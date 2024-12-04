/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Deparment of Computer Science and Engineering
    * Indian Institue of Technology, Kharagpur
*/

#include <bits/stdc++.h>
#include "rdb.h"
using namespace std;

/*
Bratin Mondal
21CS10016
*/

// Function to show menu and take input for actions
int show_menu(vector<Relation *> Rlist)
{
    cout << endl
         << Rlist.size() << " Relation(s) are available" << endl;
    if (Rlist.size() == 0)
    {
        cout << "Enter 1 to create new Relation:" << endl
             << "Enter -1 to exit:" << endl;
        int key = -2;
        while (key != -1 && key != 1)
        {
            cin >> key;
            if (key != -1 && key != 1)
            {
                cout << "Please enter valid choice:" << endl;
            }
        }
        return key;
    }
    else
    {
        cout << "Enter 1 to create new Relation:" << endl
             << "Enter 2 to delete an existing Relation:" << endl
             << "Enter 3 to add record to a Table:" << endl
             << "Enter 4 to display a Table:" << endl
             << "Enter 5 to do some operation with a Table:" << endl
             << "Enter -1 to exit:" << endl;

        int key = -2;

        while (key < -1 || key > 5 || key == 0)
        {
            cin >> key;
            if (key < -1 || key > 5 || key == 0)
            {
                cout << "Please enter valid choice:" << endl;
            }
        }
        return key;
    }
}

// Function to show menu and take input for operations
int do_operations()
{
    cout << "Enter 1 to do Union operation:" << endl
         << "Enter 2 to do Difference operation:" << endl
         << "Enter 3 to do Cartesian Product operation:" << endl
         << "Enter 4 to do Projection operation:" << endl
         << "Enter 5 to do Selection operation:" << endl
         << "Enter 6 to do Rename operation:" << endl
         << "Enter 7 to do Natural Join operation:" << endl;

    int key = -1;
    while (key < 0 || key > 7)
    {
        cin >> key;
        if (key < 0 || key > 7)
        {
            cout << "Please enter valid index:" << endl;
        }
    };
    return key;
}

// Function to display attributes only
void display_attr(Relation *R)
{
    if (R == NULL)
    {
        return;
    }
    cout << "The attributes are:" << endl;
    for (int i = 0; i < R->natttr; i++)
    {
        cout << "| " << R->attrnames.at(i);
        if (R->attrinds[i] == 0)
        {
            cout << " (Integer) ";
        }
        if (R->attrinds[i] == 1)
        {
            cout << " (Float) ";
        }
        if (R->attrinds[i] == 2)
        {
            cout << " (String) ";
        }
        cout << " |";
    }
    cout << endl;
}

// adding new relation to list of relations
void new_relation(vector<Relation *> &Rlist)
{
    Relation *Rnew = new Relation;
    int temp;
    cout << "Enter the no of attributes in the relation:" << endl;
    cin >> temp;
    Rnew->natttr = temp;
    string temps;

    for (int i = 0; i < Rnew->natttr; i++)
    {
        cout << "Enter " << i << " attribute name:" << endl;
        cin >> temps;
        cout << "Enter " << i << " attribute type:(0 for integer , 1 for float , 2 for string)" << endl;
        cin >> temp;
        Rnew->attrinds.push_back(temp);
        Rnew->attrnames.push_back(temps);
    }
    display_attr(Rnew);

    Rnew->nrecs = 0;
    Rlist.push_back(Rnew);
}

// adding new record to an existing relation
void add_record(Relation *R)
{
    Record *newr = new Record;
    int temp1;
    float temp2;
    string temp3;
    display_attr(R);

    for (int i = 0; i < R->natttr; i++)
    {
        if (R->attrinds[i] == 0)
        {
            cout << i << " attribute is a integer and its name is " << R->attrnames[i] << " Enter the integer for new record" << endl;
            cin >> temp1;
            integerAttribute *x = new integerAttribute(temp1);
            newr->attrptr.push_back(x);
        }

        if (R->attrinds[i] == 1)
        {
            cout << i << " attribute is a float and its name is " << R->attrnames[i] << " Enter the float for new record" << endl;
            cin >> temp2;
            floatAttribute *y = new floatAttribute(temp2);
            newr->attrptr.push_back(y);
        }

        if (R->attrinds[i] == 2)
        {
            cout << i << " attribute is a string and its name is " << R->attrnames[i] << " Enter the string for new record" << endl;
            cin >> temp3;
            stringAttribute *z = new stringAttribute(temp3);
            newr->attrptr.push_back(z);
        }
    }

    bool flag = 1;

    for (auto rec : R->recs)
    {
        if (*rec == *newr)
        {
            cout << "Record already exists" << endl;
            flag = 0;
            break;
        }
    }

    if (flag)
    {
        R->recs.push_back(newr);
        R->nrecs++;
    }
}

