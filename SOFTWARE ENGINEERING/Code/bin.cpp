#include <iostream>
using namespace std;

class B;
class A
{
public:
    int i_;
};

class B
{
public:
    operator A()
    {
        cout << "B::operator A()\n";
        return (A)(*this);
    }
};

int main()
{
    A a;
    B b;
    a=b;
}
