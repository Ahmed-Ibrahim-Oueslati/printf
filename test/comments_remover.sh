#!/bin/bash
# Check if a filename is provided
if [ -z "$1" ]; then
  echo "Usage: $0 filename"
  exit 1
fi

# Create a temporary file to store the modified content
tmpfile=$(mktemp)

# Remove comments starting with '//' and the rest of the line
sed 's/\/\/.*//' "$1" > "$tmpfile"

# Overwrite the original file with the modified content
mv "$tmpfile" "$1"