// function to implement the selection operation
Relation *do_selection(Relation *R)
{
    int disjunction;
    int conjunction;
    int typekey;
    string str;
    char c;
    int aa;
    float bb;
    string cc;
    DNFformula *f = new DNFformula;
    list<tuple<string, char, Attr *>> ll;
    cout << "Enter number of terms in DNF form" << endl;
    cin >> disjunction;

    for (int i = 0; i < disjunction; i++)
    {
        ll.clear();
        cout << "Enter numer of terms in Conjunction " << i + 1 << " term of DNF form" << endl;
        cin >> conjunction;
        for (int j = 0; j < conjunction; j++)
        {
            cout << "Enter " << j + 1 << " attribute type:(0 for integer , 1 for float , 2 for string)" << endl;
            cin >> typekey;
            cout << "Enter attribute Name:" << endl;
            cin >> str;
            cout << "Enter comparison operator:" << endl;
            cin >> c;
            cout << "Enter value to compare with:" << endl;
            if (typekey == 0)
            {
                cin >> aa;
                integerAttribute *x = new integerAttribute(aa);
                ll.push_back(make_tuple(str, c, x));
            }

            if (typekey == 1)
            {
                cin >> bb;
                floatAttribute *y = new floatAttribute(bb);
                ll.push_back(make_tuple(str, c, y));
            }

            if (typekey == 2)
            {
                cin >> cc;
                stringAttribute *z = new stringAttribute(cc);
                ll.push_back(make_tuple(str, c, z));
            }
        }

        f->ops.push_back(ll);
    }

    Relation *Rnew = selection(R, f);
    return Rnew;
}

// display an existing relation
void display(Relation *R)
{
    if (R == NULL)
    {
        return;
    }
    for (int i = 0; i < R->natttr; i++)
    {
        cout << "| " << R->attrnames.at(i) << " |";
    }

    cout << endl;
    Record *temp;
    auto it = R->recs.begin();

    for (int i = 0; i < R->nrecs; i++)
    {
        temp = *it;
        for (int j = 0; j < R->natttr; j++)
        {
            if (R->attrinds[j] == 0)
            {
                cout << "| " << static_cast<integerAttribute *>(temp->attrptr.at(j))->get_data() << " |";
            }

            if (R->attrinds[j] == 1)
            {
                cout << "| " << static_cast<floatAttribute *>(temp->attrptr.at(j))->get_data() << " |";
            }

            if (R->attrinds[j] == 2)
            {
                cout << "| " << static_cast<stringAttribute *>(temp->attrptr.at(j))->get_data() << " |";
            }
        }

        cout << endl;
        it++;
    }
}

void get1idx(int &a, vector<Relation *> Rlist)
{
    a = -1;
    while (a < 0 || a >= (int)Rlist.size())
    {
        cin >> a;
        if (a < 0 || a >= (int)Rlist.size())
        {
            cout << "Please enter valid index:" << endl;
        }
    }
}

void get2idx(int &a, int &b, vector<Relation *> Rlist)
{
    a = -1;
    b = -1;
    while (a < 0 || a >= (int)Rlist.size() || b < 0 || b >= (int)Rlist.size())
    {
        cin >> a >> b;
        if (a < 0 || a >= (int)Rlist.size() || b < 0 || b >= (int)Rlist.size())
        {
            cout << "Please enter valid index:" << endl;
        }
    }
}

list<string> get_common_attr(Relation *R1, Relation *R2)
{
    bool ex_flag;
    list<string> attrstr;

    for (auto name : R1->attrnames)
    {
        ex_flag = 0;
        for (auto name2 : R2->attrnames)
        {
            if (name == name2)
            {
                ex_flag = 1;
            }
        }
        if (ex_flag)
            attrstr.push_back(name);
    }
    return attrstr;
}

