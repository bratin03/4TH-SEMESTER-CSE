#include <iostream>
#include <exception>
using namespace std;

template <typename T>
class Myarray
{
    T *ptr;
    int size;

public:
    Myarray<T>(T inp[], int n) : ptr(new T[n]), size(n)
    {
        for (int i = 0; i < n; i++)
        {
            ptr[i] = inp[i];
        }
    }
    ~Myarray<T>()
    {
        {delete []  ptr; }
    }

    class Iterator
    {
        T *pointer;
        T *start;
        int size;

    public:
        Iterator(T *p = NULL) : pointer(p), start(p), size(-1) {}
        Iterator(T *p, T *st, int isize) : start(st), size(isize), pointer(p) {}
        T &operator*() const
        {
            return *pointer;
        }
        Iterator &operator=(const Iterator &other)
        {
            pointer = other.pointer;
            start = other.start;
            size = other.size;
            return *this;
        }
        friend bool operator==(const Iterator &a, const Iterator &b)
        {
            return a.pointer == b.pointer;
        }
        friend bool operator!=(const Iterator &a, const Iterator &b)
        {
            return a.pointer != b.pointer;
        }
        friend bool operator<=(const Iterator &a, const Iterator &b)
        {
            return a.pointer <= b.pointer;
        }
        friend bool operator<(const Iterator &a, const Iterator &b)
        {
            return a.pointer < b.pointer;
        }
        Iterator &operator++()
        {
            pointer++;
            return *this;
        }
        Iterator operator++(int)
        {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }
    };
    Iterator begin() {return ptr;}
    Iterator end() {return ptr+size;}
};

int main()
{
    int temp[] = {1, 2, 3, 4, 5};
    Myarray<int> A(temp, 5);
    Myarray<int>::Iterator it;
    try
    {
        for (it = A.begin(); it <= A.end(); it++)
            cout << *it << endl;
    }
    catch (out_of_range &e1)
    {
        cout << "Out of range exception" << endl;
    }
    return 0;
}
