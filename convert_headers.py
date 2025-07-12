#!/usr/bin/env python3
"""
Script to convert C++ files from using <bits/stdc++.h> to specific standard library headers.
Analyzes each file to determine which headers are actually needed.
"""

import os
import re
import sys
from pathlib import Path
from typing import Set, List, Dict

# Header mapping for common C++ standard library functions and types
HEADER_MAPPINGS = {
    # Default headers to always include
    'default': ['iostream', 'vector', 'algorithm', 'climits'],
    
    # Container headers
    'vector': 'vector',
    'deque': 'deque',
    'list': 'list',
    'forward_list': 'forward_list',
    'array': 'array',
    'stack': 'stack',
    'queue': 'queue',
    'priority_queue': 'queue',
    'set': 'set',
    'multiset': 'set',
    'unordered_set': 'unordered_set',
    'unordered_multiset': 'unordered_set',
    'map': 'map',
    'multimap': 'map',
    'unordered_map': 'unordered_map',
    'unordered_multimap': 'unordered_map',
    'pair': 'utility',
    'make_pair': 'utility',
    'tuple': 'tuple',
    'make_tuple': 'tuple',
    'tie': 'tuple',
    
    # Algorithm headers
    'sort': 'algorithm',
    'reverse': 'algorithm',
    'unique': 'algorithm',
    'lower_bound': 'algorithm',
    'upper_bound': 'algorithm',
    'binary_search': 'algorithm',
    'find': 'algorithm',
    'count': 'algorithm',
    'accumulate': 'numeric',
    'max_element': 'algorithm',
    'min_element': 'algorithm',
    'next_permutation': 'algorithm',
    'prev_permutation': 'algorithm',
    'fill': 'algorithm',
    'copy': 'algorithm',
    'swap': 'algorithm',
    'merge': 'algorithm',
    'partition': 'algorithm',
    'stable_sort': 'algorithm',
    'partial_sort': 'algorithm',
    'nth_element': 'algorithm',
    'make_heap': 'algorithm',
    'push_heap': 'algorithm',
    'pop_heap': 'algorithm',
    'sort_heap': 'algorithm',
    'is_heap': 'algorithm',
    'remove': 'algorithm',
    'remove_if': 'algorithm',
    'replace': 'algorithm',
    'replace_if': 'algorithm',
    'transform': 'algorithm',
    'for_each': 'algorithm',
    'all_of': 'algorithm',
    'any_of': 'algorithm',
    'none_of': 'algorithm',
    
    # String operations
    'string': 'string',
    'to_string': 'string',
    'stoi': 'string',
    'stol': 'string',
    'stoll': 'string',
    'stof': 'string',
    'stod': 'string',
    'stold': 'string',
    'getline': 'string',
    'substr': 'string',
    
    # I/O operations
    'cout': 'iostream',
    'cin': 'iostream',
    'cerr': 'iostream',
    'clog': 'iostream',
    'endl': 'iostream',
    'flush': 'iostream',
    'istream': 'iostream',
    'ostream': 'iostream',
    'iostream': 'iostream',
    'stringstream': 'sstream',
    'istringstream': 'sstream',
    'ostringstream': 'sstream',
    'ifstream': 'fstream',
    'ofstream': 'fstream',
    'fstream': 'fstream',
    
    # Math functions
    'max': 'algorithm',
    'min': 'algorithm',
    'abs': 'cstdlib',
    'sqrt': 'cmath',
    'pow': 'cmath',
    'log': 'cmath',
    'log10': 'cmath',
    'sin': 'cmath',
    'cos': 'cmath',
    'tan': 'cmath',
    'floor': 'cmath',
    'ceil': 'cmath',
    'round': 'cmath',
    'gcd': 'numeric',
    'lcm': 'numeric',
    
    # Limits and constants
    'INT_MAX': 'climits',
    'INT_MIN': 'climits',
    'LONG_MAX': 'climits',
    'LONG_MIN': 'climits',
    'LLONG_MAX': 'climits',
    'LLONG_MIN': 'climits',
    'CHAR_MAX': 'climits',
    'CHAR_MIN': 'climits',
    'UINT_MAX': 'climits',
    'numeric_limits': 'limits',
    
    # Memory management
    'unique_ptr': 'memory',
    'shared_ptr': 'memory',
    'weak_ptr': 'memory',
    'make_unique': 'memory',
    'make_shared': 'memory',
    
    # Functional programming
    'function': 'functional',
    'bind': 'functional',
    'lambda': 'functional',
    'hash': 'functional',
    
    # Iterator support
    'iterator': 'iterator',
    'reverse_iterator': 'iterator',
    'advance': 'iterator',
    'distance': 'iterator',
    'next': 'iterator',
    'prev': 'iterator',
    'begin': 'iterator',
    'end': 'iterator',
    'rbegin': 'iterator',
    'rend': 'iterator',
    
    # Random number generation
    'random_device': 'random',
    'mt19937': 'random',
    'uniform_int_distribution': 'random',
    'uniform_real_distribution': 'random',
    'normal_distribution': 'random',
    
    # Time and chrono
    'chrono': 'chrono',
    'steady_clock': 'chrono',
    'high_resolution_clock': 'chrono',
    'duration': 'chrono',
    'time_point': 'chrono',
    
    # Utility
    'move': 'utility',
    'forward': 'utility',
    'swap': 'utility',
    'exchange': 'utility',
    
    # Type traits
    'enable_if': 'type_traits',
    'is_same': 'type_traits',
    'is_integral': 'type_traits',
    'is_floating_point': 'type_traits',
    
    # C standard library wrappers
    'malloc': 'cstdlib',
    'free': 'cstdlib',
    'exit': 'cstdlib',
    'atoi': 'cstdlib',
    'atol': 'cstdlib',
    'atoll': 'cstdlib',
    'rand': 'cstdlib',
    'srand': 'cstdlib',
    'printf': 'cstdio',
    'scanf': 'cstdio',
    'sprintf': 'cstdio',
    'sscanf': 'cstdio',
    'memcpy': 'cstring',
    'memset': 'cstring',
    'strlen': 'cstring',
    'strcmp': 'cstring',
    'strcpy': 'cstring',
    'strcat': 'cstring',
    'memcmp': 'cstring',
    'isalpha': 'cctype',
    'isdigit': 'cctype',
    'isalnum': 'cctype',
    'isspace': 'cctype',
    'tolower': 'cctype',
    'toupper': 'cctype',
}

