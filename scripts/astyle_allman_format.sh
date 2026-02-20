#!/bin/bash
# format_allman.sh — formats all .c and .h files with Allman style and forced braces
# Original files backed up with .orig

# Directories to process
DIRS="core hardware services system utils"

# Find all .c and .h files and run astyle on them
find $DIRS -type f \( -name "*.c" -o -name "*.h" \) -print0 | \
xargs -0 astyle --style=allman \
                --indent=spaces=4 \
                --pad-oper \
                --pad-header \
                --add-braces \
                --keep-one-line-blocks

echo "Formatting complete. Original files saved with .orig."

