#!/usr/bin/gawk -f
BEGIN { FS = ":" }
{
if ($2 == "sauropod") {
pos = index($6,"-")
if (pos == 0) {
ts = te = int($6)
} else {
ts = int(substr($6, 1, pos-1))
te = int(substr($6, pos+1, length($6)-pos))
}

a=0
if (((ts <= 252) && (ts >= 201))||((te<=252)&&(ts>=201))) { nt++; sumt += $3 ;a=1}
if (((ts <= 201) && (ts >= 145))||((te<=201)&&(te>=145))) { nj++; sumj += $3 ;a=1}
if (((ts <= 145) && (ts >= 65))||((te<=145)&&(te>=65))) { nc++; sumc += $3 ;a=1}
if(a==0){
printf("Period cannot be determined for %s (%d,%d)\n", $1, ts, te);
}}
}
END {
printf("Average lengths of sauropod dinosaurs\n") > "avg.txt"
printf("Triassic period (252-201 Ma) : %6.2f meters\n", sumt / nt) >> "avg.txt"
printf("Jurassic period (201-145 Ma) : %6.2f meters\n", sumj / nj) >> "avg.txt"
printf("Cretaceous period (145-65 Ma) : %6.2f meters\n", sumc / nc) >> "avg.txt"
}