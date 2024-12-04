#include <iostream>
using namespace std;
class Complex
{ // Private data members
    double re, im;

public:
    Complex(double a = 0.0, double b = 0.0) : re(a), im(b) {}
    ~Complex() {}
    void display();
    double real() { return re; }
    double img() { return im; }
    void set_real(double r) { re = r; }
    void set_img(double i) { im = i; }
    Complex operator+(Complex &t2);
};

void Complex::display()
{
    cout << re << " +j " << im << endl;
}

Complex Complex::operator+(Complex &t2)
{
    Complex sum;
    sum.re = (re + t2.re); // this works even though private
    sum.im = (im + t2.im);
    return sum;
}
int main()
{
    Complex c1(4.5, 25.25), c2(8.3, 10.25), c3;
    cout << "1st complex No:";
    c1.display();
    cout << "2nd complex No:";
    c2.display();
    c3 = c1 + c2; // Overload operator +
    cout << "Sum = ";
    c3.display();
}

/*
1st complex No:4.5 +j 25.25
2nd complex No:8.3 +j 10.25
Sum = 12.8 +j 35.5
*/

#include <iostream>
using namespace std;
class Complex
{
    double re, im;

public:
    Complex(double r = 0, double i = 0) : re(r), im(i) {}
    friend ostream &operator<<(ostream &os, const Complex &a);
    friend istream &operator>>(istream &is, Complex &a);
};
ostream &operator<<(ostream &os, const Complex &a)
{
    os << a.re << " +j " << a.im << endl;
    return os;
}
istream &operator>>(istream &is, Complex &a)
{
    is >> a.re >> a.im;
    return is;
}
int main()
{
    Complex d;
    cin >> d;
    cout << d;
}