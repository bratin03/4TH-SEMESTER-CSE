/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Deparment of Computer Science and Engineering
    * Indian Institue of Technology, Kharagpur
*/

#include <bits/stdc++.h>
#include "rdb.h"
using namespace std;

// Natural Join Operation
Relation *naturaljoin(Relation *R1, Relation *R2, list<string> joinattr)
{ // creating a new relation for cross product
    Relation *Rnew = new Relation;
    Rnew->natttr = R1->natttr + R2->natttr;
    Rnew->nrecs = 0;
    Rnew->attrnames = R1->attrnames;

    for (auto name : R2->attrnames)
    {
        Rnew->attrnames.push_back(name);
    }

    Rnew->attrinds = R1->attrinds;

    for (auto num : R2->attrinds)
    {
        Rnew->attrinds.push_back(num);
    }

    // In the newly created relation adding those product of records element which match in the attributes provided in join attr
    vector<int> idx1, idx2;
    vector<string>::iterator it2;

    for (auto it : joinattr)
    {
        it2 = find(R1->attrnames.begin(), R1->attrnames.end(), it);
        idx1.push_back((int)(it2 - R1->attrnames.begin()));
        it2 = find(R2->attrnames.begin(), R2->attrnames.end(), it);
        idx2.push_back((int)(it2 - R2->attrnames.begin()));
    }

    bool flag;

    for (auto rec : R1->recs)
    {
        for (auto rec2 : R2->recs)
        {
            flag = 1;
            for (int i = 0; i < (int)joinattr.size(); i++)
            {
                if (*(rec->attrptr[idx1[i]]) != *(rec2->attrptr[idx2[i]]))
                {
                    flag = 0;
                    break;
                }
                if (flag)
                {
                    Record *newr = append_rec(rec, rec2);
                    Rnew->recs.push_back(newr);
                    Rnew->nrecs++;
                }
            }
        }
    }

    // taking a projection for avoiding duplicate attribute name
    set<string> attrset;

    for (auto name : R1->attrnames)
    {
        attrset.insert(name);
    }

    for (auto name : R2->attrnames)
    {
        attrset.insert(name);
    }

    list<string> attrstr;
    for (auto name : attrset)
    {
        attrstr.push_back(name);
    }

    Relation *Rfinal = Rnew->projection(attrstr);
    return Rfinal;
}