def find_cpp_files(directory: str) -> List[Path]:
    """Find all C++ files in the given directory and subdirectories."""
    cpp_files = []
    for root, dirs, files in os.walk(directory):
        for file in files:
            if file.endswith(('.cpp', '.cc', '.cxx', '.c++')):
                cpp_files.append(Path(root) / file)
    return cpp_files

def analyze_file_content(file_path: Path) -> Set[str]:
    """Analyze a C++ file and determine which headers are needed."""
    try:
        with open(file_path, 'r', encoding='utf-8') as f:
            content = f.read()
    except UnicodeDecodeError:
        try:
            with open(file_path, 'r', encoding='latin-1') as f:
                content = f.read()
        except Exception as e:
            print(f"Error reading {file_path}: {e}")
            return set()
    
    required_headers = set(HEADER_MAPPINGS['default'])
    
    # Remove comments to avoid false positives
    content = re.sub(r'//.*$', '', content, flags=re.MULTILINE)
    content = re.sub(r'/\*.*?\*/', '', content, flags=re.DOTALL)
    
    # Look for patterns that indicate specific header usage
    for pattern, header in HEADER_MAPPINGS.items():
        if pattern == 'default':
            continue
            
        # Check for function calls: pattern(
        if re.search(rf'\b{re.escape(pattern)}\s*\(', content):
            required_headers.add(header)
            continue
            
        # Check for type declarations: pattern<
        if re.search(rf'\b{re.escape(pattern)}\s*<', content):
            required_headers.add(header)
            continue
            
        # Check for simple usage: pattern (word boundary)
        if re.search(rf'\b{re.escape(pattern)}\b', content):
            required_headers.add(header)
    
    return required_headers

def has_bits_stdc_header(file_path: Path) -> bool:
    """Check if file uses bits/stdc++.h header."""
    try:
        with open(file_path, 'r', encoding='utf-8') as f:
            content = f.read()
    except UnicodeDecodeError:
        try:
            with open(file_path, 'r', encoding='latin-1') as f:
                content = f.read()
        except Exception as e:
            return False
    
    return re.search(r'#include\s*<\s*bits/stdc\+\+\.h\s*>', content) is not None

def convert_file(file_path: Path, dry_run: bool = False) -> bool:
    """Convert a single file from bits/stdc++.h to specific headers."""
    if not has_bits_stdc_header(file_path):
        return False
    
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
    
    # Analyze content to determine required headers
    required_headers = analyze_file_content(file_path)
    
    # Remove bits/stdc++.h include
    content = re.sub(r'#include\s*<\s*bits/stdc\+\+\.h\s*>\s*\n?', '', content)
    
    # Generate new header includes
    header_includes = []
    for header in sorted(required_headers):
        header_includes.append(f'#include <{header}>')
    
    # Find the position to insert headers (after existing includes or at the beginning)
    lines = content.split('\n')
    insert_pos = 0
    
    # Find the last #include line
    for i, line in enumerate(lines):
        if line.strip().startswith('#include'):
            insert_pos = i + 1
    
    # Insert new headers
    for i, header_include in enumerate(header_includes):
        lines.insert(insert_pos + i, header_include)
    
    new_content = '\n'.join(lines)
    
    if dry_run:
        print(f"Would convert {file_path}")
        print(f"  Required headers: {', '.join(sorted(required_headers))}")
        return True
    
    # Write the modified content back
    try:
        with open(file_path, 'w', encoding='utf-8') as f:
            f.write(new_content)
        print(f"Converted {file_path}")
        print(f"  Added headers: {', '.join(sorted(required_headers))}")
        return True
    except Exception as e:
        print(f"Error writing {file_path}: {e}")
        return False

def main():
    """Main function to process all C++ files."""
    if len(sys.argv) < 2:
        print("Usage: python convert_headers.py <directory> [--dry-run]")
        sys.exit(1)
    
    directory = sys.argv[1]
    dry_run = '--dry-run' in sys.argv
    
    if not os.path.isdir(directory):
        print(f"Error: {directory} is not a valid directory")
        sys.exit(1)
    
    print(f"{'[DRY RUN] ' if dry_run else ''}Converting C++ files in: {directory}")
    print(f"Looking for files with #include <bits/stdc++.h>...")
    
    cpp_files = find_cpp_files(directory)
    converted_count = 0
    
    for file_path in cpp_files:
        if convert_file(file_path, dry_run):
            converted_count += 1
    
    print(f"\n{'Would convert' if dry_run else 'Converted'} {converted_count} files out of {len(cpp_files)} C++ files found.")
    
    if dry_run:
        print("\nRun without --dry-run to actually modify the files.")

if __name__ == "__main__":
    main()