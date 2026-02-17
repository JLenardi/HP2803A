#!/bin/bash
#==================================================
# A64 build script for layered project
#==================================================

# Run from repository root:
#   ./scripts/build_a64.sh

set -euo pipefail

# Compiler flags
CFLAGS="-std=c99 -Wall -Wextra -Wconversion -Werror -pedantic"

# Include paths
INCLUDES="-I app -I services -I system -I hardware -I hardware/a64 -I core -I utils"

# Directories
COMMON_DIRS=(app services system hardware core utils)
PLATFORM_DIRS=(hardware/a64)

# Collect source files
SRCS=()

# Add platform-specific files first
for d in "${PLATFORM_DIRS[@]}"; do
    [ -d "$d" ] && SRCS+=( $(find "$d" -maxdepth 1 -name '*.c') )
done

# Add common files, skipping any overridden by platform files
for d in "${COMMON_DIRS[@]}"; do
    [ -d "$d" ] || continue
    for f in "$d"/*.c; do
        [ -f "$f" ] || continue
        base=$(basename "$f")
        # Check if this file exists in a platform dir
        skip=false
        for pd in "${PLATFORM_DIRS[@]}"; do
            if [ -f "$pd/$base" ]; then
                skip=true
                break
            fi
        done
        $skip || SRCS+=( "$f" )
    done
done

# Output executable
OUTDIR=build
OUT=$OUTDIR/prog

mkdir -p "$OUTDIR"

# Compile
echo "Compiling all A64 source files..."
gcc $CFLAGS $INCLUDES "${SRCS[@]}" -o "$OUT" -lm

echo "A64 build successful: $OUT"

