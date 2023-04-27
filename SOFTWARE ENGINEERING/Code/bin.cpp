#include <iostream>
using namespace std;

void A()
{
    cout << " Hello " << endl;
}
// Function pointer as argument

void B(void (*fptr)())
{
    // Calling back function that fptr points to
    fptr();
}

int main()
{
    void (*fp)() = A;
    B(fp); // Or simply B ( A )
    return 0;
}