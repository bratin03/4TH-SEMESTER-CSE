/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Deparment of Computer Science and Engineering
    * Indian Institue of Technology, Kharagpur
*/

#include <stdio.h>
#include <stdlib.h>
#include "secret.h"

int main(int argc, char *argv[])
{
   int n, r;
   if (argc != 2)
   {
      fprintf(stderr, "*** Run as: ./oops YOUR_ROLL_NUMBER\n");
      exit(1);
   }

   gensecret(argv[1]);

   n = 10000;
   r = f(n);
   printf("f(%d) = %d\n", n, r);

   exit(0);
}
