#include <iostream>
using namespace std;
int f(int, int);
double f(int);
int f(double, double);

int f(int a, int b)
{
    cout << "calling f1" << endl;
    return f(f(a - b), f(b - a));
}

double f(int c)
{
    cout << "calling f2" << endl;
    if (c > 10)
        return c / 2;
    else
        return c;
}

int f(double a, double b)
{
    cout << "calling f3" << endl;
    if (b > a)
        return f(a - b);
    else
        return f(b - a);
}
int main()
{
    cout << f(66, 25) << endl;
}
/*
calling f1
calling f2
calling f2
calling f3
calling f2
-61
*/

int main()
{
    cout << f(66.0, 25.0) << endl;
}
/*
calling f3
calling f2
-41
*/