#!/usr/bin/gawk -f
{
if ($2 == "large theropod") {
n = split($7, country, ", ");
for (i=1; i<=n; ++i) { tlist[country[i]] = tlist[country[i]] " " $1 }
}
}
END {
x=asorti(tlist,tlist2)
for (c in tlist2) {
printf("%-15s: %s\n", tlist2[c], tlist[tlist2[c]])
}
}