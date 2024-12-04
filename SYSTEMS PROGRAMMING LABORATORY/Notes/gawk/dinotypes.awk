#!/usr/bin/gawk -f

BEGIN {
  FS=":"
}

{
  type=$2
  name=$1
  dinos[type][name]=1
  count[type]++
}

END {
  for (type in dinos) {
    print type ":"
    for (name in dinos[type]) {
      print "\t" name
    }
    print "Total count = " count[type] "\n"
  }
}
