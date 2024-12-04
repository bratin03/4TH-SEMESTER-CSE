/*
• const cast operator: const cast<type>(expr)
◦ Explicitly overrides const and / or volatile in a cast
◦ Usually does not perform computation or change value
• static cast operator: static cast<type>(expr)
◦ Performs a non - polymorphic cast
◦ Usually performs computation to change value – implicit or user - defined • reinterpret cast operator: reinterpret cast<type>(expr)
◦ Casts between unrelated pointer types or pointer and integer
◦ Does not perform computation yet reinterprets value
• dynamic cast operator: dynamic cast<type>(expr)
◦ Performs a run - time cast that verifies the validity of the cast
◦ Performs pre - defined computation, sets null or throws exception
*/

// const_cast Operator

#include <iostream>
using namespace std;
class A
{
    int i_;

public:
    A(int i) : i_(i) {}
    int get() const { return i_; }
    void set(int j) { i_ = j; }
};
void print(char *str) { cout << str; }
int main()
{
    const char *c = "sample text";
    print(c);                     // error: ’void print(char *)’: cannot convert argument 1 from ’const char *’ to ’char *’
    print(const_cast<char *>(c)); // Okay
    const A a(1);
    a.get();
    a.set(5);                  // error: ’void A::set(int)’: cannot convert ’this’ pointer from ’const A’ to ’A &’
    const_cast<A &>(a).set(5); // Okay
    const_cast<A>(a).set(5);   // error: ’const_cast’: cannot convert from ’const A’ to ’A’
}

/*
bin.cpp: In function ‘int main()’:
bin.cpp:16:11: error: invalid conversion from ‘const char*’ to ‘char*’ [-fpermissive]
   16 |     print(c);                     // error: ’void print(char *)’: cannot convert argument 1 from ’const char *’ to ’char *’
      |           ^
      |           |
      |           const char*
bin.cpp:12:18: note:   initializing argument 1 of ‘void print(char*)’
   12 | void print(char *str) { cout << str; }
      |            ~~~~~~^~~
bin.cpp:20:12: error: passing ‘const A’ as ‘this’ argument discards qualifiers [-fpermissive]
   20 |     a.set(5);                  // error: ’void A::set(int)’: cannot convert ’this’ pointer from ’const A’ to ’A &’
      |            ^
bin.cpp:10:10: note:   in call to ‘void A::set(int)’
   10 |     void set(int j) { i_ = j; }
      |          ^~~
bin.cpp:22:20: error: invalid use of const_cast with type ‘A’, which is not a pointer, reference, nor a pointer-to-data-member type
   22 |     const_cast<A>(a).set(5);   // error: ’const_cast’: cannot convert from ’const A’ to ’A’
*/

#include <iostream>
using namespace std;
class A
{
    int i_;

public:
    A(int i) : i_(i) {}
    int get() const { return i_; }
    void set(int j) { i_ = j; }
};
void print(char *str) { cout << str; }
int main()
{
    char *c = "sample text";
    print(c);                     // error: ’void print(char *)’: cannot convert argument 1 from ’const char *’ to ’char *’
    print(const_cast<char *>(c)); // Okay
    A a(1);
    a.get();
    a.set(5);                  // error: ’void A::set(int)’: cannot convert ’this’ pointer from ’const A’ to ’A &’
    const_cast<A &>(a).set(5); // Okay
    const_cast<A>(a).set(5);   // error: ’const_cast’: cannot convert from ’const A’ to ’A’
}

