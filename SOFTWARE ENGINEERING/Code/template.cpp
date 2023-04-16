#include <iostream>
#include <string>
#include <cstring>

using namespace std;

template <class T1 = int, class T2 = string> // Version 1 with default parameters
class Student
{
    T1 roll_;
    T2 name_;

public:
    Student(T1 r, T2 n) : roll_(r), name_(n) {}
    void Print() const { std::cout << "Version 1: (" << name_ << ", " << roll_ << ")" << std::endl; }
};
template <class T1> // Version 2: Partial Template Specialization
class Student<T1, char *>
{
    T1 roll_;
    char *name_;

public:
    Student(T1 r, char *n) : roll_(r), name_(std::strcpy(new char[std::strlen(n) + 1], n)) {}
    void Print() const { std::cout << "Version 2: (" << name_ << ", " << roll_ << ")" << std::endl; }
};
int main()
{
    Student<int, string> s1(2, "Ramesh");
    s1.Print();
    // Version 1: T1 = int, T2 = string
    Student<int>
        s2(11, "Shampa");
    s2.Print();
    // Version 1: T1 = int, defa T2 = string
    Student<>
        s3(7, "Gagan");
    s3.Print();
    // Version 1: defa T1 = int, defa T2 = string
    Student<string>
        s4("X9", "Lalita");
    s4.Print(); // Version 1: T1 = string, defa T2 = string
    Student<int, char *> s5(3, "Gouri");
    s5.Print();
    // Version 2: T1 = int, T2 = char*
}