#!/usr/bin/gawk -f

BEGIN {
   FS = ":"
}

{
   if (NR == 1) {
      n = int($1)
      for (i=1; i<=n; ++i) {
         L[i] = 0;
         R[i] = 0;
         P[i] = 0;
      }
      hidx = 0
      print "Going to read tree with " n " nodes\n"
   } else {
      key = $1
      if (H[key] == 0) { H[key] = ++hidx; K[hidx] = key }
      idx = H[key]
      nc = split($2,C,",")
      if (nc != 2) {
         print "Invalid number of child nodes in Line " NR
      } else {
         lkey = C[1]
         rkey = C[2]
         if (lkey == "") lidx = 0;
         else {
            if (H[lkey] == 0) { H[lkey] = ++hidx; K[hidx] = lkey }
            lidx = H[lkey]
         }
         if (rkey == "") ridx = 0;
         else {
            if (H[rkey] == 0) { H[rkey] = ++hidx; K[hidx] = rkey }
            ridx = H[rkey]
         }
         L[idx] = lidx
         R[idx] = ridx
         if (lidx != 0) P[lidx] = idx
         if (ridx != 0) P[ridx] = idx
      }
   }
}

function prntree ( n, i, key )
{
   for (key in H) {
      i = H[key]
      printf("%10s :  ", key)
      printf("Index = %3d", i);
      printf("  Left child = "); printf("%-10s", (L[i]) == 0 ? "-" : K[L[i]]);
      printf("  Right child = "); printf("%-10s", (R[i]) == 0 ? "-" : K[R[i]]);
      printf("\n");
   }
   print ""
}

function findroot ( n, i, ridx )
{
    ridx = 0
    for (i=1; i<=n; ++i) {
       if (P[i] == 0) {
          ridx = i
       }
    }
   return ridx
}

function inorder ( rootidx, lidx, ridx )
{
   if (rootidx == 0) return
   lidx = L[rootidx]
   ridx = R[rootidx]
   inorder(lidx)
   printf("%10s ", K[rootidx]);
   ++npr
   if (npr == 5) { printf("\n"); npr = 0 }
   inorder(ridx)
}

END {
   prntree(n)
   rootidx = findroot(n)
   print "The root node has index " rootidx " and key \"" K[rootidx] "\"\n"
   print "Inorder listing of the keys:"
   inorder(rootidx)
   print "\n\nBye..."
}
