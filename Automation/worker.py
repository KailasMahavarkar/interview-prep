#!/usr/bin/env python3
"""
Redis File Worker - Pulls files from Redis with decompression
Polls Redis for file changes and syncs to local filesystem
"""

import os
import sys
import json
import time
import logging
import threading
from pathlib import Path
from datetime import datetime
from typing import Dict, Set, Optional, List
import redis
import zstd
from concurrent.futures import ThreadPoolExecutor
from config import DEFAULT_CONFIG


class RedisFileWorker:
    """Redis file synchronization worker"""

    def __init__(self, config: Dict):
        self.config = config
        self.redis_client = self._connect_redis()
        self.key_prefix = config['redis']['key_prefix']
        self.sync_directory = Path(config['sync']['destination_folder']).resolve()
        self.local_file_states: Dict[str, Dict] = {}
        self.running = False

        # Ensure sync directory exists
        self.sync_directory.mkdir(parents=True, exist_ok=True)

        # Load local file states
        self._load_local_states()

    def _connect_redis(self) -> redis.Redis:
        """Connect to Redis server"""
        try:
            client = redis.Redis(
                host=self.config['redis']['host'],
                port=self.config['redis']['port'],
                password=self.config['redis']['password'],
                db=self.config['redis']['db'],
                decode_responses=False  # We need bytes for compressed data
            )
            client.ping()
            logging.info(f"Connected to Redis at {self.config['redis']['host']}:{self.config['redis']['port']}")
            return client
        except Exception as e:
            logging.error(f"Failed to connect to Redis: {e}")
            sys.exit(1)

    def _load_local_states(self):
        """Load local file states from cache"""
        state_file = self.sync_directory / '.redissync_states.json'
        try:
            if state_file.exists():
                with open(state_file, 'r') as f:
                    self.local_file_states = json.load(f)
                logging.info(f"Loaded {len(self.local_file_states)} local file states")
        except Exception as e:
            logging.warning(f"Could not load local states: {e}")

    def _save_local_states(self):
        """Save local file states to cache"""
        state_file = self.sync_directory / '.redissync_states.json'
        try:
            with open(state_file, 'w') as f:
                json.dump(self.local_file_states, f, indent=2)
        except Exception as e:
            logging.error(f"Could not save local states: {e}")

    def _backup_file(self, file_path: Path) -> bool:
        """Backup existing file before overwriting"""
        if not self.config['worker']['backup_changed_files']:
            return True

        if not file_path.exists():
            return True

        try:
            backup_dir = Path(self.config['worker']['backup_directory'])
            backup_dir.mkdir(parents=True, exist_ok=True)

            # Create timestamped backup
            timestamp = datetime.now().strftime('%Y%m%d_%H%M%S')
            backup_name = f"{file_path.name}.{timestamp}.bak"
            backup_path = backup_dir / backup_name

            # Copy file to backup
            import shutil
            shutil.copy2(file_path, backup_path)

            logging.debug(f"Backed up {file_path} to {backup_path}")
            return True

        except Exception as e:
            logging.error(f"Failed to backup {file_path}: {e}")
            return False

    def _get_redis_file_list(self) -> List[str]:
        """Get list of all files stored in Redis"""
        try:
            pattern = f"{self.key_prefix}:meta:*"
            keys = self.redis_client.keys(pattern)

            file_keys = []
            for key in keys:
                # Extract file path from meta key
                key_str = key.decode('utf-8') if isinstance(key, bytes) else key
                file_path = key_str.replace(f"{self.key_prefix}:meta:", "")
                file_keys.append(file_path)

            return file_keys

        except Exception as e:
            logging.error(f"Error getting file list from Redis: {e}")
            return []

    def _get_file_metadata(self, file_key: str) -> Optional[Dict]:
        """Get file metadata from Redis"""
        try:
            meta_key = f"{self.key_prefix}:meta:{file_key}"
            meta_data = self.redis_client.get(meta_key)

            if meta_data:
                return json.loads(meta_data.decode('utf-8'))
            return None

        except Exception as e:
            logging.error(f"Error getting metadata for {file_key}: {e}")
            return None

    def _download_file(self, file_key: str, metadata: Dict) -> bool:
        """Download and decompress file from Redis"""
        try:
            # Get compressed data
            data_key = f"{self.key_prefix}:file:{file_key}"
            compressed_data = self.redis_client.get(data_key)

            if not compressed_data:
                logging.error(f"No data found for {file_key}")
                return False

            # Decompress content
            original_content = zstd.decompress(compressed_data)

            # Verify size matches metadata
            if len(original_content) != metadata['original_size']:
                logging.error(f"Size mismatch for {file_key}: expected {metadata['original_size']}, got {len(original_content)}")
                return False

            # Determine local file path
            local_file_path = self.sync_directory / file_key

            # Create directories if needed
            if self.config['worker']['create_directories']:
                local_file_path.parent.mkdir(parents=True, exist_ok=True)

            # Backup existing file if it exists and has changed
            if local_file_path.exists():
                self._backup_file(local_file_path)

            # Write file content
            with open(local_file_path, 'wb') as f:
                f.write(original_content)

            # Set file permissions
            os.chmod(local_file_path, self.config['worker']['file_permissions'])

            # Update local state
            self.local_file_states[file_key] = {
                'hash': metadata['hash'],
                'size': metadata['original_size'],
                'last_sync': datetime.now().isoformat(),
                'local_path': str(local_file_path)
            }

            logging.info(f"Downloaded {file_key} ({metadata['original_size']} bytes, "
                         f"compression ratio: {metadata.get('compression_ratio', 1):.2f}x)")

            return True

        except Exception as e:
            logging.error(f"Error downloading {file_key}: {e}")
            return False

    def _remove_local_file(self, file_key: str):
        """Remove local file that no longer exists in Redis"""
        try:
            if file_key in self.local_file_states:
                local_path = Path(self.local_file_states[file_key]['local_path'])

                if local_path.exists():
                    # Backup before removing
                    self._backup_file(local_path)
                    local_path.unlink()
                    logging.info(f"Removed local file: {local_path}")

                # Remove from state
                del self.local_file_states[file_key]

        except Exception as e:
            logging.error(f"Error removing local file {file_key}: {e}")

    def _sync_single_file(self, file_key: str) -> bool:
        """Sync a single file from Redis"""
        try:
            # Get file metadata
            metadata = self._get_file_metadata(file_key)
            if not metadata:
                logging.warning(f"No metadata found for {file_key}")
                return False

            # Check if file needs to be updated
            if file_key in self.local_file_states:
                local_state = self.local_file_states[file_key]
                if local_state.get('hash') == metadata.get('hash'):
                    logging.debug(f"File {file_key} is up to date")
                    return True

            # Download the file
            return self._download_file(file_key, metadata)

        except Exception as e:
            logging.error(f"Error syncing file {file_key}: {e}")
            return False

    def sync_all_files(self) -> Dict[str, int]:
        """Sync all files from Redis"""
        logging.info("Starting file synchronization from Redis...")

        # Get list of files in Redis
        redis_files = set(self._get_redis_file_list())
        local_files = set(self.local_file_states.keys())

        stats = {
            'downloaded': 0,
            'updated': 0,
            'removed': 0,
            'errors': 0
        }

        # Files to download/update
        files_to_sync = redis_files

        # Use thread pool for parallel downloads
        max_workers = self.config['worker']['max_workers']
        with ThreadPoolExecutor(max_workers=max_workers) as executor:
            # Submit sync tasks
            future_to_file = {
                executor.submit(self._sync_single_file, file_key): file_key
                for file_key in files_to_sync
            }

            # Process results
            for future in future_to_file:
                file_key = future_to_file[future]
                try:
                    success = future.result()
                    if success:
                        if file_key in local_files:
                            stats['updated'] += 1
                        else:
                            stats['downloaded'] += 1
                    else:
                        stats['errors'] += 1
                except Exception as e:
                    logging.error(f"Error processing {file_key}: {e}")
                    stats['errors'] += 1

        # Remove local files that no longer exist in Redis
        files_to_remove = local_files - redis_files
        for file_key in files_to_remove:
            self._remove_local_file(file_key)
            stats['removed'] += 1

        # Save updated states
        self._save_local_states()

        logging.info(f"Sync completed: {stats['downloaded']} downloaded, "
                     f"{stats['updated']} updated, {stats['removed']} removed, "
                     f"{stats['errors']} errors")

        return stats

    def listen_for_notifications(self):
        """Listen for real-time notifications via Redis pub/sub"""
        if not self.config['notifications']['enabled']:
            return

        def notification_listener():
            try:
                pubsub = self.redis_client.pubsub()
                channel = f"{self.key_prefix}:notifications"
                pubsub.subscribe(channel)

                logging.info(f"Listening for notifications on {channel}")

                for message in pubsub.listen():
                    if not self.running:
                        break

                    if message['type'] == 'message':
                        try:
                            notification = json.loads(message['data'].decode('utf-8'))
                            self._handle_notification(notification)
                        except Exception as e:
                            logging.error(f"Error processing notification: {e}")

                pubsub.unsubscribe(channel)
                pubsub.close()

            except Exception as e:
                logging.error(f"Error in notification listener: {e}")

        # Start notification listener in background thread
        listener_thread = threading.Thread(target=notification_listener, daemon=True)
        listener_thread.start()

    def _handle_notification(self, notification: Dict):
        """Handle real-time file change notification"""
        try:
            action = notification.get('action')
            file_path = notification.get('file_path')

            if action == 'file_updated':
                logging.info(f"Received update notification for {file_path}")
                self._sync_single_file(file_path)
                self._save_local_states()

            elif action == 'file_removed':
                logging.info(f"Received removal notification for {file_path}")
                self._remove_local_file(file_path)
                self._save_local_states()

        except Exception as e:
            logging.error(f"Error handling notification: {e}")

    def get_sync_status(self) -> Dict:
        """Get current sync status"""
        redis_files = self._get_redis_file_list()
        local_files = list(self.local_file_states.keys())

        status = {
            'redis_files': len(redis_files),
            'local_files': len(local_files),
            'sync_directory': str(self.sync_directory),
            'last_sync': None,
            'files_behind': 0
        }

        # Calculate files behind (simple check)
        redis_file_set = set(redis_files)
        local_file_set = set(local_files)
        status['files_behind'] = len(redis_file_set - local_file_set)

        # Get last sync time
        if self.local_file_states:
            last_sync_times = [
                state.get('last_sync') for state in self.local_file_states.values()
                if state.get('last_sync')
            ]
            if last_sync_times:
                status['last_sync'] = max(last_sync_times)

        return status

    def start_worker(self):
        """Start the worker in daemon mode"""
        self.running = True

        # Start notification listener
        self.listen_for_notifications()

        # Perform initial sync
        self.sync_all_files()

        # Start polling loop
        poll_interval = self.config['worker']['poll_interval_seconds']
        logging.info(f"Starting worker loop (poll interval: {poll_interval}s)")

        try:
            while self.running:
                time.sleep(poll_interval)

                if self.running:  # Check again in case we were stopped during sleep
                    self.sync_all_files()

        except KeyboardInterrupt:
            logging.info("Worker interrupted by user")
        except Exception as e:
            logging.error(f"Error in worker loop: {e}")
        finally:
            self.running = False

    def stop_worker(self):
        """Stop the worker"""
        self.running = False
        logging.info("Worker stopped")


