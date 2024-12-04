/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Deparment of Computer Science and Engineering
    * Indian Institue of Technology, Kharagpur
*/

#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "foo.h"

void fooprn(unsigned int n)
{
   unsigned int b, m, t;

   if (n == 0)
   {
      printf("zero");
      return;
   }
   b = n / 1000000000;
   n %= 1000000000;
   m = n / 1000000;
   n %= 1000000;
   t = n / 1000;
   n %= 1000;

   if (b)
   {
      cmnprn(b);
      printf(" billion");
   }
   if (m)
   {
      if (b)
         printf(" ");
      cmnprn(m);
      printf(" million");
   }
   if (t)
   {
      if (b || m)
         printf(" ");
      cmnprn(t);
      printf(" thousand");
   }
   if (n)
   {
      if (b || m || t)
         printf(" ");
      cmnprn(n);
   }
}
