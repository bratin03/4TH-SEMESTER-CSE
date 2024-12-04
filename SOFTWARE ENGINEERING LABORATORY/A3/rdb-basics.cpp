/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Deparment of Computer Science and Engineering
    * Indian Institue of Technology, Kharagpur
*/

#include <bits/stdc++.h>
#include "rdb.h"
using namespace std;

// overloading operators for record class
bool Record::operator==(const Record &right)
{
    auto it1 = attrptr.begin();
    auto it2 = right.attrptr.begin();
    bool flag = 1;

    while (it1 != attrptr.end() && it2 != right.attrptr.end())
    {
        if (*(*it1) != *(*it2))
        {
            flag = 0;
            return false;
        }
        it1++;
        it2++;
    }

    if (flag)
        return true;
    return false;
}

bool Record::operator!=(const Record &right)
{
    auto it1 = attrptr.begin();
    auto it2 = right.attrptr.begin();
    bool flag = 1;

    while (it1 != attrptr.end() && it2 != right.attrptr.end())
    {
        if (*(*it1) != *(*it2))
        {
            flag = 0;
            return true;
        }
        it1++;
        it2++;
    }

    if (flag)
        return false;
    return true;
}

bool Record::operator<(const Record &right)
{
    auto it1 = attrptr.begin();
    auto it2 = right.attrptr.begin();
    bool flag = 1;

    while (it1 != attrptr.end() && it2 != right.attrptr.end())
    {
        if (*(*it1) >= *(*it2))
        {
            flag = 0;
            return false;
        }
        it1++;
        it2++;
    }

    if (flag)
        return true;
    return false;
}

bool Record::operator<=(const Record &right)
{
    auto it1 = attrptr.begin();
    auto it2 = right.attrptr.begin();
    bool flag = 1;

    while (it1 != attrptr.end() && it2 != right.attrptr.end())
    {
        if (*(*it1) > *(*it2))
        {
            flag = 0;
            return false;
        }
        it1++;
        it2++;
    }

    if (flag)
        return true;
    return false;
}

bool Record::operator>(const Record &right)
{
    auto it1 = attrptr.begin();
    auto it2 = right.attrptr.begin();
    bool flag = 1;

    while (it1 != attrptr.end() && it2 != right.attrptr.end())
    {
        if (*(*it1) <= *(*it2))
        {
            flag = 0;
            return false;
        }
        it1++;
        it2++;
    }

    if (flag)
        return true;
    return false;
}

bool Record::operator>=(const Record &right)
{
    auto it1 = attrptr.begin();
    auto it2 = right.attrptr.begin();
    bool flag = 1;

    while (it1 != attrptr.end() && it2 != right.attrptr.end())
    {
        if (*(*it1) < *(*it2))
        {
            flag = 0;
            return false;
        }
        it1++;
        it2++;
    }

    if (flag)
        return true;
    return false;
}

// Function to append 2 records
Record *append_rec(Record *a, Record *b)
{
    Record *r3 = new Record();

    for (auto a1 : a->attrptr)
    {
        r3->attr_pb(a1);
    }

    for (auto b1 : b->attrptr)
    {
        r3->attr_pb(b1);
    }

    return r3;
}

// Union Operation
Relation *union_(Relation *R1, Relation *R2)
{
    if (R1->natttr != R2->natttr)
    {
        cout << "Error: Incomaptible Relations." << endl;
        return NULL;
    }

    for (int i = 0; i < R1->natttr; i++)
    {
        if (R1->attrinds[i] != R2->attrinds[i])
        {
            cout << "Error: Incomaptible Relations." << endl;
            return NULL;
        }
    }

    // Copying records from R1
    Relation *R = new Relation();
    R->natttr = R1->natttr;
    R->nrecs = R1->nrecs;
    R->attrnames = R1->attrnames;
    R->attrinds = R1->attrinds;
    R->recs = R1->recs;

    // copying new records from R2 avoiding duplicate copying
    bool flag;

    for (auto rec : R2->recs)
    {
        flag = 1;
        for (auto exist : R1->recs)
        {
            if (*rec == *exist)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            R->recs.push_back(rec);
            R->nrecs++;
        }
    }

    return R;
}

// Difference Operation
Relation *difference(Relation *R1, Relation *R2)
{
    if (R1->natttr != R2->natttr)
    {
        cout << "Error: Incomaptible Relations." << endl;
        return NULL;
    }

    for (int i = 0; i < R1->natttr; i++)
    {
        if (R1->attrinds[i] != R2->attrinds[i])
        {
            cout << "Error: Incomaptible Relations." << endl;
            return NULL;
        }
    }

    Relation *R = new Relation();
    R->natttr = R1->natttr;
    R->attrnames = R1->attrnames;
    R->attrinds = R1->attrinds;
    R->nrecs = 0;
    // copying records from R1 that don't exist in R2
    bool flag;

    for (auto rec : R1->recs)
    {
        flag = 1;
        for (auto exist : R2->recs)
        {
            if (*rec == *exist)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            R->recs.push_back(rec);
            R->nrecs++;
        }
    }

    return R;
}

