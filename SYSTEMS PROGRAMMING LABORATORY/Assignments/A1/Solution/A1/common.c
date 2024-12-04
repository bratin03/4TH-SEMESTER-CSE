/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Deparment of Computer Science and Engineering
    * Indian Institue of Technology, Kharagpur
*/

#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void cmnprn(unsigned int n)
{
   char S[20][16] = {
       "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
       "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
       "eighteen", "nineteen"};

   char T[10][16] = {
       "zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

   int hi, lo;

   if (n >= 1000)
   {
      printf("big");
      return;
   }
   if (n == 0)
   {
      printf("zero");
      return;
   }

   hi = n / 100;
   lo = n % 100;
   if (hi)
      printf("%s hundred", S[hi]);
   if (lo >= 20)
   {
      printf("%s%s", hi ? " " : "", T[lo / 10]);
      if (lo % 10)
         printf(" %s", S[lo % 10]);
   }
   else if (lo > 0)
      printf("%s%s", hi ? " " : "", S[lo]);
}
