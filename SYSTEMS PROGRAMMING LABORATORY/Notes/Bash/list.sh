#!/bin/bash


solve (){
    local currentdir=$1
    local currentlvl=$2
    local lev=0
    c=`ls "$currentdir"`
    for entry in `ls "$currentdir"`;
    do
    if [ -f "$currentdir/$entry" ];
    then echo $entry;
    else echo $entry;
    fi
    done

}




if [ $# -eq 0 ]; then root=".";
else root=$1;
fi

if [ ! -d "$root" ];
then echo "$root is not a directory"
else
 solve "$root" 0
fi