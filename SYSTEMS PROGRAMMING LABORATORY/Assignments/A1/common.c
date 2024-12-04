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
    unsigned int x = n;
    int j, i = 0;
    int a[3];
    a[0] = -1;
    a[1] = -1;
    a[2] = -1;
    if (n > 999)
    {
        printf("Big");
        return;
    }
    if (n == 0)
    {
        printf("Zero");
        return;
    }
    while (x > 0)
    {
        a[i] = x % 10;
        i++;
        x /= 10;
    }
    if (a[2] != -1)
    {
        j = a[2];
        if (j == 1)
            printf("One Hunderd ");
        if (j == 2)
            printf("Two Hunderd ");
        if (j == 3)
            printf("Three Hunderd ");
        if (j == 4)
            printf("Four Hunderd ");
        if (j == 5)
            printf("Five Hunderd ");
        if (j == 6)
            printf("Six Hunderd ");
        if (j == 7)
            printf("Seven Hunderd ");
        if (j == 8)
            printf("Eight Hunderd ");
    }
    if (a[1] == 1)
    {
        j = a[0];
        if (j == 0)
            printf("Ten");
        if (j == 1)
            printf("Eleven");
        if (j == 2)
            printf("Twelve");
        if (j == 3)
            printf("Thirteen");
        if (j == 4)
            printf("Fourteen");
        if (j == 5)
            printf("Fifteen");
        if (j == 6)
            printf("Sixten");
        if (j == 7)
            printf("Seventeen");
        if (j == 8)
            printf("Eighteen");
        if (j == 9)
            printf("Nineteen");
    }
    else
    {
        if (a[1] != -1)
        {
            j = a[1];

            if (j == 2)
                printf("Twenty");
            if (j == 3)
                printf("Thirty");
            if (j == 4)
                printf("Fourty");
            if (j == 5)
                printf("Fifty");
            if (j == 6)
                printf("Sixty");
            if (j == 7)
                printf("Seventy");
            if (j == 8)
                printf("Eighty");
            if (j == 9)
                printf("Ninety");
        }
    }
    if (a[0] != -1)
    {
        j = a[0];
        if (j == 1)
            printf("One");
        if (j == 2)
            printf("Tw0");
        if (j == 3)
            printf("Three");
        if (j == 4)
            printf("Four");
        if (j == 5)
            printf("Five");
        if (j == 6)
            printf("Six");
        if (j == 7)
            printf("Seven");
        if (j == 8)
            printf("Eight");
        if (j == 9)
            printf("Nine");
    }
}
