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






#include <stdio.h>
int (*pt2Function)(int, char, char);
int DoIt(int a, char b, char c);
// typedef int (*pt2Function)(int, char, char);

int main()
{
    pt2Function = DoIt;
    pt2Function = &DoIt;
    // Both are Fine



    // pt2Function f = &DoIt;

    int result = (*pt2Function)(12, 'a', 'b');
    int result = pt2Function(12, 'a', 'b');
    //Both are Fine



    // int result = f(12, 'a', 'b');
    printf("%d", result);
    return 0;
}

int DoIt(int a, char b, char c)
{
    printf("DoIt\n");
    return a + b + c;
}

//Fine



#include <stdio.h>
typedef int (*pt2Function)(int, char, char); //Added typedef
int DoIt(int a, char b, char c);
// typedef int (*pt2Function)(int, char, char);

int main()
{
    pt2Function = DoIt;
    pt2Function = &DoIt;
    //Both are error

   // pt2Function f = &DoIt;

    int result = pt2Function(12, 'a', 'b');
   //int result = f(12, 'a', 'b');
    printf("%d", result);
    return 0;
}

int DoIt(int a, char b, char c)
{
    printf("DoIt\n");
    return a + b + c;
}

/*
error: expected unqualified-id before ‘=’ token
    8 |     pt2Function = DoIt

 error: invalid conversion from ‘pt2Function’ {aka ‘int (*)(int, char, char)’} to ‘int’ [-fpermissive]
   11 |     int result = pt2Function(12, 'a', 'b');
      |                  ^~~~~~~~~~~~~~~~~~~~~~~~~
      |                  |
      |                  pt2Function {aka int (*)(int, char, char)}
*/



#include <stdio.h>
typedef int (*pt2Function)(int, char, char);
int DoIt(int a, char b, char c);
// typedef int (*pt2Function)(int, char, char);

int main()
{
    // pt2Function = &DoIt;
    pt2Function f = &DoIt;
    pt2Function f = DoIt;
    //Both are Fine



    int result = f(12, 'a', 'b');
    int result = (*f)(12, 'a', 'b');
    //Both are Fine


    printf("%d", result);
    return 0;
}

int DoIt(int a, char b, char c)
{
    printf("DoIt\n");
    return a + b + c;
}

//Fine



#include <iostream>
using namespace std;

class A
{
public:
    int DoIt(float a, char b, char c)
    {
        cout << "A::DoIt" << endl;
        return a + b + c;
    }
};

int (A::*pt2Member)(float, char, char);

int main()
{
    pt2Member = &A::DoIt;

    A a;
    int result = (a.*pt2Member)(2, 'a', 'b');
    cout << result << endl;
}
