#!/bin/bash

# Directory containing the files
DIR="./core"

# Loop through .c and .h files
for file in "$DIR"/*.c "$DIR"/*.h; do
  # Check if file exists to avoid errors if no matches
  [ -e "$file" ] || continue

  # Get the base filename
  base=$(basename "$file")
  
  # Construct new filename with prefix
  new="$DIR/cor_$base"
  
  # Rename the file
  mv "$file" "$new"
done

