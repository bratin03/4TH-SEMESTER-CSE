/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Deparment of Computer Science and Engineering
    * Indian Institue of Technology, Kharagpur
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "common.h"
#include "foo.h"
#include "bar.h"

unsigned int urand()
{
   unsigned int r;

   r = rand();
   r <<= 1;
   r ^= (unsigned int)rand();
   return r;
}

int main()
{
   unsigned int n;

   srand((unsigned int)time(NULL));

#ifdef INTERACTIVE
   printf("Enter n: ");
   scanf("%u", &n);
#else
   do
      n = urand();
   while (n < 1000000000);
#endif
   while (1)
   {
      printf("\nn = %u\nfoo: \"", n);
      fooprn(n);
      printf("\"\nbar: \"");
      barprn(n);
      printf("\"\n");
      if (n == 0)
         break;
      n /= 10;
   }

   exit(0);
}
