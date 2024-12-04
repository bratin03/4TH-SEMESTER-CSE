/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Deparment of Computer Science and Engineering
    * Indian Institue of Technology, Kharagpur
*/

#include <string>
#include <bits/stdc++.h>
using namespace std;

class Relation;
// Forward declaration
// Attr class with virtual fucntions
class Attr
{
public:
    Attr() {}
    virtual bool operator==(const Attr &right) = 0;
    virtual bool operator!=(const Attr &right) = 0;
    virtual bool operator<(const Attr &right) = 0;
    virtual bool operator<=(const Attr &right) = 0;
    virtual bool operator>(const Attr &right) = 0;
    virtual bool operator>=(const Attr &right) = 0;
};

// DNFformula struct to be used for selection opearation
struct DNFformula
{
    list<list<tuple<string, char, Attr *>>> ops;
};

// integerAttribute class to store integer entry in records
class integerAttribute : public Attr
{
private:
    int element;

public: // constructor
    integerAttribute(int element) : element(element) {}
    // operator overloading
    bool operator==(const Attr &right);
    bool operator!=(const Attr &right);
    bool operator<(const Attr &right);
    bool operator<=(const Attr &right);
    bool operator>(const Attr &right);
    bool operator>=(const Attr &right);
    // utility functions
    int get_data() { return element; }
    void set_data(int a) { element = a; }
};

// stringAttribute class to store integer entry in records
class stringAttribute : public Attr
{
private:
    string element;

public: // constructor
    stringAttribute(string element) : element(element) {}
    // operator overloading
    bool operator==(const Attr &right);
    bool operator!=(const Attr &right);
    bool operator<(const Attr &right);
    bool operator<=(const Attr &right);
    bool operator>(const Attr &right);
    bool operator>=(const Attr &right);
    // utility functions
    string get_data() { return element; }
    void set_data(string a) { element = a; }
};

// floatAttribute class to store integer entry in records
class floatAttribute : public Attr
{
private:
    float element;

public: // constructor
    floatAttribute(float element) : element(element) {}
    // operator overloading
    bool operator==(const Attr &right);
    bool operator!=(const Attr &right);
    bool operator<(const Attr &right);
    bool operator<=(const Attr &right);
    bool operator>(const Attr &right);
    bool operator>=(const Attr &right);
    // utility functions
    float get_data() { return element; }
    void set_data(float a) { element = a; }
};

// Record class to store records
class Record
{
private:
    vector<Attr *> attrptr;

public:
    // comparison operators
    bool operator==(const Record &right);
    bool operator!=(const Record &right);
    bool operator<(const Record &right);
    bool operator<=(const Record &right);
    bool operator>(const Record &right);
    bool operator>=(const Record &right);
    // push back function
    void attr_pb(Attr *a) { attrptr.push_back(a); }
    // friend function
    friend Record *append_rec(Record *a, Record *b);
    friend Relation *select_one(Relation *R1, list<tuple<string, char, Attr *>> a);
    friend void add_record(Relation *R);
    friend void display(Relation *R);
    friend list<string> get_common_attr(Relation *R1, Relation *R2);
    friend Relation *naturaljoin(Relation *, Relation *, list<string>);
    // friend class
    friend class Relation;
};

// Function to append 2 records
Record *append_rec(Record *, Record *);

// Relation class to store relations
class Relation
{
private:
    // data
    int natttr, nrecs;
    vector<string> attrnames;
    vector<int> attrinds;
    list<Record *> recs;
    // functions
public:
    // utility functions
    void set_nattr(int a) { natttr = a; }
    int get_nattr() { return natttr; }
    void set_nrecs(int a) { nrecs = a; }
    int get_nrecs() { return nrecs; }
    // Member functions
    Relation *projection(list<string> b);
    Relation *rename(string s1, string s2);
    // friend functions
    friend Relation *union_(Relation *, Relation *);
    friend Relation *difference(Relation *, Relation *);
    friend Relation *cartesianproduct(Relation *, Relation *);
    friend Relation *naturaljoin(Relation *, Relation *, list<string>);
    friend Relation *selection(Relation *R1, DNFformula *f);
    friend Relation *select_one(Relation *R1, list<tuple<string, char, Attr *>> a);
    friend void new_relation(vector<Relation *> &Rlist);
    friend void add_record(Relation *R);
    friend void display(Relation *R);
    friend list<string> get_common_attr(Relation *R1, Relation *R2);
    friend void display_attr(Relation *R);
    // friend class
    friend class Record;
};
