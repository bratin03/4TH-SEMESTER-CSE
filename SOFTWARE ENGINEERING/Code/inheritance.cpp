/*
• Derived ISA Base
• Data Members
◦ Derived class inherits all data members of Base class
◦ Derived class may add data members of its own
• Member Functions
◦ Derived class inherits all member functions of Base class
◦ Derived class may override a member function of Base class by redefining it with the same signature
◦ Derived class may overload a member function of Base class by redefining it with the same name;
but different signature
◦ Derived class may add new member functions
• Access Specification
◦ Derived class cannot access private members of Base class
◦ Derived class can access protected members of Base class
• Construction-Destruction
◦ A constructor of the Derived class must first call a constructor of the Base class to construct the
Base class instance of the Derived class
◦ The destructor of the Derived class must call the destructor of the Base class to destruct the Base
class instance of the Derived class

• Derived ISA Base
• Data Members
◦ Derived class inherits all data members of Base class
◦ Derived class may add data members of its own
• Object Layout
◦ Derived class layout contains an instance of the Base class
◦ Further, Derived class layout will have data members of its own
◦ C++ does not guarantee the relative position of the Base class instance and
Derived class members
*/

#include <bits/stdc++.h>
using namespace std;
class B
{
    int data1B_;

public:
    int data2B_;
};

class D : public B
{
    int infoD_;

public:
    int get1B() { return data1B_; } //<----
    int get2B() { return data2B_; }
};

// member "B::data1B_" is inaccessible

/*
• Derived ISA Base
• Member Functions
◦ Derived class inherits all member functions of Base class
▷ Note: Derived class does not inherit the Constructors and Destructor of Base
class but must have access to them
◦ Derived class may override a member function of Base class by redefining it with
the same signature
◦ Derived class may overload a member function of Base class by redefining it with
the same name; but different signature
◦ Derived class may add new member functions
• Static Member Functions
◦ Derived class does not inherit the static member functions of Base class
• Friend Functions
◦ Derived class does not inherit the friend functions of Base class
*/

#include <bits/stdc++.h>
using namespace std;
class B
{
    void f(int i) { cout << i << endl; }

public:
    void g(int i) { cout << i << endl; }
};

class D : public B
{
public:
    void f(int i) { cout << i << " D:" << endl; }
    void g(float i) { cout << i << " D:" << endl; } //<---- float but still calls it
};

int main()
{
    B b;
    D d;

    d.g(2);
    d.f(1);
}

/*
2 D:
1 D:
*/

#include <bits/stdc++.h>
using namespace std;

class B
{
    void f(int i) { cout << i << endl; }

public:
    void g(int i) { cout << i << endl; } //<---does not call it
};

class D : public B
{
public:
    void f(int i) { cout << i << " D:" << endl; }
    void g(string i) { cout << i << " D:(string)" << endl; }
};

int main()
{
    B b;
    D d;

    d.g(2);
    d.f(1);
}

/*
error: cannot convert ‘int’ to ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’}
      |     d.g(2);
      |         ^
      |         |
      |         int
bin.cpp:16:19: note:   initializing argument 1 of ‘void D::g(std::string)’
      |     void g(string i) { cout << i << " D:(string)" << endl; }
*/

/*
• protected Access Specification
◦ A new protected access specification is introduced for Base class
◦ Derived class can access protected members of Base class
◦ No other class or global function can access protected members of Base class
◦ A protected member in Base class is like public in Derived class
◦ A protected member in Base class is like private in other classes or global functions
*/

/*
• Derived ISA Base
• Constructor-Destructor
◦ Derived class does not inherit the Constructors and Destructor of Base class but
must have access to them
◦ Derived class must provide its own Constructors and Destructor
◦ Derived class cannot override or overload a Constructor or the Destructor of Base
class
• Construction-Destruction
◦ A constructor of the Derived class must first call a constructor of the Base class to
construct the Base class instance of the Derived class
◦ The destructor of the Derived class must call the destructor of the Base class to
destruct the Base class instance of the Derived class
*/

/*
Works even if inheritance is private or protected
*/

/*

                                            Inheritance
                       | public          |  protected      |   private
             -------------------------------------------------------------
             public    |  public         |  protected      |   private
             -------------------------------------------------------------
Visibility   protected | protected       |  protected      |   private
             -------------------------------------------------------------
             private   |  not inherited  | not inherited   |  not inherited

*/

#include <iostream>
using namespace std;
class A
{
private:
    int x;

protected:
    int y;

public:
    int z;
};

class B : public A
{
private:
    int u;

protected:
    int v;

public:
    int w;
    void f()
    {
        cout << x << y << z << endl; //<----- x gives an error
    }
};

class C : protected A
{
private:
    int u;

protected:
    int v;

public:
    int w;
    void f()
    {
        cout << x << y << z << endl; //<----- x gives an error
    }
};

class D : private A
{
private:
    int u;

protected:
    int v;

public:
    int w;
    void f()
    {
        cout << x << y << z << endl; //<----- x gives an error
    }
};

int main()
{
    A a;
    B b;
    C c;
    D d;
    cout << a.x << a.y << a.z << endl;                      //<-----x,y error
    cout << b.x << b.y << b.z << b.u << b.v << b.w << endl; //<-----x,y,u,v error
    cout << c.x << c.y << c.z << c.u << c.v << c.w << endl; //<-----x,y,z,u,v error
    cout << d.x << d.y << d.z << d.u << d.v << d.w << endl; //<-----x,y,z,u,v error
}