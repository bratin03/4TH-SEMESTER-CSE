#!/usr/bin/gawk -f

BEGIN{FS=" "}
{
    Name=$1
    Roll=$2
    Mark=$3
    Names[$2]=$1
    Marks[$2]=$3
}

END{
    n=asort(Marks,Marks2)
    n2=asorti(Names,Rolls)
    for (mark in Marks2)
    {
        for(roll in Rolls)
        {
            if(Marks[Rolls[roll]]==Marks2[NR+1-mark])
            {
                print Names[Rolls[roll]] " " Rolls[roll] " " Marks2[NR+1-mark]
                break
            }
        }
        delete Rolls[roll]
    }
}