/*
bin.cpp: In function ‘int main()’:
bin.cpp:15:15: warning: ISO C++ forbids converting a string constant to ‘char*’ [-Wwrite-strings]
   15 |     char *c = "sample text";
      |               ^~~~~~~~~~~~~
bin.cpp:22:20: error: invalid use of const_cast with type ‘A’, which is not a pointer, reference, nor a pointer-to-data-member type
   22 |     const_cast<A>(a).set(5);   // error: ’const_cast’: cannot convert from ’const A’ to ’A’
*/
#include <iostream>
using namespace std;
class A
{
    int i_;

public:
    A(int i) : i_(i) {}
    int get() const { return i_; }
    void set(int j) { i_ = j; }
};
void print(char *str) { cout << str; }
int main()
{
    const char *c = "sample text";
    print(const_cast<char *>(c));
    print((char *)(c));
    // C-Style Cast
    const A a(1);
    const_cast<A &>(a).set(5);
    ((A &)a).set(5);
    // C-Style Cast
    const_cast<A>(a).set(5); // error: ’const_cast’: cannot convert from ’const A’ to ’A’
    ((A)a).set(5);
    // C-Style Cast
}

/*
bin.cpp: In function ‘int main()’:
bin.cpp:23:20: error: invalid use of const_cast with type ‘A’, which is not a pointer, reference, nor a pointer-to-data-member type
   23 |     const_cast<A>(a).set(5); // error: ’const_cast’: cannot convert from ’const A’ to ’A’
      |
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i = 3;
    const int &cref_i = i;
    cout << "i = " << i << " " << cref_i << endl;
    const_cast<int &>(cref_i) = 4;
    cout << "i = " << i << " " << cref_i << endl;

    const int j = 3;
    int &ref_j = const_cast<int &>(j);
    cout << "j = " << j << " " << ref_j << endl;
    ref_j = 4;
    cout << "j = " << j << " " << ref_j << endl;

    int k = 3;
    const int *point_k = &k;
    *(const_cast<int *>(point_k)) = 4;
    cout << "k = " << k << " " << *point_k << endl;
    cout << "k = " << k << " " << *point_k << endl;

    const int l = 3;
    int *point_l = const_cast<int *>(&l);
    cout << "l = " << l << " " << *point_l << endl;
    *point_l = 4;
    cout << "l = " << l << " " << *point_l << endl;

    const int i1 = 3;
    const_cast<int &>(i1) = 4;
    cout << "i1 = " << i1 << endl;
}

/*
i = 3 3
i = 4 4
j = 3 3
j = 3 4
k = 4 4
k = 4 4
l = 3 3
l = 3 4
i1 = 3
*/

#include <bits/stdc++.h>
using namespace std;

struct type
{
    type() : i(3) {}
    void m1(int v) const
    {
        const_cast<type *>(this)->i = v;
    }
    int i;
};

int main()
{

    type t;
    cout << t.i << endl;
    t.m1(4);
    cout << t.i << endl;

    const type t1;
    cout << t1.i << endl;
    t1.m1(4);
    cout << t1.i << endl;
}

/*
3
4
3
4
*/

// static cast Operator

// static cast performs all conversions allowed implicitly (not only those with pointers
// to classes), and also the opposite of these

#include <iostream>
using namespace std;
int main()
{ // Built-in Types
    int i = 2;
    long j;
    double d = 3.7;
    int *pi = &i;
    double *pd = &d;
    void *pv = 0;
    i = d;                   // okay
    i = static_cast<int>(d); // okay
    i = (int)d;              // okay

    d = i;                      // okay
    d = static_cast<double>(i); // okay
    d = (double)i;              // okay

    pv = pi;                     // okay
    pi = pv;                     // invalid conversion from ‘void*’ to ‘int*’
    pi = static_cast<int *>(pv); // okay
    pi = (int *)pv;

    j = pd;                    // invalid conversion from ‘double*’ to ‘long int’
    j = static_cast<long>(pd); // error: invalid static_cast from type ‘double*’ to type ‘long int’
    j = (long)pd;              // okay

    i = (int)pd; // size error
}

