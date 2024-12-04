/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Deparment of Computer Science and Engineering
    * Indian Institue of Technology, Kharagpur
*/

#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "bar.h"

void barprn(unsigned int n)
{
   unsigned int c, l, t;

   if (n == 0)
   {
      printf("zero");
      return;
   }
   c = n / 10000000;
   n %= 10000000;
   l = n / 100000;
   n %= 100000;
   t = n / 1000;
   n %= 1000;

   if (c)
   {
      cmnprn(c);
      printf(" crore");
   }
   if (l)
   {
      if (c)
         printf(" ");
      cmnprn(l);
      printf(" lakh");
   }
   if (t)
   {
      if (c || l)
         printf(" ");
      cmnprn(t);
      printf(" thousand");
   }
   if (n)
   {
      if (c || l || t)
         printf(" ");
      cmnprn(n);
   }
}
