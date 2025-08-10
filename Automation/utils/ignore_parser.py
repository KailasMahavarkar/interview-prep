from pathlib import Path
import logging
import pathspec

class RedisIgnoreParser:
    """Parser for .redisignore files (gitignore syntax)"""

    def __init__(self, base_path: Path):
        self.base_path = Path(base_path)
        self.spec = None
        self.load_ignore_patterns()

    def load_ignore_patterns(self):
        """Load ignore patterns from .redisignore files"""
        patterns = []

        # Default patterns
        default_patterns = [
            '.git/',
            '.redissync/',
            '*.tmp',
            '*.log',
            '*.swp',
            '.DS_Store',
            '__pycache__/',
            '*.pyc',
            '.redisignore'
        ]
        patterns.extend(default_patterns)

        # Load .redisignore files
        ignore_files = list(self.base_path.rglob('.redisignore'))

        for ignore_file in ignore_files:
            try:
                with open(ignore_file, 'r', encoding='utf-8') as f:
                    for line in f:
                        line = line.strip()
                        if line and not line.startswith('#'):
                            patterns.append(line)
            except Exception as e:
                logging.warning(f"Error reading {ignore_file}: {e}")

        self.spec = pathspec.PathSpec.from_lines('gitwildmatch', patterns)
        logging.info(f"Loaded {len(patterns)} ignore patterns")

    def should_ignore(self, file_path: Path) -> bool:
        """Check if file should be ignored"""
        try:
            relative_path = file_path.relative_to(self.base_path)
            return self.spec.match_file(str(relative_path))
        except ValueError:
            return True  # Outside base path
