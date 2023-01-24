#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include"foo.h"
#include"bar.h"


int main()
{
#ifdef INTERACTIVE
    unsigned int n;
    printf("Enter n:")
        scanf("%u", &n);
    while (n != 0)
    {
        printf("%u\n", n);
        printf("foo: ");
        fooprn(n);
        printf("\n");
        printf("bar: ");
        barprn(n);
        printf("\n");
        n = n / 10;
    }
    if (n == 0)
    {
        printf("%u\n", n);
        printf("foo: ");
        fooprn(n);
        printf("\n");
        printf("bar: ");
        barprn(n);
        printf("\n");
        n = n / 10;
    }
#else
srand(time(0));
unsigned int n=rand();

    while (n != 0)
    {
        printf("%u\n", n);
        printf("foo: ");
        fooprn(n);
        printf("\n");
        printf("bar: ");
        barprn(n);
        printf("\n");
        n = n / 10;
    }
    if (n == 0)
    {
        printf("%u\n", n);
        printf("foo: ");
        fooprn(n);
        printf("\n");
        printf("bar: ");
        barprn(n);
        printf("\n");
        n = n / 10;
    }
#endif

exit(0);

}
