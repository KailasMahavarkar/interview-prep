#!/usr/bin/env python3
"""
Redis File Watcher - Pushes files to Redis with compression and rolling hash
Monitors filesystem changes and syncs to Redis with deduplication
"""

import os
import sys
import json
import time
import logging
import threading
from pathlib import Path
from datetime import datetime
from typing import Dict
import redis
import zstd
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler
from utils.rolling_hash import RollingHash
from utils.ignore_parser import RedisIgnoreParser
from config import DEFAULT_CONFIG

class RedisFileSync:
    """Redis file synchronization manager"""
    
    def __init__(self, config: Dict, source_folder: Path):
        self.config = config
        self.source_folder = source_folder.resolve()
        self.redis_client = self._connect_redis()
        self.compression_level = config['watcher']['compression_level']
        self.rolling_hash = RollingHash()
        self.file_hashes: Dict[str, str] = {}
        self.key_prefix = config['redis']['key_prefix']
        self._load_file_hashes()
    
    def _connect_redis(self) -> redis.Redis:
        """Connect to Redis server"""
        try:
            client = redis.Redis(
                host=self.config['redis']['host'],
                port=self.config['redis']['port'],
                password=self.config['redis']['password'],
                db=self.config['redis']['db'],
                decode_responses=False
            )
            client.ping()
            logging.info(f"Connected to Redis at {self.config['redis']['host']}:{self.config['redis']['port']}")
            return client
        except Exception as e:
            logging.error(f"Failed to connect to Redis: {e}")
            sys.exit(1)
    
    def _load_file_hashes(self):
        """Load existing file hashes from Redis"""
        try:
            hash_key = f"{self.key_prefix}:hashes"
            hash_data = self.redis_client.get(hash_key)
            if hash_data:
                self.file_hashes = json.loads(hash_data.decode('utf-8'))
                logging.info(f"Loaded {len(self.file_hashes)} existing file hashes")
        except Exception as e:
            logging.warning(f"Could not load existing hashes: {e}")
    
    def _save_file_hashes(self):
        """Save file hashes to Redis"""
        try:
            hash_key = f"{self.key_prefix}:hashes"
            hash_data = json.dumps(self.file_hashes)
            self.redis_client.set(hash_key, hash_data)
        except Exception as e:
            logging.error(f"Could not save file hashes: {e}")
    
    def push_file(self, file_path: Path) -> bool:
        """Push file to Redis with compression and hash checking"""
        try:
            # Read file content
            with open(file_path, 'rb') as f:
                content = f.read()
            
            # Check file size
            max_size = self.config['sync']['max_file_size_mb'] * 1024 * 1024
            if len(content) > max_size:
                logging.warning(f"File {file_path} too large ({len(content)} bytes), skipping")
                return False
            
            # Compute rolling hash
            current_hash = self.rolling_hash.compute_hash(content)
            # Use relative path from source folder as key
            file_key = str(file_path.relative_to(self.source_folder))
            
            # Check if file changed
            if file_key in self.file_hashes and self.file_hashes[file_key] == current_hash:
                logging.debug(f"File {file_path} unchanged (hash: {current_hash})")
                return True
            
            # Compress content
            compressed_content = zstd.compress(content, self.compression_level)
            compression_ratio = len(content) / len(compressed_content) if len(compressed_content) > 0 else 1
            
            # Prepare file metadata
            metadata = {
                'original_size': len(content),
                'compressed_size': len(compressed_content),
                'compression_ratio': compression_ratio,
                'hash': current_hash,
                'timestamp': datetime.now().isoformat(),
                'file_path': str(file_path)
            }
            
            # Store in Redis
            data_key = f"{self.key_prefix}:file:{file_key}"
            meta_key = f"{self.key_prefix}:meta:{file_key}"
            
            pipe = self.redis_client.pipeline()
            pipe.set(data_key, compressed_content)
            pipe.set(meta_key, json.dumps(metadata))
            pipe.execute()
            
            # Update local hash cache
            self.file_hashes[file_key] = current_hash
            self._save_file_hashes()
            
            # Notify about file change
            notification = {
                'action': 'file_updated',
                'file_path': str(file_path),
                'hash': current_hash,
                'timestamp': datetime.now().isoformat(),
                'size': len(content),
                'compressed_size': len(compressed_content)
            }
            
            self.redis_client.publish(f"{self.key_prefix}:notifications", json.dumps(notification))
            
            logging.info(f"Pushed {file_path} (hash: {current_hash}, ratio: {compression_ratio:.2f}x)")
            return True
            
        except Exception as e:
            logging.error(f"Error pushing file {file_path}: {e}")
            return False
    
    def remove_file(self, file_path: Path):
        """Remove file from Redis"""
        try:
            # Use relative path from source folder as key
            file_key = str(file_path.relative_to(self.source_folder))
            data_key = f"{self.key_prefix}:file:{file_key}"
            meta_key = f"{self.key_prefix}:meta:{file_key}"
            
            pipe = self.redis_client.pipeline()
            pipe.delete(data_key)
            pipe.delete(meta_key)
            pipe.execute()
            
            # Remove from hash cache
            if file_key in self.file_hashes:
                del self.file_hashes[file_key]
                self._save_file_hashes()
            
            # Notify about file removal
            notification = {
                'action': 'file_removed',
                'file_path': str(file_path),
                'timestamp': datetime.now().isoformat()
            }
            
            self.redis_client.publish(f"{self.key_prefix}:notifications", json.dumps(notification))
            
            logging.info(f"Removed {file_path} from Redis")
            
        except Exception as e:
            logging.error(f"Error removing file {file_path}: {e}")

