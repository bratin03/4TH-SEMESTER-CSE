/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Deparment of Computer Science and Engineering
    * Indian Institue of Technology, Kharagpur
*/

#include <bits/stdc++.h>
#include "rdb.h"
using namespace std;

// defining overloading of comparsion operators of theree derived class for integer , string and float

bool integerAttribute::operator==(const Attr &right)
{
    const integerAttribute *rhs = dynamic_cast<const integerAttribute *>(&right);
    if (element == rhs->element)
    {
        return true;
    }
    return false;
}

bool integerAttribute::operator!=(const Attr &right)
{
    const integerAttribute *rhs = dynamic_cast<const integerAttribute *>(&right);
    if (element != rhs->element)
    {
        return true;
    }
    return false;
}

bool integerAttribute::operator<(const Attr &right)
{
    const integerAttribute *rhs = dynamic_cast<const integerAttribute *>(&right);
    if (element < rhs->element)
    {
        return true;
    }
    return false;
}

bool integerAttribute::operator<=(const Attr &right)
{
    const integerAttribute *rhs = dynamic_cast<const integerAttribute *>(&right);
    if (element <= rhs->element)
    {
        return true;
    }
    return false;
}

bool integerAttribute::operator>(const Attr &right)
{
    const integerAttribute *rhs = dynamic_cast<const integerAttribute *>(&right);
    if (element > rhs->element)
    {
        return true;
    }
    return false;
}

bool integerAttribute::operator>=(const Attr &right)
{
    const integerAttribute *rhs = dynamic_cast<const integerAttribute *>(&right);
    if (element >= rhs->element)
    {
        return true;
    }
    return false;
}

bool floatAttribute::operator==(const Attr &right)
{
    const floatAttribute *rhs = dynamic_cast<const floatAttribute *>(&right);
    if (element == rhs->element)
    {
        return true;
    }
    return false;
}

bool floatAttribute::operator!=(const Attr &right)
{
    const floatAttribute *rhs = dynamic_cast<const floatAttribute *>(&right);
    if (element != rhs->element)
    {
        return true;
    }
    return false;
}

bool floatAttribute::operator<(const Attr &right)
{
    const floatAttribute *rhs = dynamic_cast<const floatAttribute *>(&right);
    if (element < rhs->element)
    {
        return true;
    }
    return false;
}

bool floatAttribute::operator<=(const Attr &right)
{
    const floatAttribute *rhs = dynamic_cast<const floatAttribute *>(&right);
    if (element <= rhs->element)
    {
        return true;
    }
    return false;
}

bool floatAttribute::operator>(const Attr &right)
{
    const floatAttribute *rhs = dynamic_cast<const floatAttribute *>(&right);
    if (element > rhs->element)
    {
        return true;
    }
    return false;
}

bool floatAttribute::operator>=(const Attr &right)
{
    const floatAttribute *rhs = dynamic_cast<const floatAttribute *>(&right);
    if (element >= rhs->element)
    {
        return true;
    }
    return false;
}

bool stringAttribute ::operator==(const Attr &right)
{
    const stringAttribute *rhs = dynamic_cast<const stringAttribute *>(&right);
    if (element == rhs->element)
    {
        return true;
    }
    return false;
}

bool stringAttribute ::operator!=(const Attr &right)
{
    const stringAttribute *rhs = dynamic_cast<const stringAttribute *>(&right);
    if (element != rhs->element)
    {
        return true;
    }
    return false;
}

bool stringAttribute ::operator<(const Attr &right)
{
    const stringAttribute *rhs = dynamic_cast<const stringAttribute *>(&right);
    if (element < rhs->element)
    {
        return true;
    }
    return false;
}

bool stringAttribute ::operator<=(const Attr &right)
{
    const stringAttribute *rhs = dynamic_cast<const stringAttribute *>(&right);
    if (element <= rhs->element)
    {
        return true;
    }
    return false;
}

bool stringAttribute ::operator>(const Attr &right)
{
    const stringAttribute *rhs = dynamic_cast<const stringAttribute *>(&right);
    if (element > rhs->element)
    {
        return true;
    }
    return false;
}

bool stringAttribute ::operator>=(const Attr &right)
{
    const stringAttribute *rhs = dynamic_cast<const stringAttribute *>(&right);
    if (element >= rhs->element)
    {
        return true;
    }
    return false;
}
