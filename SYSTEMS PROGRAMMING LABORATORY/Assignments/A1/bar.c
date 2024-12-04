/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Deparment of Computer Science and Engineering
    * Indian Institue of Technology, Kharagpur
*/

#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void barprn(unsigned int n)
{
    if (n == 0)
    {
        printf("0");
        return;
    }
    int a0 = n % 1000;
    n = n / 1000;
    int a1 = n % 100;
    n = n / 100;
    int a2 = n % 100;
    n = n / 100;
    int a3 = n;
    if (a3)
    {
        cmnprn(a3);
        printf(" crore ");
    }
    if (a2)
    {
        cmnprn(a2);
        printf(" lakh ");
    }
    if (a1)
    {
        cmnprn(a1);
        printf(" thousand ");
    }
    if (a0)
    {
        cmnprn(a0);
    }
}
