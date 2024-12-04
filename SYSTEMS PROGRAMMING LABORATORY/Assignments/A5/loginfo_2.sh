#!/bin/bash

if [ $# -eq 0 ]
then
   lastoutput=`last -w`
else
   lastoutput=`last -w -$1`
fi
declare -a loglines
while read -r line; do loglines+=("$line"); done <<< "$lastoutput"
n=$((${#loglines[@]}-2))
echo "$n login records read"
declare -iA logcnt
pattern="^[^ ][^ ]*"
i=0
while [ $i -lt $n ]
do
   line=${loglines[$i]}
   if [[ $line =~ $pattern ]]
   then
      username=${BASH_REMATCH[0]}
      logcnt[$username]=$((logcnt[$username]+1))
   fi
   i=$((i+1))
done
for username in ${!logcnt[@]}
do
   echo "$username logged in ${logcnt[$username]} times"
done
