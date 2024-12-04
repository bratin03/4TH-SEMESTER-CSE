/*
Casting is safe for promotion (All the data types of the variables are upgraded to the
data type of the variable with larger data type)

bool → char → short int → int → unsigned int → long → unsigned →
long long → float → double → long double
*/

#include <iostream>
using namespace std;
class A
{
public:
    void f()
    {
        cout << "A::f()" << endl;
    }
    virtual void g()
    {
        cout << "A::g()" << endl;
    }
    void h()
    {
        cout << "A::h()" << endl;
    }
};

class B : public A
{
public:
    void f()
    {
        cout << "B::f()" << endl;
    }
    virtual void g()
    {
        cout << "B::g()" << endl;
    }
    virtual void h()
    {
        cout << "B::h()" << endl;
    }
};

class C : public B
{
public:
    void f()
    {
        cout << "C::f()" << endl;
    }
    virtual void g()
    {
        cout << "C::g()" << endl;
    }
    void h()
    {
        cout << "C::h()" << endl;
    }
};

int main()
{
    B *q = new C;
    A *p = q;
    A *y = new B;
    y->f();
    y->g();
    y->h();
    p->f();
    p->g();
    p->h();
    q->f();
    q->g();
    q->h();
}

/*
A::f()
B::g()
A::h()
A::f()
C::g()
A::h()
B::f()
C::g()
C::h()
*/