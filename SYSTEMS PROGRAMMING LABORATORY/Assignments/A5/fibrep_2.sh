#!/bin/bash

if [ $# -eq 0 ]
then
   echo "Run fibrep.sh with a single positive integer argument"
   exit 1
else
   N=$1
   if [ $N -le 0 ]
   then
      echo "Invalid argument $N to fibrep.sh"
      exit 2
   fi
fi

declare -ia F=(0 1)
t=1
while true
do
   if [ ${F[$t]} -ge $N ]; then break; fi
   t=$((t+1))
   F[$t]=$((F[$t-1]+F[$t-2]))
done

echo "Computed Fibonacci numbers up to F($t) = ${F[$t]}"

echo -n "$N = "
printinstance="first"
while [ $N -gt 0 ]
do
   while [ ${F[$t]} -gt $N ]; do t=$((t-1)); done
   if [ $printinstance != first ]; then echo -n " + "; fi
   echo -n "F($t)"
   printinstance="notfirst"
   N=$((N-F[$t]))
done
echo ""
exit 0
