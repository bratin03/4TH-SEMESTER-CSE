#include <iostream>
#include <exception>
using namespace std;

class Excp : public exception
{
};
class A
{
public:
    A() { cout << "A created" << endl; }
    ~A() { cout << "A destroyed" << endl; }
};
void g()
{
    A a;
    bool error = true;
    cout << "g() started\n";
    if (error)
        throw Excp();
    cout << "g() ended\n";
    return;
}

int main()
{
    try
    {
        cout << "g() called\n";
        g();
        cout << "g() returned\n";
    }
    catch (Excp &)
    {
        cout << "g() failed\n";
    }
    return 0;
}

/*
g() called
A created
g() started
A destroyed
g() failed
*/

#include <iostream>
#include <exception>
using namespace std;

class Excp : public exception
{
};
class A
{
public:
    A() { cout << "A created" << endl; }
    ~A() { cout << "A destroyed" << endl; }
};
void g()
{

    bool error = true;
    cout << "g() started\n";
    if (error)
        throw Excp();
    A a;
    cout << "g() ended\n";
    return;
}

int main()
{
    try
    {
        cout << "g() called\n";
        g();
        cout << "g() returned\n";
    }
    catch (Excp &)
    {
        cout << "g() failed\n";
    }
    return 0;
}

/*
g() called
g() started
g() failed
*/

#include <iostream>
#include <exception>
using namespace std;
class MyException : public exception
{
};
class MyClass
{
    int a;

public:
    MyClass(int a1) : a(a1) { cout << "MyClass created: " << a << endl; }
    ~MyClass() { cout << "Myclass destoryed: " << a << endl; }
};
void h()
{
    MyClass h_a(1);
    // throw 1;
    //   Line 1
    // throw 2.5;
    //  Line 2
    // throw MyException(); // Line 3
    // throw exception();
    //  Line 4
    throw MyClass(4);
    //  Line 5
}
// Stack unwind, h_a.~MyClass() called
// Passes on all exceptions
void g()
{
    MyClass g_a(2);
    try
    {
        h();
        bool okay = true; // Not executed
    }
    // Catches exception from Line 1
    catch (int)
    {
        cout << "int\n";
    }
    // Catches exception from Line 2
    catch (double)
    {
        cout << "double\n";
    }
    // Catches exception from Line 3-5 & passes on
    catch (...)
    {
        throw;
    }
}
// Stack unwind, g_a.~MyClass() called
void f()
{
    MyClass f_a(3);
    try
    {
        g();
        bool okay = true; // Not executed
    }
    // Catches exception from Line 3
    catch (MyException)
    {
        cout << "MyException\n";
    }
    // Catches exception from Line 4
    catch (exception)
    {
        cout << "exception\n";
    }
    // Catches exception from Line 5 & passes on
    catch (...)
    {
        throw;
    }
} // Stack unwind, f_a.~MyClass() called
int main()
{
    try
    {
        f();
        bool okay = true; // Not executed
    }
    // Catches exception from Line 5
    catch (...)
    {
        cout << "Unknown\n";
    }
    cout << "End of main()\n";
}

/*
MyClass created: 3
MyClass created: 2
MyClass created: 1
MyClass created: 4
Myclass destoryed: 1
Myclass destoryed: 2
Myclass destoryed: 3
Unknown
Myclass destoryed: 4
End of main()
*/

#include <iostream>
#include <exception>
using namespace std;
class A
{
public:
    A() { cout << "Constructor" << endl; }
    ~A() { cout << "Destructor" << endl; }
    A(A &a) { cout << "Copy constructor" << endl; }
    A &operator=(A a)
    {
        cout << "Copy assignment" << endl;
        return *this;
    }
};

int main()
{
    try
    {
        try
        {
            A a;
            cout << 1 << endl;
            throw a;
        }
        catch (A a)
        {
            cout << 2 << endl;
            throw a;
        }
    }
    catch (A a)
    {
        cout << "3" << endl;
    }
}

