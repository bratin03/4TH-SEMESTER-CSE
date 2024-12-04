#!/bin/bash

# Check if an argument has been passed
if [ "$#" -ne 1 ]; then
  echo "Usage: $0 <directory>"
  exit 1
fi

# Check if the argument is a valid directory
if [ ! -d "$1" ]; then
  echo "$1 is not a directory"
  exit 1
fi

# Initialize the list of files
last_files=$(cd "$1" && find . -type f)

# Print the list of files
echo "Files in $1:"
echo "$last_files"

# Continuously list modified files every minute
while true; do
  sleep 60

  # Get the current list of files
  current_files=$(cd "$1" && find . -type f)

  # Find modified files
  modified_files=$(comm -13 <(echo "$last_files" | sort) <(echo "$current_files" | sort))

  # Print modified files
  if [ -n "$modified_files" ]; then
    echo "Modified files in $1:"
    echo "$modified_files"
  fi

  # Update the list of files
  last_files=$current_files
done