// main function to Implement the UI
int main()
{
    vector<Relation *> Rlist;
    int key = 0, key2;
    int temp;
    int idx1, idx2, keep, count;
    list<string> param;
    string inp, inp2;
    Relation *Rnew1, *Rnew2, *Rnew3, *Rnew4, *Rnew5, *Rnew6, *Rnew7;
    while (key != -1)
    {
        key = show_menu(Rlist);
        switch (key)
        {
        case 1:
            new_relation(Rlist);
            break;
        case 2:
            cout << "Enter Relation index to delete:" << endl;
            get1idx(temp, Rlist);
            Rlist.erase(Rlist.begin() + temp);
            break;
        case 3:
            cout << "Enter Relation index to add new Record:" << endl;
            get1idx(temp, Rlist);
            add_record(Rlist[temp]);
            break;
        case 4:
            cout << "Enter Relation index to display:" << endl;
            get1idx(temp, Rlist);
            display(Rlist[temp]);
            break;
        case 5:
        {
            key2 = do_operations();
            switch (key2)
            {
            case 1:
                cout << "Enter Relation indices for Union operation:(separated by space)" << endl;
                get2idx(idx1, idx2, Rlist);
                Rnew1 = union_(Rlist[idx1], Rlist[idx2]);
                if (Rnew1)
                {
                    cout << "Union:" << endl;
                    display(Rnew1);
                    cout << "Enter 1 to append the new relation to list of stored relation. Enter 0 to discard" << endl;
                    cin >> keep;
                    if (keep == 1)
                        Rlist.push_back(Rnew1);
                }
                break;
            case 2:
                cout << "Enter Relation indices for Difference operation:(separated by space)" << endl;
                get2idx(idx1, idx2, Rlist);
                Rnew2 = difference(Rlist[idx1], Rlist[idx2]);
                if (Rnew2)
                {
                    cout << "Difference:" << endl;
                    display(Rnew2);
                    cout << "Enter 1 to append the new relation to list of stored relation. Enter 0 to discard" << endl;
                    cin >> keep;
                    if (keep == 1)
                        Rlist.push_back(Rnew2);
                }
                break;
            case 3:
                cout << "Enter Relation indices for Cartesian Product operation:(separated by space)" << endl;
                get2idx(idx1, idx2, Rlist);
                Rnew3 = cartesianproduct(Rlist[idx1], Rlist[idx2]);
                if (Rnew3)
                {
                    cout << "Cartesian Product:" << endl;
                    display(Rnew3);
                    cout << "Enter 1 to append the new relation to list of stored relation. Enter 0 to discard" << endl;
                    cin >> keep;
                    if (keep == 1)
                        Rlist.push_back(Rnew3);
                }
                break;
            case 4:
                cout << "Enter Relation index for Projection operation:" << endl;
                get1idx(idx1, Rlist);
                display_attr(Rlist[idx1]);
                cout << "Enter how many attributes to take projection with:" << endl;
                cin >> count;
                param.clear();
                for (int j = 0; j < count; j++)
                {
                    cout << "Enter " << j << " attribute name:" << endl;
                    cin >> inp;
                    param.push_back(inp);
                }
                Rnew4 = Rlist[idx1]->projection(param);
                if (Rnew4)
                {
                    cout << "Projection:" << endl;
                    display(Rnew4);
                    cout << "Enter 1 to append the new relation to list of stored relation. Enter 0 to discard" << endl;
                    cin >> keep;
                    if (keep == 1)
                        Rlist.push_back(Rnew4);
                }
                break;
            case 5:
                cout << "Enter Relation index for Selection operation:" << endl;
                get1idx(idx1, Rlist);
                display_attr(Rlist[idx1]);
                Rnew5 = do_selection(Rlist[idx1]);
                if (Rnew5)
                {
                    cout << "Selection:" << endl;
                    display(Rnew5);
                    cout << "Enter 1 to append the new relation to list of stored relation. Enter 0 to discard" << endl;
                    cin >> keep;
                    if (keep == 1)
                        Rlist.push_back(Rnew5);
                }
                break;
            case 6:
                cout << "Enter Relation index for Rename operation:" << endl;
                get1idx(idx1, Rlist);
                display_attr(Rlist[idx1]);
                cout << "Enter attribute name to replace:" << endl;
                cin >> inp;
                cout << "Enter attribute name to replace with:" << endl;
                cin >> inp2;
                Rnew6 = Rlist[idx1]->rename(inp, inp2);
                if (Rnew6)
                {
                    cout << "Rename:" << endl;
                    display(Rnew6);
                    cout << "Enter 1 to append the new relation to list of stored relation. Enter 0 to discard" << endl;
                    cin >> keep;
                    if (keep == 1)
                        Rlist.push_back(Rnew6);
                }
                break;
            case 7:
                cout << "Enter Relation indices for Natural Join operation:(separated by space)" << endl;
                get2idx(idx1, idx2, Rlist);
                cout << "For 1st Relation" << endl;
                display_attr(Rlist[idx1]);
                cout << "For 2nd Relation" << endl;
                display_attr(Rlist[idx2]);
                cout << "Enter number of attributes on which to perform nautural join:(Enter -1 to use all the common attributes)" << endl;
                cin >> temp;
                list<string> attrstr;
                if (temp == -1)
                {
                    attrstr = get_common_attr(Rlist[idx1], Rlist[idx2]);
                }
                else
                {

                    for (int i = 0; i < temp; i++)
                    {
                        cout << "Enter " << i + 1 << " attribute name to perform natural join" << endl;
                        cin >> inp;
                        attrstr.push_back(inp);
                    }
                }
                Rnew7 = naturaljoin(Rlist[idx1], Rlist[idx2], attrstr);
                if (Rnew7)
                {
                    cout << "Natural Join:" << endl;
                    display(Rnew7);
                    cout << "Enter 1 to append the new relation to list of stored relation. Enter 0 to discard" << endl;
                    cin >> keep;
                    if (keep == 1)
                        Rlist.push_back(Rnew7);
                }
                break;
            }
        }

        default:
            break;
        }
    }
}