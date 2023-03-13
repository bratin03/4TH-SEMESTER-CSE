int main()
{
    const int n;
}

// error : uninitialized const 'n'

int main()
{
    const int n = 5;

    n = 6;
}

// error: assignment of read-only variable ‘n’

int main()
{
    const int n = 5;
    int *p = &n;
}

// error : invalid conversion from ‘const int *’ to ‘int *’

int main()
{
    const int n = 5;
    const int *p = &n;
}

// Fine

int main()
{
    int n = 5;
    const int *p = &n;

    n = 6;
}

// Fine

int main()
{
    int n = 5;
    const int *p = &n;

    *p = 7;
}

// error: assignment of read-only location ‘* p’

int main()
{
    const int n = 5;
    const int *a;
}

// Fine

int main()
{
    const int n = 5;
    int b = 4;
    const int *a = &n;
    a = &b;
}

// Fine

#include <iostream>
using namespace std;
int main()
{
    const int a = 5;
    int *b;
    b = (int *)&a;
    *b = 10;
    cout << a << " " << b << " " << &a << " " << *b << "\n";
}

// Output:
//  5 0x7fff29f7927c 0x7fff29f7927c 10

int main()
{
    int m = 4, n = 5;
    int *const a;
}

// error: uninitialized const ‘a’

int main()
{
    int m = 4, n = 5;
    int *const a = &m;
    a = &n;
}

// error: assignment of read-only variable ‘a’

#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    char *str = strdup("IIT, Kharagpur");
    str[0] = 'N';
    // Edit the name
    cout << str << endl;
    str = strdup("JIT, Kharagpur"); // Change the name
    cout << str << endl;
}

// output:
// NIT, Kharagpur
// JIT, Kharagpur

int main()
{
    const char *str = strdup("IIT, Kharagpur");
    str[0] = 'N';
    // Edit the name
    cout << str << endl;
    str = strdup("JIT, Kharagpur"); // Change the name
    cout << str << endl;
}

// error: assignment of read-only location ‘* str’
//   str[0] = 'N';

int main()
{
    char *const str = strdup("IIT, Kharagpur");
    str[0] = 'N';
    // Edit the name
    cout << str << endl;
    str = strdup("JIT, Kharagpur"); // Change the name
    cout << str << endl;
}

// error: assignment of read-only variable ‘str’
//     str = strdup("JIT, Kharagpur"); // Change the name

int main()
{
    const volatile int a = 6;
    cout << a << endl;
    a = 7;
    cout << a << endl;
}
// error: assignment of read-only variable ‘a’
//          a = 7;

int main()
{
    const volatile int a = 6;
    cout << a << endl;
    int *b = (int *)&a;
    *b = 9;
    cout << a << endl;
}
// 6
// 9