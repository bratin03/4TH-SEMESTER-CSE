#include <iostream>
using namespace std;
void A()
{ 
    cout << " Hello " << endl;
}

void C()
{
    cout << " Bye " << endl;
}

// Function pointer as argument
void B(void (*fptr)())
{
    // Calling back function that fptr points to
    fptr();
}
int main()
{
    void (*fp)() = C;
    B(fp); // Or simply B ( A )
    return 0;
}