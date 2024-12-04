#!/bin/bash

function checkfib(){
    local a=0
    local b=1
    local c=1
    local n=$1
    if [ $n -eq 0 ];
    then {
        echo "$1 is a Fibonacci Number"
    };
    elif [ $n -eq 0 ];
    then {
        echo "$1 is a Fibonacci Number"
    };
    else {
        while [ $b -le $n ];
        do
        if [ $b -eq $n ];
        then {
            echo "$1 is a Fibonacci Number"
            return 
        }
                fi
        c=$b
        b=$((a+b))
        a=$c

        done
        echo "$1 is not a Fibonacci Number"
    }
    fi
    
}

for arg;
do
    checkfib $arg
done
