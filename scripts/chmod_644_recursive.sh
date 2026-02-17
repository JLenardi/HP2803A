#!/bin/bash

# Recursively find all .c and .h files and set permissions to 644
find . -type f \( -name "*.c" -o -name "*.h" \) -exec chmod 644 {} \;

echo "Permissions updated to 644 for all .c and .h files."

