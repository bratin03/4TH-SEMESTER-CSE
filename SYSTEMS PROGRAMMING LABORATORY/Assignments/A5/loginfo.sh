#!/bin/bash

# Check if script is run with one positive integer argument
if [[ $# -eq 1 && $1 =~ ^[1-9][0-9]*$ ]]; then
  S=`last -w -n $1` # Get last n login records
else
  S=`last -w` # Get all login records
fi

# Store login records in an array
A=()
while read -r line; do
  A+=("$line")
done <<< "$S"

# Print the number of login records read
if [[ $# -eq 1 && $1 =~ ^[1-9][0-9]*$ && $1 -lt ${#A}-2 ]]; then
  echo "$1 login records read"
else
  echo "$((${#A}-2)) login records read"
fi

# Create an associative array to store the number of logins per user
declare -A H
count=0

# Parse the login records and update the number of logins per user
for line in "${A[@]}"; do
  # Exit loop if we've processed all login records except the last two
  if (( count >= ${#A[@]} - 2 )); then
    break
  fi
  # Extract the username from the login record and update the count in the associative array
  if [[ $line =~ ^([^ ]*[ ]) ]]; then
    username=${BASH_REMATCH[1]}
    H[$username]=$(( ${H[$username]} + 1 ))
  fi
  ((count++))
done

# Print the number of logins per user
for username in "${!H[@]}"; do
  count=${H[$username]}
  echo "$username logged in $count times"
done

exit 0 # Exit with a zero exit code to indicate success
