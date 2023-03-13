### Generation of the static library

gcc -Wall -c common.c
gcc -Wall -c foo.c
gcc -Wall -c bar.c
ar rcs libnumprn.a common.o foo.o bar.o

### Generation of the dynamic library

gcc -Wall -fPIC -c common.c
gcc -Wall -fPIC -c foo.c
gcc -Wall -fPIC -c bar.c
gcc -shared -o libnumprn.so common.o foo.o bar.o

### Compilation with the static library

gcc -L. app.c -lnumprn
gcc -L. -DINTERACTIVE app.c -lnumprn

### Compilation with the dynamic library

gcc -L. -Wl,-rpath=. app.c -lnumprn
gcc -L. -Wl,-rpath=. -DINTERACTIVE app.c -lnumprn
