import os
from dotenv import load_dotenv

# Load environment variables
load_dotenv()

# Configuration
DEFAULT_CONFIG = {
    'redis': {
        'host': os.getenv('REDIS_HOST', 'localhost'),
        'port': int(os.getenv('REDIS_PORT', '6379')),
        'password': os.getenv('REDIS_PASSWORD'),
        'db': int(os.getenv('REDIS_DB', '0')),
        'key_prefix': os.getenv('REDIS_KEY_PREFIX', 'filesync')
    },
    'sync': {
        'source_folder': os.getenv('SYNC_SOURCE_FOLDER', '.'),  # Folder to watch/upload
        'destination_folder': os.getenv('SYNC_DESTINATION_FOLDER', './synced_files'),  # Folder to download to
        'file_extensions': ['.cpp', '.h', '.c', '.hpp', '.cc', '.cxx', '.py', '.txt', '.md', '.json', '.sh', '.bat', '.yml', '.yaml', '.gitignore'],
        'max_file_size_mb': 10,
    },
    'watcher': {
        'debounce_seconds': 2.0,
        'compression_level': 3
    },
    'worker': {
        'poll_interval_seconds': 30,
        'max_workers': 4,
        'file_permissions': 0o644,
        'create_directories': True,
        'backup_changed_files': True,
        'backup_directory': '.redissync/backups'
    },
    'notifications': {
        'enabled': True,
        'subscribe_timeout': 5
    },
    'logging': {
        'level': 'INFO',
        'file': 'redis_sync.log',
        'format': '%(asctime)s - %(levelname)s - %(message)s'
    }
}