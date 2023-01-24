Static Library:
Creating Library: ar rcs libnumprn.a common.o foo.o bar.o
Running Non-Interactive mode: gcc -Wall -L. app.c -lnumprn
Running Interactive mode: gcc -Wall -L. -Dinteractive app.c -lnumprn

Shared Library
Creating Library: gcc -shared -o -libnumprn.so common.o foo.o bar.o
Running Non-Interactive mode: gcc -Wall -L. app.c -lnumprn
Running Interactive mode: gcc -Wall -L. -Dinteractive app.c -lnumprn
