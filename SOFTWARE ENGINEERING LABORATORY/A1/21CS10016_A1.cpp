/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Deparment of Computer Science and Engineering
    * Indian Institue of Technology, Kharagpur
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;
const int max_iter = 100;

// Struct Term represents a particular term with degree d and coefficient c in a polynomial

struct Term
{
    int d;
    double c;
    Term *next;
};

// Struct Polyn represents a polynomial which contains a linked list of terms

struct Polyn
{
    Term *arr;
};

// printx function takes a polynomial and displays it in terms of x

void printx(Polyn p1)
{
    Term *temp = p1.arr;
    if (temp == NULL)
        cout << 0;
    while (temp)
    {
        cout << showpos << temp->c;
        cout << noshowpos << "x^" << temp->d;
        temp = temp->next;
    }
    cout << "\n"
         << endl;
}

// This function adds term of degree d and coefficient c to a polynomial

void addremoveterm(Polyn &p1, int d, double c)
{ // checking if coefficient is non zero
    if (c != 0)
    {
        // if the polynomial contains no other term we enter this term at the start of the linked list
        if (p1.arr == NULL)
        {
            Term *temp = (Term *)malloc(sizeof(Term));
            temp->c = c;
            temp->d = d;
            temp->next = NULL;
            p1.arr = temp;

            return;
        }

        // otherwise we look for the right place to enter the term in sorted order of degree in the polynomial
        else
        { // linked list traversal for searching the right place
            Term *p, *q;
            p = p1.arr;
            q = p;
            while (p != NULL)
            { // if there already exists a term with the same degree we add the coefficients
                if (p->d == d)
                {
                    p->c += c;
                    // if the coefficients add up to zero, we remove the term
                    if (p->c == 0)
                    {
                        q->next = p->next;
                        // if we want to remove the term from the start of the list
                        if (p == p1.arr)
                            p1.arr = p->next;
                        free(p);
                    }

                    return;
                }
                // We enter the term in the appropiate place
                if (p->d > d)
                { // If the appropiate place is the start of the list
                    if (p == p1.arr)
                    {
                        Term *temp = (Term *)malloc(sizeof(Term));
                        temp->c = c;
                        temp->d = d;
                        temp->next = p1.arr;
                        p1.arr = temp;

                        return;
                    }
                    // If the appropiate place is somewhere in the middle of the list
                    else
                    {
                        Term *temp = (Term *)malloc(sizeof(Term));
                        temp->c = c;
                        temp->d = d;
                        temp->next = p;
                        q->next = temp;

                        return;
                    }
                }
                q = p;
                p = p->next;
            }
            // If we have traversed the whole linked list but still not added the term
            // Means the appropiate place is at the end of the list
            Term *temp = (Term *)malloc(sizeof(Term));
            temp->c = c;
            temp->d = d;
            temp->next = NULL;
            q->next = temp;

            return;
        }
    }
}

// This function removes term of degree d from a polynomial

void addremoveterm(Polyn &p1, int d)
{
    Term *temp = p1.arr, *q = temp;
    bool flag = 0;
    // Searching for term of degree d in the polynomial
    while (temp)
    {
        if (temp->d == d)
        { // deleting the term if it is found
            q->next = temp->next;
            if (temp == p1.arr)
                p1.arr = temp->next;
            free(temp);
            flag = 1;
            cout << "Deleted term of degree " << d << endl;
            return;
        }
        // Break out of the loop if we reach a degree d greater than our target degree
        if (temp->d > d)
            break;
        q = temp;
        temp = temp->next;
    }
    // No such term exist
    if (flag == 0)
        cout << "No term of degree " << d << " exists" << endl;
}

// This function removes term with coefficients less than epsilon from a polynomial

void addremoveterm(Polyn &p1, int a, int b, double e)
{
    Term *temp = p1.arr, *q = temp;
    bool flag = 0;
    // Traversing through the polynomial
    while (temp)
    { // If we find term with coefficient less than epsilon, we exclude that from the list and continue the traversal
        if (abs(temp->c) < e)
        {
            flag = 1;
            // If the term is at the start of linked list
            if (temp == p1.arr)
            {
                p1.arr = temp->next;
                temp = p1.arr;
                continue;
            }
            // If the term is somewhere in between the linked list
            else
            {
                q->next = temp->next;
                temp = q;
                continue;
            }
        }
        q = temp;
        temp = temp->next;
    }
    if (flag)
        cout << "Deleted term(s) with coefficient value less than " << e << endl;
    // No such term exist
    else
        cout << "No term with coefficient less than " << e << " exists" << endl;
}

// This function evaluates polynimal at a particular given value

double evaluate(Polyn p1, double x)
{ // Traversing through the polynomial and adding the value of the terms putting x equal to the provided value
    double sum = 0;
    Term *temp = p1.arr;
    while (temp)
    {
        sum += temp->c * pow(x, temp->d);
        temp = temp->next;
    }
    return sum;
}

// Overloading the + operator to add two polynomials

