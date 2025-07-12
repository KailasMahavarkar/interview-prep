#!/bin/bash

# Header Conversion Script for C++ files
# Converts files from using <bits/stdc++.h> to specific standard library headers

show_usage() {
    echo "Header Conversion Script for C++ Files"
    echo "======================================"
    echo ""
    echo "This script converts C++ files from using <bits/stdc++.h> to specific headers"
    echo "based on actual usage analysis of your code."
    echo ""
    echo "Usage:"
    echo "  $0 [OPTIONS] <directory>"
    echo ""
    echo "Options:"
    echo "  --dry-run    Preview changes without modifying files"
    echo "  --help, -h   Show this help message"
    echo ""
    echo "Examples:"
    echo "  $0 --dry-run .                    # Preview changes for entire project"
    echo "  $0 \"Graph Concept\"               # Convert files in Graph Concept directory"
    echo "  $0 --dry-run \"Codeforces/800\"     # Preview changes for specific directory"
    echo ""
    echo "The script will:"
    echo "  • Find all .cpp files using <bits/stdc++.h>"
    echo "  • Analyze code to determine required headers"
    echo "  • Always include: iostream, vector, algorithm, climits"
    echo "  • Add specific headers based on detected usage"
    echo "  • Remove <bits/stdc++.h> completely"
}

# Make the Python script executable
chmod +x convert_headers.py

# Parse command line arguments
DRY_RUN=""
DIRECTORY=""

while [[ $# -gt 0 ]]; do
    case $1 in
        --dry-run)
            DRY_RUN="--dry-run"
            shift
            ;;
        --help|-h)
            show_usage
            exit 0
            ;;
        -*)
            echo "Unknown option: $1"
            show_usage
            exit 1
            ;;
        *)
            if [ -z "$DIRECTORY" ]; then
                DIRECTORY="$1"
            else
                echo "Error: Multiple directories specified"
                show_usage
                exit 1
            fi
            shift
            ;;
    esac
done

# Check if directory is provided
if [ -z "$DIRECTORY" ]; then
    echo "Error: Directory path required"
    echo ""
    show_usage
    exit 1
fi

# Check if directory exists
if [ ! -d "$DIRECTORY" ]; then
    echo "Error: Directory '$DIRECTORY' does not exist"
    exit 1
fi

# Check if Python script exists
if [ ! -f "convert_headers.py" ]; then
    echo "Error: convert_headers.py not found in current directory"
    echo "Make sure you're running this script from the directory containing convert_headers.py"
    exit 1
fi

# Confirm if not dry run
if [ -z "$DRY_RUN" ]; then
    echo "This will modify C++ files in: $DIRECTORY"
    read -p "Continue? (y/N): " confirm
    if [[ ! $confirm =~ ^[yY]([eE][sS])?$ ]]; then
        echo "Conversion cancelled."
        exit 0
    fi
fi

# Run the conversion
echo "Running header conversion..."
python convert_headers.py "$DIRECTORY" $DRY_RUN

echo ""
echo "Conversion complete!"
if [ -n "$DRY_RUN" ]; then
    echo "This was a dry run. Run without --dry-run to actually modify files."
fi