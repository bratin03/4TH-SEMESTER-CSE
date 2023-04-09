#!/usr/bin/gawk -f

BEGIN{
    FS=":"
}

{
    if($2=="sauropod"){
        n=index($6,"-")
        if(n==0){
            ts=int($6)
            te=int($6)
            tm=-int($6)
        }
        else{
            ts=int(substr($6,1,n-1))
            te=int(substr($6,n+1,length($6)-n))
            tm=-(ts+te)/2
        }
        tsa[$1]=ts
        tea[$1]=te
        tma[$1]=tm
    }
}

END{
    n=asort(tma,tma_sorted)
    for (i=1;i<=n;i++){
        for (dino in tma){
            if(tma[dino]==tma_sorted[i]){
                printf("Name: %s Living Times: %d-%d Length: %d\n",dino,tsa[dino],tea[dino],tsa[dino]-tea[dino])
                delete tma[dino]
            }
        }
    }
}
