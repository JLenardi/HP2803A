#!/bin/bash
#==================================================
# AVR build script for layered project
#==================================================

# Run from repository root:
#   ./scripts/build_avr.sh

set -euo pipefail

# MCU and CPU frequency
MCU=atmega644
F_CPU=16000000UL

# Usage check (optional: allow platform argument for future AVR variants)
PLATFORM=${1:-avr}

# Compiler flags
CFLAGS="-mmcu=$MCU -DF_CPU=$F_CPU -Os -std=c99 -Wall -Wextra -Wconversion -Werror -pedantic"

# Base include paths
INCLUDES="-I app -I services -I system -I hardware -I core -I utils"

# Common directories
COMMON_DIRS=(app services system hardware core utils)

# Platform directories
PLATFORM_DIRS=(hardware/$PLATFORM)

# Add platform include paths
for d in "${PLATFORM_DIRS[@]}"; do
    INCLUDES="$INCLUDES -I $d"
done

# Collect source files
SRCS=()

# Platform-specific files first
for d in "${PLATFORM_DIRS[@]}"; do
    [ -d "$d" ] && SRCS+=( $(find "$d" -maxdepth 1 -name '*.c') )
done

# Add common files if not overridden by platform
for d in "${COMMON_DIRS[@]}"; do
    [ -d "$d" ] || continue
    for f in "$d"/*.c; do
        [ -f "$f" ] || continue
        base=$(basename "$f")
        skip=false
        for pd in "${PLATFORM_DIRS[@]}"; do
            [ -f "$pd/$base" ] && { skip=true; break; }
        done
        $skip || SRCS+=( "$f" )
    done
done

# Output files
OUTDIR=build
ELF=$OUTDIR/prog.elf
HEX=$OUTDIR/prog.hex

mkdir -p "$OUTDIR"

# Compile and link
echo "Compiling all AVR source files for platform: $PLATFORM..."
avr-gcc $CFLAGS $INCLUDES "${SRCS[@]}" -o "$ELF"

# Convert ELF to HEX
echo "Creating HEX file..."
avr-objcopy -O ihex -R .eeprom "$ELF" "$HEX"

echo "AVR build complete: $HEX"

