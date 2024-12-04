/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Deparment of Computer Science and Engineering
    * Indian Institue of Technology, Kharagpur
*/

#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void fooprn(unsigned int x)
{
    if (x == 0)
    {
        printf("0");
        return;
    }
    unsigned int a[5];
    int i;
    for (i = 0; i < 5; i++)
    {
        a[i] = x % 1000;
        x = x / 1000;
    }
    if (a[4])
    {
        cmnprn(a[4]);
        printf(" trillion ");
    }
    if (a[3])
    {
        cmnprn(a[3]);
        printf(" billion ");
    }
    if (a[2])
    {
        cmnprn(a[2]);
        printf(" million ");
    }
    if (a[1])
    {
        cmnprn(a[1]);
        printf(" thousand ");
    }
    if (a[0])
    {
        printf(" ");
        cmnprn(a[0]);
    }
}
