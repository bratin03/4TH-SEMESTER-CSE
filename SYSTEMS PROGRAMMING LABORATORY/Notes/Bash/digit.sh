#!/bin/bash

function solve(){
    local n=$1
    if [ ${#n} -le 3 ]; then echo "$n"
    elif [ ${#n} -le 5 ]; then echo "${n:0:$(( ${#n}-3 ))},${n: -3}"
    elif [ ${#n} -le 7 ]; then echo "${n:0:$(( ${#n}-5 ))},${n:$(( ${#n}-5 )):-3},${n: -3}"
    elif [ ${#n} -le 9 ]; then echo "${n:0:$(( ${#n}-7 ))},${n:$(( ${#n}-7 )):-5},${n:$(( ${#n}-5 )):-3},${n: -3}"
    fi

}


echo -n "Enter the number: "; read n
solve $n
