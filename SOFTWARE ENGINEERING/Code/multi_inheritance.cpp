#include <bits/stdc++.h>
using namespace std;
class A
{
public:
    virtual ~A() { cout << "A::~A()" << endl; }
    virtual void foo()
    {
        cout << "A::foo()" << endl;
    }
};
class B : public virtual A
{
public:
    virtual ~B() { cout << "B::~B()" << endl; }
    virtual void foo()
    {
        cout << "B::foo()" << endl;
    }
};
class C : public virtual A
{
public:
    virtual ~C() { cout << "C::~C()" << endl; }
    virtual void foobar()
    {
        cout << "C::foobar()" << endl;
    }
};
class D : public B, public C
{
public:
    virtual ~D() { cout << "D::~D()" << endl; }
    virtual void foo()
    {
        cout << "D::foo()" << endl;
    }
    virtual void foobar()
    {
        cout << "D::foobar()" << endl;
    }
};

int main()
{
    A a;
    B b;
    C c;
    D d;
    A *a1;
    B *b1;
    C *c1;
    D *d1;
    a.foo();
    b.foo();
    c.foo();
    c.foobar();
    d.foo();
    d.foobar();
    cout << endl;
    a1 = &b;
    a1->foo();
    a1 = &c;
    a1->foo();
    a1 = &d;
    a1->foo();
    cout << endl;
    b1 = &d;
    b1->foo();
    cout << endl;
    c1 = &d;
    c1->foo();
    c1->foobar();
    cout << endl;
}

/*
A::foo()
B::foo()
A::foo()
C::foobar()
D::foo()
D::foobar()

B::foo()
A::foo()
D::foo()

D::foo()

D::foo()
D::foobar()

D::~D()
C::~C()
B::~B()
A::~A()
C::~C()
A::~A()
B::~B()
A::~A()
A::~A()
*/