Polyn operator+(Polyn p1, Polyn p2)
{ // We traverse through both the polynomial together and keep adding the terms in sorted order of degree
    Polyn p;
    p.arr = NULL;
    Term *a = p1.arr, *b = p2.arr;
    while (a && b)
    { // Adding a term from polynomial 2
        if (a->d > b->d)
        {
            addremoveterm(p, b->d, b->c);
            b = b->next;
        }
        // Adding a term from polynomial 1
        else if (a->d < b->d)
        {
            addremoveterm(p, a->d, a->c);
            a = a->next;
        }
        else
        {
            if (a->c + b->c != 0)
            { // Adding a sum of term from both polynomial
                addremoveterm(p, a->d, a->c + b->c);
            }
            a = a->next;
            b = b->next;
        }
    }
    // Adding the remaining elements
    while (a)
    {
        addremoveterm(p, a->d, a->c);
        a = a->next;
    }
    while (b)
    {
        addremoveterm(p, b->d, b->c);
        b = b->next;
    }

    return p;
}

// Evaluating derivative of a given polynomial

Polyn derivative(Polyn p)
{ // Traverse through the polynomial and add derivative of each term to our answer
    Polyn d;
    d.arr = NULL;
    Term *a = p.arr;
    while (a)
    {
        if (a->d)
        {
            addremoveterm(d, a->d - 1, (a->d) * (a->c));
        }
        a = a->next;
    }
    return d;
}

// Function to evaluate the zero of a polynomial using Newton's method

double zero_newton(Polyn p1, double x0, double epsilon = 1e-9)
{ // Calculating the derivative of the function
    // Then keep using newton's method until the absolute value of polynimal at our calculated root is greater than epsilon
    Polyn p2 = derivative(p1);
    int i = 0;
    while (abs(evaluate(p1, x0)) > epsilon)
    { // If newton's method fails to converge or gets stuck at a particular xo or continues for more than 100 iterations
        // we return the value obtained till that iteration with a warning message
        if (evaluate(p1, x0) == 0 || evaluate(p2, x0) == 0 || i > max_iter)
        {
            cout << "Newton's method fails to converge. Returning the value obtained after " << i << " iterations" << endl;
            return x0;
        }
        x0 = x0 - (evaluate(p1, x0) / evaluate(p2, x0));
        i++;
    }
    return x0;
}

// This function shows the list of available functions

void showp(vector<Polyn> P)
{
    if (P.size() == 0)
    {
        cout << "No polynomial available currently." << endl;
        return;
    }
    cout << "The available polynomials are:\n";
    for (int i = 0; i < P.size(); i++)
    {
        cout << "P" << (i + 1) << "(x): ";
        printx(P[i]);
    }
}

// This function shows the availble options to user and returns the user's choice as an input

int show_menu()
{
    cout << "Enter 1 to create new Polynomial:" << endl;
    cout << "Enter 2 to delete an existing polynomial:" << endl;
    cout << "Enter 3 to add term to an existing polynomial:" << endl;
    cout << "Enter 4 to remove term of some degree:" << endl;
    cout << "Enter 5 to remove all terms with absolute coefficient values less than a particular value(𝜖):" << endl;
    cout << "Enter 6 to evaluate a polynomial at a particular value:" << endl;
    cout << "Enter 7 to add two existing polynomials:" << endl;
    cout << "Enter 8 to calculate derivative of a polynomial:" << endl;
    cout << "Enter 9 to calculate a zero (root) of a polynomial,using Newton's method:" << endl;
    cout << "Enter -1 to exit:" << endl;
    int a;
    cin >> a;
    return a;
}

// This function creates a new polynomial with no terms (i.e 0) and adds it to the list of available polynomials

void act1(vector<Polyn> &p)
{
    Polyn p1;
    p1.arr = NULL;
    p.push_back(p1);
    cout << "New polynomial created\n";
}

// This function deletes a polynomial from list of available polynomials

void act2(vector<Polyn> &p)
{
    int idx;
    cout << "Enter the polynomial index to delete:\n";
    cin >> idx;
    if (idx < 1 || idx > p.size())
    {
        cout << "Invalid Polynomial index entered\n";
        return;
    }
    p.erase(p.begin() + idx - 1);
    cout << "Deleted P" << idx << "(x)" << endl;
}

// This function adds a term to a polynomial from list of available polynomials

void act3(vector<Polyn> &p)
{
    int idx;
    cout << "Enter the polynomial index to add term:\n";
    cin >> idx;
    if (idx < 1 || idx > p.size())
    {
        cout << "Invalid Polynomial index entered\n";
        return;
    }
    int d;
    double c;
    cout << "Enter the degree of the term:\n";
    cin >> d;
    cout << "Enter the coefficient of the term:\n";
    cin >> c;
    addremoveterm(p[idx - 1], d, c);
    cout << "Inserted " << showpos << c << "x^" << noshowpos << d << " in P" << idx << "(x)" << endl;
}

