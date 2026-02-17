#!/bin/bash
# Find and delete all *.*.orig files with confirmation

echo "Searching for files matching '*.*.orig'..."

find . -type f -name "*.*.orig" -ok rm {} \;

echo "Done."

