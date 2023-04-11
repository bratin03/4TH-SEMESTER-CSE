#!/bin/bash

# Check if script is run with at least one argument
if [[ $# -eq 0 ]]; then
  echo "Run fibrep.sh with a single positive integer argument"
  exit 1
fi

# Check if argument is a positive integer
if [[ $1 -le 0 ]]; then
    echo "Invalid argument $1 to fibrep.sh"
    exit 1
fi

N=$1
F=(0 1) # Initialize the array with the first two Fibonacci numbers
t=1 # Initialize the index for the current Fibonacci number
indices=() # Initialize an empty array to store the indices of Fibonacci numbers used in the Zeckendorf representation

# Compute the Fibonacci numbers up to the smallest number that is greater than or equal to N
until [[ ${F[t]} -ge $N ]]; do
  F[t+1]=$(( F[t] + F[t-1] )) # Compute the next Fibonacci number by adding the previous two
  (( t++ )) # Increment the index
done

# Compute the Zeckendorf representation of N
for (( i=$t; i>0; i-- )); do
  if [[ ${F[i]} -le $N ]]; then
    N=$(( N - F[i] )) # Subtract the current Fibonacci number from N
    indices+=("$i") # Add the index of the current Fibonacci number to the array
  fi
done

# If N is not zero, it means there was no valid Zeckendorf representation for the original argument
if [[ $N -ne 0 ]]; then
  echo "Unable to find Zeckendorf representation for $1"
  exit 1
fi

echo "Computed Fibonacci numbers up to F($t) = ${F[$t]}"

# Print the Zeckendorf representation
length=${#indices[*]}
last_element="${indices[$length-1]}"
echo -n "$1 = "
for idx in ${indices[@]};
    do echo -n " F($idx) "
    if [ $last_element -ne $idx ]; then
        echo -n "+"
    else echo ""
    fi 
done

exit 0 # Exit with a zero exit code to indicate success