// This function deletes a term of degree d from a polynomial from list of available polynomials

void act4(vector<Polyn> &p)
{
    int idx;
    cout << "Enter the polynomial index to remove term:\n";
    cin >> idx;
    if (idx < 1 || idx > p.size())
    {
        cout << "Invalid Polynomial index entered\n";
        return;
    }
    int d;
    cout << "Enter the degree of the term:\n";
    cin >> d;
    addremoveterm(p[idx - 1], d);
}

// This function removes term with coefficients less than epsilon from a polynomial from list of available polynomials

void act5(vector<Polyn> &p)
{
    int idx;
    cout << "Enter the polynomial index to remove term:\n";
    cin >> idx;
    if (idx < 1 || idx > p.size())
    {
        cout << "Invalid Polynomial index entered\n";
        return;
    }
    double epsilon;
    cout << "Enter the value of epsilon0(Enter -1 to use default value 1e-9):\n";
    cin >> epsilon;
    if (epsilon == -1)
    {
        addremoveterm(p[idx - 1], 0, 0);
    }
    else
    {
        addremoveterm(p[idx - 1], 0, 0, epsilon);
    }
}

// This function evaluates a polynimal from the given list of polynomial at a particular given value

void act6(vector<Polyn> &p)
{
    int idx;
    cout << "Enter the polynomial index to evaluate:\n";
    cin >> idx;
    if (idx < 1 || idx > p.size())
    {
        cout << "Invalid Polynomial index entered\n";
        return;
    }
    cout << "Enter the value of x:\n";
    double x;
    cin >> x;
    cout << "P" << idx << "(" << x << ")=" << evaluate(p[idx - 1], x) << endl;
}

// This function calculates the sum of two polynomials from the given list of polynomials

void act7(vector<Polyn> &p)
{
    int idx1, idx2;
    cout << "Enter the polynomial indices to add(separated by space):\n";
    cin >> idx1 >> idx2;
    if (idx1 < 1 || idx1 > p.size() || idx2 < 1 || idx2 > p.size())
    {
        cout << "Invalid Polynomial index entered\n";
        return;
    }
    Polyn temp = p[idx1 - 1] + p[idx2 - 1];
    cout << "P" << idx1 << "(x)+P" << idx2 << "(x)=";
    printx(temp);
    int keep;
    cout << "Enter 1 if you want to add the result to the list or Enter 0 to discard:\n";
    cin >> keep;
    if (keep == 1)
    {
        p.push_back(temp);
    }
}

// This function evaluates derivative of a polynomial from the list of available polynomials

void act8(vector<Polyn> &p)
{
    int idx;
    cout << "Enter the polynomial index to find derivative:\n";
    cin >> idx;
    if (idx < 1 || idx > p.size())
    {
        cout << "Invalid Polynomial index entered\n";
        return;
    }
    Polyn derv = derivative(p[idx - 1]);
    cout << "P'" << idx << "(x)=";
    printx(derv);
    int keep;
    cout << "Enter 1 if you want to add the result to the list or Enter 0 to discard:\n";
    cin >> keep;
    if (keep == 1)
    {
        p.push_back(derv);
    }
}

// This function evaluates the zero of a polynomial from the list of given polynomials using Newton's method

void act9(vector<Polyn> &p)
{
    int idx;
    cout << "Enter the polynomial index to find root:\n";
    cin >> idx;
    if (idx < 1 || idx > p.size())
    {
        cout << "Invalid Polynomial index entered\n";
        return;
    }
    int x0, epsilon;
    cout << "Enter x0(Initial value to start with in Newton's method):\n";
    cin >> x0;
    cout << "Enter the value of epsilon0(Enter -1 to use default value 1e-9):\n";
    cin >> epsilon;
    double ans;
    if (epsilon == -1)
    {
        ans = zero_newton(p[idx - 1], x0);
        cout << "Root of P" << idx << "(x) as solved by Newton's method starting from x0=" << x0 << " and 𝜖=1e-9 is " << ans << endl;
    }
    else
    {
        ans = zero_newton(p[idx - 1], x0, epsilon);
        cout << "Root of P" << idx << "(x) as solved by Newton's method starting from x0=" << x0 << " and 𝜖=" << epsilon << "is " << ans << endl;
    }
}

// The main function keeps on showing the list of available polynomials and the various operations that the user can execute
// It exits on receiving -1
int main()
{
    vector<Polyn> p;
    int key = 0;
    while (key != -1)
    {
        showp(p);
        key = show_menu();
        switch (key)
        {
        case 1:
            act1(p);
            break;
        case 2:
            act2(p);
            break;
        case 3:
            act3(p);
            break;
        case 4:
            act4(p);
            break;
        case 5:
            act5(p);
            break;
        case 6:
            act6(p);
            break;
        case 7:
            act7(p);
            break;
        case 8:
            act8(p);
            break;
        case 9:
            act9(p);
            break;
        default:
            if (key != -1)
                cout << "Enter a valid numer" << endl;
            continue;
        }
    }
}