// Cartesian Product Operation
Relation *cartesianproduct(Relation *R1, Relation *R2)
{
    Relation *R = new Relation();
    R->natttr = R1->natttr + R2->natttr;
    R->nrecs = (R1->nrecs) * (R2->nrecs);
    R->attrnames = R1->attrnames;
    R->attrinds = R1->attrinds;

    // Adding all possible pair of records after appending
    for (auto attr : R2->attrnames)
    {
        R->attrnames.push_back(attr);
    }

    for (auto attri : R2->attrinds)
    {
        R->attrinds.push_back(attri);
    }

    for (auto r1 : R1->recs)
    {
        for (auto r2 : R2->recs)
        {
            Record *R3 = append_rec(r1, r2);
            R->recs.push_back(R3);
        }
    }

    return R;
}

// Projection Operation
Relation *Relation::projection(list<string> projectattrs)
{
    Relation *R = new Relation();
    R->natttr = projectattrs.size();
    R->nrecs = 0;
    int indices[projectattrs.size()];
    int i = 0;
    // finding out the index of attributes to include in final result
    vector<string>::iterator it;
    list<string>::iterator it2 = projectattrs.begin();

    for (int j = 0; j < (int)projectattrs.size(); j++, it2++)
    {
        it = find(attrnames.begin(), attrnames.end(), *it2);
        indices[i++] = (int)(it - attrnames.begin());
    }

    sort(indices, indices + projectattrs.size());

    for (i = 0; i < (int)projectattrs.size(); i++)
    {
        R->attrnames.push_back(attrnames.at(indices[i]));
        R->attrinds.push_back(attrinds.at(indices[i]));
    }
    // creating new records with selected attributes
    // adding them to relation avoiding duplicate copy
    bool flag;

    for (auto rec : recs)
    {
        Record *newr = new Record;
        for (int i = 0; i < (int)projectattrs.size(); i++)
        {
            newr->attr_pb(rec->attrptr[indices[i]]);
        }
        flag = 1;
        for (auto exist : R->recs)
        {
            if (*newr == *exist)
            {
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

    return R;
}

// Rename Operation
Relation *Relation::rename(string s1, string s2)
{ // Renaming an attribute
    Relation *R1 = new Relation();
    R1->natttr = natttr;
    R1->nrecs = nrecs;
    R1->attrnames = attrnames;
    R1->attrinds = attrinds;
    R1->recs = recs;
    vector<string>::iterator it;
    it = find(R1->attrnames.begin(), R1->attrnames.end(), s1);
    *it = s2;
    return R1;
}

// Utility function to be used for Selection Operation
Relation *select_one(Relation *R1, list<tuple<string, char, Attr *>> a)
{
    // Taking each CNF form of logic and returning respective
    Relation *R = new Relation;
    R->natttr = R1->natttr;
    R->nrecs = 0;
    R->attrnames = R1->attrnames;
    R->attrinds = R1->attrinds;
    string str;
    char comp;
    bool flag;
    vector<int> idxes;
    vector<char> comp_op;
    vector<string>::iterator it;
    vector<Attr *> attrs;
    int count = 0;

    for (auto cond : a)
    {
        str = get<0>(cond);
        comp = get<1>(cond);
        it = find(R1->attrnames.begin(), R1->attrnames.end(), str);
        idxes.push_back((int)(it - R1->attrnames.begin()));
        comp_op.push_back(comp);
        attrs.push_back(get<2>(cond));
        count++;
    }

    for (auto rec : R1->recs)
    {
        flag = 1;
        for (int i = 0; i < count; i++)
        {

            if (comp_op[i] == '=')
            {

                if ((*(rec->attrptr[idxes[i]])) != *attrs[i])
                {
                    flag = 0;
                    break;
                }
            }
            if (comp_op[i] == '>')
            {
                if ((*(rec->attrptr[idxes[i]])) <= *attrs[i])
                {
                    flag = 0;
                }
            }
            if (comp_op[i] == '<')
            {
                if ((*(rec->attrptr[idxes[i]])) >= *attrs[i])
                {
                    flag = 0;
                }
            }
            if (comp_op[i] == '!')
            {
                if ((*(rec->attrptr[idxes[i]])) == *attrs[i])
                {
                    flag = 0;
                }
            }
        }

        if (flag)
        {
            R->recs.push_back(rec);
            R->nrecs++;
        }
    }

    return R;
}

Relation *selection(Relation *R1, DNFformula *f)
{ // Sending every CNF form to utility function select_one and taking union of them to get DNF
    Relation *result1 = NULL, *result2 = NULL;
    int rkey = 1;
    list<list<tuple<string, char, Attr *>>> listed = f->ops;

    for (auto element : listed)
    {
        Relation *Rn = select_one(R1, element);

        if (rkey == 1)
        {
            if (!result2)
            {
                result1 = Rn;
            }
            else
                result1 = union_(result2, Rn);
            rkey = 2;
        }
        else if (rkey == 2)
        {
            if (!result1)
            {
                result2 = Rn;
            }
            else
                result2 = union_(result1, Rn);
            rkey = 1;
        }
    }

    if (rkey == 1)
        return result2;
    else
        return result1;
}