def load_config(config_path: str = '.redissync/config.json') -> Dict:
    """Load configuration from file"""
    config = DEFAULT_CONFIG.copy()

    if os.path.exists(config_path):
        try:
            with open(config_path, 'r') as f:
                user_config = json.load(f)
                # Deep merge
                for section, values in user_config.items():
                    if section in config and isinstance(config[section], dict):
                        config[section].update(values)
                    else:
                        config[section] = values
            logging.info(f"Loaded config from {config_path}")
        except Exception as e:
            logging.warning(f"Error loading config: {e}")

    return config


def setup_logging(config: Dict):
    """Setup logging configuration"""
    log_config = config['logging']

    logging.basicConfig(
        level=getattr(logging, log_config['level']),
        format=log_config['format'],
        handlers=[
            logging.FileHandler(log_config['file']),
            logging.StreamHandler()
        ]
    )


def main():
    """Main entry point"""
    import argparse

    parser = argparse.ArgumentParser(description='Redis File Sync Worker')
    parser.add_argument('--config', '-c', default='.redissync/config.json',
                        help='Configuration file path')
    parser.add_argument('--sync-once', action='store_true',
                        help='Sync once and exit (no daemon mode)')
    parser.add_argument('--status', action='store_true',
                        help='Show sync status and exit')

    args = parser.parse_args()

    # Load configuration
    config = load_config(args.config)
    setup_logging(config)

    logging.info("Starting Redis File Sync Worker")

    # Create sync directory if it doesn't exist
    os.makedirs('.redissync', exist_ok=True)

    # Initialize worker
    worker = RedisFileWorker(config)

    if args.status:
        # Show status and exit
        status = worker.get_sync_status()
        print("\n=== Redis File Sync Status ===")
        print(f"Redis files: {status['redis_files']}")
        print(f"Local files: {status['local_files']}")
        print(f"Files behind: {status['files_behind']}")
        print(f"Sync directory: {status['sync_directory']}")
        print(f"Last sync: {status['last_sync'] or 'Never'}")
        return

    if args.sync_once:
        # Sync once and exit
        stats = worker.sync_all_files()
        print(f"Sync completed: {stats}")
        return

    # Start worker daemon
    try:
        worker.start_worker()
    except KeyboardInterrupt:
        logging.info("Stopping worker...")
        worker.stop_worker()


if __name__ == "__main__":
    main()
