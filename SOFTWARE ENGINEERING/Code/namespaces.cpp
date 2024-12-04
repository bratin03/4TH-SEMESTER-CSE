#include <iostream>
#include <cstdlib>
using namespace std;

namespace myNS
{
    int abs(int n)
    {
        if (n < -128)
            return 0;

        if (n > 127)
            return 0;

        if (n < 0)
            return -n;

        return n;
    }
}
using namespace myNS;
int main()
{
    cout << abs(-203) << endl;
}

//error

#include <iostream>
#include <cstdlib>
using namespace std;

namespace myNS
{
    int abs(int n)
    {
        if (n < -128)
            return 0;

        if (n > 127)
            return 0;

        if (n < 0)
            return -n;

        return n;
    }
}
using namespace myNS;
int main()
{
    using namespace myNS;
    cout << abs(-203) << endl;
}

//error

#include <iostream>
#include <cstdlib>
using namespace std;

namespace myNS
{
    int abs(int n)
    {
        if (n < -128)
            return 0;

        if (n > 127)
            return 0;

        if (n < 0)
            return -n;

        return n;
    }
}

int main()
{
    using myNS::abs;
    cout << abs(-203) << endl;
}

//Fine

#include <iostream>
#include <cstdlib>
using namespace std;

namespace myNS
{
    int abs(int n)
    {
        if (n < -128)
            return 0;

        if (n > 127)
            return 0;

        if (n < 0)
            return -n;

        return n;
    }
}
using myNS::abs;
int main()
{

    cout << abs(-203) << endl;
}

//error

#include <iostream>
#include <cstdlib>
using namespace std;

namespace myNS
{
    int abs(int n)
    {
        if (n < -128)
            return 0;

        if (n > 127)
            return 0;

        if (n < 0)
            return -n;

        return n;
    }
}

int main()
{
    using myNS::abs;
    cout << ::abs(-203) << endl;
}

//Output 203