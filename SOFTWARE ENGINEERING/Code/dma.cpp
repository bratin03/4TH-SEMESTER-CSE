#include <iostream>
using namespace std;
int main()
{
    int *p = new int();
    cout << *p << endl;
    delete p;
}
// 0

#include <iostream>
using namespace std;
int main()
{
    int *p = (int *)operator new(sizeof(int));
    cout << *p << endl;
    operator delete(p);
}
// 0

#include <iostream>
using namespace std;
int main()
{
    int *p = new int[3];
    cout << *(p) << endl;
    delete[] p;
}

// 0

#include <iostream>
using namespace std;
int main()
{
    unsigned char buf[sizeof(int) * 2]; // Byte buffer on stack
    // placement new in buffer buf
    int *pInt = new (buf) int(3);
    int *qInt = new (buf + sizeof(int)) int(5);
    int *pBuf = (int *)(buf + 0);
    // *pInt in buf[0] to buf[sizeof(int)-1]
    int *qBuf = (int *)(buf + sizeof(int));
    // *qInt in buf[sizeof(int)] to buf[2*sizeof(int)-1]
    cout << "Buf Addr Int Addr" << endl
         << pBuf << " " << pInt << endl
         << qBuf << " " << qInt << endl;
    cout << "1st Int 2nd Int" << endl
         << *pBuf << " " << *qBuf << endl;
    int *rInt = new int(7); // heap allocation
    cout << "Heap Addr 3rd Int" << endl
         << rInt << " " << *rInt << endl;
    delete rInt;
    // delete integer from heap
    // No delete for placement new
}

/*
Buf Addr Int Addr
0x7ffe1d5eed10 0x7ffe1d5eed10
0x7ffe1d5eed14 0x7ffe1d5eed14
1st Int 2nd Int
3 5
Heap Addr 3rd Int
0x56163de622c0 7
*/

#include <iostream>
#include <stdlib.h>
using namespace std;
void *operator new(size_t n)
{ // Definition of Operator new
    cout << "Overloaded new" << endl;
    void *ptr = malloc(n);
    // Memory allocated to ptr. Can be done by function operator new()
    return ptr;
}
void operator delete(void *p)
{ // Definition of operator delete
    cout << "Overloaded delete" << endl;
    free(p);
    // Allocated memory released. Can be done by function operator delete()
}
int main()
{ // 1
    int *p = new int(3);
    cout << "The value is : " << *p << endl;
    delete p;
    cout << endl;
    // 2
    int *q = (int *)operator new(sizeof(int));
    *q = 2;
    cout << "The value is : " << *q << endl;
    operator delete(q);
    cout << endl;
    // 3
    int *a = new int[4];
    for (int j = 0; j < 4; j++)
    {
        a[j] = (j + 1) * (j + 1);
        cout << a[j] << " ";
    }
    cout << endl;
    delete[] a;
    cout << endl;
    // 4
    int *b = (int *)operator new(sizeof(int) * 4);
    for (int j = 0; j < 4; j++)
    {
        b[j] = (j) * (j);
        cout << b[j] << " ";
    }
    cout << endl;
    operator delete(b);
    cout << endl;
    // 5
    unsigned char buf[sizeof(int) * 2];
    int *pInt = new (buf) int(3);
    int *qInt = new (buf + sizeof(int)) int(4);
    cout << *pInt << endl
         << *qInt << endl;
}

/*
Overloaded new
The value is : 3
Overloaded delete

Overloaded new
The value is : 2
Overloaded delete

Overloaded new
1 4 9 16
Overloaded delete

Overloaded new
0 1 4 9
Overloaded delete

3
4
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
void *operator new[](size_t os, char setv)
{ // Fill the allocated array with setv
    void *t = operator new(os);
    memset(t, setv, os);
    return t;
}
void operator delete[](void *ss)
{
    operator delete(ss);
}
int main()
{
    char *t = new ('#') char[10]; // Allocate array of 10 elements and fill with ’#’

    cout << "p = " << (t) << endl;
    for (int k = 0; k < 10; ++k)
        cout << t[k];
    delete[] t;
}

/*
p = ##########
##########
*/