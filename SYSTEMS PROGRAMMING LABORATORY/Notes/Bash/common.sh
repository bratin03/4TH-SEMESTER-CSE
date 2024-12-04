#!/bin/bash

# Check if two arguments have been passed
if [ "$#" -ne 2 ]; then
  echo "Usage: $0 <dir1> <dir2>"
  exit 1
fi

# Check if the directories exist
if [ ! -d "$1" ]; then
  echo "$1 does not exist"
  exit 1
fi

if [ ! -d "$2" ]; then
  echo "$2 does not exist"
  exit 1
fi

# Find common files in both directories
common_files=$(comm -12 <(cd "$1" && ls) <(cd "$2" && ls))

# Print common files
echo "Common files in $1 and $2:"
echo "$common_files"