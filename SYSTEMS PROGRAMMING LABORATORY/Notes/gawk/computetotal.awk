#!/usr/bin/gawk -f

BEGIN{FS=" "  ; OFS="\t"}
{
    if(NR==1){n=$1}
    if(NR==2){
        for(i=1;i<=n;i++)
        {
            arr[i]=int($i)
        }
    }
    if(NR==3){
        for(i=1;i<=n;i++)
        {
            per[i]=int($i)
        }
    }
    if(NR>3){
        name=$1
        roll=$2
        score=0
        total=100
        
        for(i=3;i<n+3;i++){
            if($i=="GRANT"){
                total-=per[i-2]
            }
            else if($i=="ABSENT"){
            }
            else{score+=(int($i)/arr[i-2])*per[i-2]}
        }
        score=score*100/total
        print name " " roll " " score >> "foototal.txt"
    }
}