#include <iostream>
using namespace std;
// Class Hierarchy
class A
{
public:
    int a = 1;
};
class B : public A
{
public:
    int b = 2;
};
int main()
{
    A a;
    B b;

    // UPCAST
    A *p = 0;
    p = &b;
    cout << p->a << endl;
    // implicit -- okay
    p = static_cast<A *>(&b); // static_cast -- okay
    cout << p->a << endl;
    p = (A *)&b;
    cout << p->a << endl;
    // C-style -- okay

    // DOWNCAST
    B *q = 0;
    // q = &a;
    //  implicit -- error  error: invalid conversion from ‘A*’ to ‘B*’
    q = static_cast<B *>(&a); // static_cast -- okay: RISKY: Should use dynamic_cast
    cout << q->a << " " << q->b << endl;
    q = (B *)&a;
    cout << q->a << " " << q->b << endl;

    // C-style -- okay
}

/*
1
1
1
1 237640944
1 237640944
*/

#include <iostream>
using namespace std;

class Window
{
public:
    int a;
    virtual void onResize()
    {
        a = 100;
    };
};

class SpecialWindow : public Window
{
public:
    int b;
    virtual void onResize()
    {
        static_cast<Window>(*this).onResize();
        b = 200;
    }
};

int main()
{
    SpecialWindow W1;
    W1.a = 1;
    W1.b = 2;
    cout << W1.a << " " << W1.b << endl;
    W1.onResize();
    cout << W1.a << " " << W1.b << endl;
}

/*
1 2
1 200
*/

#include <iostream>
using namespace std;

class Window
{
public:
    int a;
    virtual void onResize()
    {
        a = 100;
    };
};

class SpecialWindow : public Window
{
public:
    int b;
    virtual void onResize()
    {
        Window::onResize();
        b = 200;
    }
};

int main()
{
    SpecialWindow W1;
    W1.a = 1;
    W1.b = 2;
    cout << W1.a << " " << W1.b << endl;
    W1.onResize();
    cout << W1.a << " " << W1.b << endl;
}

/*
1 2
100 200
*/

#include <iostream>
using namespace std;

class B;
class A
{
public:
    A(int i = 0) { cout << "A::A(i)" << endl; }
    A(const B &) { cout << "A::A(B&)" << endl; }
    A &operator=(A x)
    {
        cout << "copy assignmnet operator" << endl;
        return *this;
    }
};

class B
{
};

int main()
{
    A a;
    B b;
    int i = 4;
    cout << endl;
    A a1(b);
    cout << endl;
    a = b;
    a = static_cast<A>(b);
    a = (A)b;

    a = i;
    a = static_cast<int>(i);
    a = (A)i;
}

/*
A::A(i)

A::A(B&)

A::A(B&)
copy assignmnet operator
A::A(B&)
copy assignmnet operator
A::A(B&)
copy assignmnet operator
A::A(i)
copy assignmnet operator
A::A(i)
copy assignmnet operator
A::A(i)
copy assignmnet operator
*/

#include <iostream>
using namespace std;

class B;
class A
{
public:
    int i_;
    A(int i = 0) : i_(i) { cout << "A::A(i)" << endl; }
    A(const B &)
    {
        cout << "A::A(B&)" << endl;
    }
    operator int()
    {
        cout << "A::operator int()\n";
        return i_;
    }
    A &operator=(A x)
    {
        cout << "copy assignmnet operator" << endl;
        return *this;
    }
};

class B
{
public:
    operator A()
    {
        cout << "B::operator A()\n";
        return A();
    }
};

int main()
{
    A a;
    B b;
    int i = 3;
    cout << endl;
    a = b;
    cout << endl;
    a = static_cast<A>(b);
    cout << endl;
    a = (A)b;
    cout << endl;
    a = i;
    cout << endl;
    a = static_cast<int>(i);
    cout << endl;
    a = (A)i;
    cout << endl;
    i = a;
    i = static_cast<int>(a);
    i = (int)a;
}

/*
A::A(i)

B::operator A()
A::A(i)
copy assignmnet operator

A::A(B&)
copy assignmnet operator

A::A(B&)
copy assignmnet operator

A::A(i)
copy assignmnet operator

A::A(i)
copy assignmnet operator

A::A(i)
copy assignmnet operator

A::operator int()
A::operator int()
A::operator int()
*/

#include <iostream>
using namespace std;