class FileWatchHandler(FileSystemEventHandler):
    """File system event handler with debouncing"""
    
    def __init__(self, redis_sync: RedisFileSync, ignore_parser: RedisIgnoreParser, config: Dict):
        self.redis_sync = redis_sync
        self.ignore_parser = ignore_parser
        self.config = config
        self.pending_files: Dict[str, float] = {}
        self.debounce_timer = None
        self.lock = threading.Lock()
        
        # Start debounce timer
        self._start_debounce_timer()
    
    def _start_debounce_timer(self):
        """Start the debounce timer"""
        def process_pending():
            while True:
                time.sleep(self.config['watcher']['debounce_seconds'])
                self._process_pending_files()
        
        timer_thread = threading.Thread(target=process_pending, daemon=True)
        timer_thread.start()
    
    def _process_pending_files(self):
        """Process files that have been pending for debounce period"""
        with self.lock:
            current_time = time.time()
            debounce_time = self.config['watcher']['debounce_seconds']
            
            ready_files = []
            for file_path, timestamp in list(self.pending_files.items()):
                if current_time - timestamp >= debounce_time:
                    ready_files.append(file_path)
                    del self.pending_files[file_path]
            
            for file_path in ready_files:
                self._sync_file(Path(file_path))
    
    def _should_process_file(self, file_path: Path) -> bool:
        """Check if file should be processed"""
        if not file_path.is_file():
            return False
        
        return self._should_process_path(file_path)
    
    def _should_process_path(self, file_path: Path) -> bool:
        """Check if path should be processed (without checking if file exists)"""
        # Check file extension
        extensions = self.config['sync']['file_extensions']
        if extensions:
            # Check both suffix (normal extensions) and name (special files like .gitignore)
            if file_path.suffix not in extensions and file_path.name not in extensions:
                return False
        
        # Check ignore patterns
        if self.ignore_parser.should_ignore(file_path):
            return False
        
        return True
    
    def _sync_file(self, file_path: Path):
        """Sync single file to Redis"""
        if self._should_process_file(file_path):
            self.redis_sync.push_file(file_path)
    
    def _queue_file(self, file_path: str):
        """Queue file for processing with debouncing"""
        with self.lock:
            self.pending_files[file_path] = time.time()
    
    def on_modified(self, event):
        if not event.is_directory:
            logging.debug(f"File modified: {event.src_path}")
            self._queue_file(event.src_path)
    
    def on_created(self, event):
        if not event.is_directory:
            logging.debug(f"File created: {event.src_path}")
            self._queue_file(event.src_path)
    
    def on_deleted(self, event):
        if not event.is_directory:
            file_path = Path(event.src_path)
            if self._should_process_path(file_path):  # Use _should_process_path for deleted files
                self.redis_sync.remove_file(file_path)
                logging.info(f"File deleted: {file_path}")
    
    def on_moved(self, event):
        if not event.is_directory:
            # Handle as delete + create
            old_path = Path(event.src_path)
            new_path = Path(event.dest_path)
            
            if self._should_process_path(old_path):  # Use _should_process_path for old path
                self.redis_sync.remove_file(old_path)
                logging.info(f"File moved from: {old_path}")
            
            if self._should_process_file(new_path):  # New path should exist, so use normal check
                self._queue_file(event.dest_path)
                logging.info(f"File moved to: {new_path}")

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

def initial_sync(redis_sync: RedisFileSync, ignore_parser: RedisIgnoreParser, config: Dict):
    """Perform initial sync of all files"""
    logging.info("Starting initial file sync...")
    
    file_count = 0
    source_folder = Path(config['sync']['source_folder']).resolve()
    
    if not source_folder.exists():
        logging.warning(f"Source folder does not exist: {source_folder}")
        return
    
    for watch_path in [source_folder]:
        watch_path = Path(watch_path)
        if not watch_path.exists():
            logging.warning(f"Watch path does not exist: {watch_path}")
            continue
        
        for file_path in watch_path.rglob('*'):
            if file_path.is_file():
                # Check file extension
                extensions = config['sync']['file_extensions']
                if extensions and file_path.suffix not in extensions:
                    logging.debug(f"Skipping {file_path} - extension {file_path.suffix} not in {extensions}")
                    continue
                
                # Check ignore patterns
                if ignore_parser.should_ignore(file_path):
                    logging.debug(f"Skipping {file_path} - ignored by patterns")
                    continue
                
                logging.info(f"Processing file: {file_path}")
                if redis_sync.push_file(file_path):
                    file_count += 1
    
    logging.info(f"Initial sync complete: {file_count} files processed")

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

def main():
    """Main entry point"""
    # Load configuration
    config = load_config()
    setup_logging(config)
    
    logging.info("Starting Redis File Watcher")
    
    # Create sync directory if it doesn't exist
    os.makedirs('.redissync', exist_ok=True)
    
    # Initialize components
    source_folder = Path(config['sync']['source_folder']).resolve()
    ignore_parser = RedisIgnoreParser(source_folder)
    redis_sync = RedisFileSync(config, source_folder)
    
    # Perform initial sync
    initial_sync(redis_sync, ignore_parser, config)
    
    # Setup file watcher
    event_handler = FileWatchHandler(redis_sync, ignore_parser, config)
    observer = Observer()
    
    # Add watcher for source folder
    if source_folder.exists():
        observer.schedule(event_handler, str(source_folder), recursive=True)
        logging.info(f"Watching source folder: {source_folder}")
    else:
        logging.warning(f"Source folder does not exist: {source_folder}")
        sys.exit(1)
    
    # Start watching
    observer.start()
    logging.info("File watcher started. Press Ctrl+C to stop.")
    
    try:
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        logging.info("Stopping file watcher...")
        observer.stop()
    
    observer.join()
    logging.info("File watcher stopped")

if __name__ == "__main__":
    main()