/*
Constructor
1
Copy constructor
Destructor
Copy constructor
2
Copy constructor
Destructor
Destructor
Copy constructor
3
Destructor
Destructor
*/

#include <iostream>
#include <exception>
using namespace std;
class A
{
public:
    A() { cout << "Constructor" << endl; }
    ~A() { cout << "Destructor" << endl; }
    A(A &a) { cout << "Copy constructor" << endl; }
    A &operator=(A a)
    {
        cout << "Copy assignment" << endl;
        return *this;
    }
};

int main()
{
    try
    {
        try
        {
            A a;
            cout << 1 << endl;
            throw a;
        }
        catch (A &a)
        {
            cout << 2 << endl;
            throw a;
        }
    }
    catch (A a)
    {
        cout << "3" << endl;
    }
}

/*
Constructor
1
Copy constructor
Destructor
2
Copy constructor
Destructor
Copy constructor
3
Destructor
Destructor
*/

#include <iostream>
#include <exception>
using namespace std;
class A
{
public:
    A() { cout << "Constructor" << endl; }
    ~A() { cout << "Destructor" << endl; }
    A(A &a) { cout << "Copy constructor" << endl; }
    A &operator=(A a)
    {
        cout << "Copy assignment" << endl;
        return *this;
    }
};

int main()
{
    try
    {
        try
        {
            A a;
            cout << 1 << endl;
            throw a;
        }
        catch (A &a)
        {
            cout << 2 << endl;
            throw a;
        }
    }
    catch (A &a)
    {
        cout << "3" << endl;
    }
}

/*
Constructor
1
Copy constructor
Destructor
2
Copy constructor
Destructor
3
Destructor
*/

#include <iostream>
#include <exception>
using namespace std;
class A
{
public:
    A() { cout << "Constructor" << endl; }
    ~A() { cout << "Destructor" << endl; }
    A(A &a) { cout << "Copy constructor" << endl; }
    A &operator=(A a)
    {
        cout << "Copy assignment" << endl;
        return *this;
    }
};

int main()
{
    try
    {
        try
        {
            A a;
            cout << 1 << endl;
            throw a;
        }
        catch (A a)
        {
            cout << 2 << endl;
            throw;
        }
    }
    catch (A a)
    {
        cout << "3" << endl;
    }
}

/*
Constructor
1
Copy constructor
Destructor
Copy constructor
2
Destructor
Copy constructor
3
Destructor
Destructor
*/

#include <iostream>
#include <exception>
using namespace std;
class A
{
public:
    A() { cout << "Constructor" << endl; }
    ~A() { cout << "Destructor" << endl; }
    A(A &a) { cout << "Copy constructor" << endl; }
    A &operator=(A a)
    {
        cout << "Copy assignment" << endl;
        return *this;
    }
};

int main()
{
    try
    {
        try
        {
            A a;
            cout << 1 << endl;
            throw a;
        }
        catch (A &a)
        {
            cout << 2 << endl;
            throw;
        }
    }
    catch (A a)
    {
        cout << "3" << endl;
    }
}

/*
Constructor
1
Copy constructor
Destructor
2
Copy constructor
3
Destructor
Destructor
*/

#include <iostream>
#include <exception>
using namespace std;
class A
{
public:
    A() { cout << "Constructor" << endl; }
    ~A() { cout << "Destructor" << endl; }
    A(A &a) { cout << "Copy constructor" << endl; }
    A &operator=(A a)
    {
        cout << "Copy assignment" << endl;
        return *this;
    }
};

int main()
{
    try
    {
        try
        {
            A a;
            cout << 1 << endl;
            throw a;
        }
        catch (A &a)
        {
            cout << 2 << endl;
            throw;
        }
    }
    catch (A &a)
    {
        cout << "3" << endl;
    }
}

/*
Constructor
1
Copy constructor
Destructor
2
3
Destructor
*/