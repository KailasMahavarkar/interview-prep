#!/usr/bin/env python3
"""
Script to add 'using namespace std;' and '#pragma GCC optimize("O3,unroll-loops")' 
after all headers in C++ files that don't already have them.
"""

import os
import re
import sys
from pathlib import Path
from typing import List, Tuple

def find_cpp_files(directory: str) -> List[Path]:
    """Find all C++ files in the given directory and subdirectories."""
    cpp_files = []
    for root, dirs, files in os.walk(directory):
        for file in files:
            if file.endswith(('.cpp', '.cc', '.cxx', '.c++')):
                cpp_files.append(Path(root) / file)
    return cpp_files

def has_using_namespace_std(content: str) -> bool:
    """Check if content has 'using namespace std;'."""
    return re.search(r'using\s+namespace\s+std\s*;', content) is not None

def has_pragma_optimize(content: str) -> bool:
    """Check if content has pragma GCC optimize directive."""
    return re.search(r'#pragma\s+GCC\s+optimize', content) is not None

def find_last_include_line(lines: List[str]) -> int:
    """Find the line number of the last #include statement."""
    last_include_line = -1
    for i, line in enumerate(lines):
        stripped_line = line.strip()
        if stripped_line.startswith('#include'):
            last_include_line = i
    return last_include_line

def process_file(file_path: Path, dry_run: bool = False) -> bool:
    """Process a single file to add using namespace std and pragma if needed."""
    try:
        with open(file_path, 'r', encoding='utf-8') as f:
            content = f.read()
    except UnicodeDecodeError:
        try:
            with open(file_path, 'r', encoding='latin-1') as f:
                content = f.read()
        except Exception as e:
            print(f"Error reading {file_path}: {e}")
            return False
    
    lines = content.split('\n')
    
    # Check what we need to add
    needs_namespace = not has_using_namespace_std(content)
    needs_pragma = not has_pragma_optimize(content)
    
    if not needs_namespace and not needs_pragma:
        return False  # Nothing to add
    
    # Find the last include line
    last_include_line = find_last_include_line(lines)
    
    if last_include_line == -1:
        # No includes found, add at the beginning
        insert_position = 0
    else:
        # Insert after the last include line
        insert_position = last_include_line + 1
    
    # Prepare what to insert
    to_insert = []
    if needs_namespace:
        to_insert.append("using namespace std;")
    if needs_pragma:
        to_insert.append('#pragma GCC optimize("O3,unroll-loops")')
    
    if dry_run:
        print(f"Would modify {file_path}")
        if needs_namespace:
            print(f"  - Add 'using namespace std;'")
        if needs_pragma:
            print(f"  - Add '#pragma GCC optimize(\"O3,unroll-loops\")'")
        return True
    
    # Insert the lines
    for i, line_to_insert in enumerate(to_insert):
        lines.insert(insert_position + i, line_to_insert)
    
    # Write the modified content back
    try:
        new_content = '\n'.join(lines)
        with open(file_path, 'w', encoding='utf-8') as f:
            f.write(new_content)
        
        print(f"Modified {file_path}")
        if needs_namespace:
            print(f"  - Added 'using namespace std;'")
        if needs_pragma:
            print(f"  - Added '#pragma GCC optimize(\"O3,unroll-loops\")'")
        return True
    except Exception as e:
        print(f"Error writing {file_path}: {e}")
        return False

def main():
    """Main function to process all C++ files."""
    if len(sys.argv) < 2:
        print("Usage: python add_namespace_and_pragma.py <directory> [--dry-run]")
        sys.exit(1)
    
    directory = sys.argv[1]
    dry_run = '--dry-run' in sys.argv
    
    if not os.path.isdir(directory):
        print(f"Error: {directory} is not a valid directory")
        sys.exit(1)
    
    print(f"{'[DRY RUN] ' if dry_run else ''}Adding 'using namespace std;' and pragma to C++ files in: {directory}")
    
    cpp_files = find_cpp_files(directory)
    modified_count = 0
    
    for file_path in cpp_files:
        if process_file(file_path, dry_run):
            modified_count += 1
    
    print(f"\n{'Would modify' if dry_run else 'Modified'} {modified_count} files out of {len(cpp_files)} C++ files found.")
    
    if dry_run:
        print("\nRun without --dry-run to actually modify the files.")

if __name__ == "__main__":
    main()