class B;
class A
{
public:
    int i_;
    A(int i = 0) : i_(i) { cout << "A::A(i)" << endl; }
    // A(const B &)
    // {
    //     cout << "A::A(B&)" << endl;
    // }
    operator int()
    {
        cout << "A::operator int()\n";
        return i_;
    }
    A &operator=(A x)
    {
        cout << "copy assignmnet operator" << endl;
        return *this;
    }
};

class B
{
public:
    operator A()
    {
        cout << "B::operator A()\n";
        return A();
    }
};

int main()
{
    A a;
    B b;
    int i = 3;
    cout << endl;
    a = b;
    cout << endl;
    a = static_cast<A>(b);
    cout << endl;
    a = (A)b;
    cout << endl;
    a = i;
    cout << endl;
    a = static_cast<int>(i);
    cout << endl;
    a = (A)i;
    cout << endl;
    i = a;
    i = static_cast<int>(a);
    i = (int)a;
}

/*
A::A(i)

B::operator A()
A::A(i)
copy assignmnet operator

B::operator A()
A::A(i)
copy assignmnet operator

B::operator A()
A::A(i)
copy assignmnet operator

A::A(i)
copy assignmnet operator

A::A(i)
copy assignmnet operator

A::A(i)
copy assignmnet operator

A::operator int()
A::operator int()
A::operator int()
*/

// reinterpret cast Operator

#include <iostream>
using namespace std;
class A
{
};
class B
{
};
int main()
{
    long i = 2;
    double d = 3.7;
    double *pd = &d;
    double *pd2;
    // i = pd;//errpr
    i = reinterpret_cast<long>(pd);
    cout << pd << " " << i << endl;
    i = (long)pd;
    cout << pd << " " << i << endl;
    pd2 = (double *)i;
    cout << pd2 << " " << i << " " << *pd2 << endl;
    pd2 = reinterpret_cast<double *>(i);
    cout << pd2 << " " << i << " " << *pd2 << endl;

    A *pA;
    B *pB;
    // pA = pB;//error
    pA = reinterpret_cast<A *>(pB);
    pA = (A *)pB;
}

/*
0x7ffc23060c18 140720896085016
0x7ffc23060c18 140720896085016
0x7ffc23060c18 140720896085016 3.7
0x7ffc23060c18 140720896085016 3.7
*/

#include <iostream>
using namespace std;
class A
{
};
class B
{
};
int main()
{
    int i = 2;
    double d = 3.7;
    double *pd = &d;
    double *pd2;
    // i = pd;//errpr
    i = reinterpret_cast<long>(pd);
    cout << pd << " " << i << endl;
    i = (long)pd;
    cout << pd << " " << i << endl;
    pd2 = (double *)i;
    cout << pd2 << " " << i << " " << *pd2 << endl;
    pd2 = reinterpret_cast<double *>(i);
    cout << pd2 << " " << i << " " << *pd2 << endl;

    A *pA;
    B *pB;
    // pA = pB;//error
    pA = reinterpret_cast<A *>(pB);
    pA = (A *)pB;
}

/*
0x7ffc86e97470 -2031520656
0x7ffc86e97470 -2031520656
Segmentation fault (core dumped)
*/

// dynamic cast Operator

#include <iostream>
using namespace std;
int main()
{
    int *p1 = new int(3);
    cout << *p1 << endl;
    double *p2 = new double(4.5);
    cout << *p2 << endl;
    p1 = dynamic_cast<int *>(p2);
    p2 = dynamic_cast<double *>(p1);
}

/*
bin.cpp: In function ‘int main()’:
bin.cpp:9:32: error: cannot dynamic_cast ‘p2’ (of type ‘double*’) to type ‘int*’ (target is not pointer or reference to class)
    9 |     p1 = dynamic_cast<int *>(p2);
      |                                ^
bin.cpp:10:35: error: cannot dynamic_cast ‘p1’ (of type ‘int*’) to type ‘double*’ (target is not pointer or reference to class)
   10 |     p2 = dynamic_cast<double *>(p1);
      |
*/
