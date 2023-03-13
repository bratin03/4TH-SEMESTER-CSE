int main()
{
    int i = 5;
    const int &j = i;
    j = 6;
}

// error: assignment of read-only reference ‘j’

int main()
{
    int i = 5;
    const int &j = i;
    i = 6;
    cout << j << " " << i;
}

// Output:
// 6 6

int main()
{
    const int i = 5;
    int &j = i;
}

// error: binding reference of type ‘int&’ to ‘const int’ discards qualifiers
//       int &j = i;

int main()
{
    int i = 5, k = 6;
    int &j = i;
    &j = k;
}

// error: lvalue required as left operand of assignment
//   &j = k;