!/bin/bash
while read -r line; do
if [[ $line =~ ^([^:]*)(:)([^:]*)(:)([^:]*)(:) ]];
then x=${BASH_REMATCH[5]} ;
if [ $x -ge 1000 ];
then echo ${BASH_REMATCH[1]}
fi
fi
done</etc/passwd