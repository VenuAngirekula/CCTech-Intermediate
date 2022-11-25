#include <string>
#include <typeinfo>
#include <float.h>
#include "utilities.h"


using namespace std;

template <typename T, typename U>
bool Testfunc(string funName, T a, T b, U checkvalue)
{
    // Get min and max value based on the datatype
    T highestValue, lowestValue;

    if (typeid(a) == typeid(int))
    {
        highestValue = INT_MAX;  lowestValue = INT_MIN; 
    }
    else if (typeid(a) == typeid(unsigned int))
    {
        highestValue = UINT_MAX;  lowestValue = 0; 
    }
    else if (typeid(a) == typeid(float))
    {
        highestValue = FLT_MAX;  lowestValue = -FLT_MAX;
    }
    else if (typeid(a) == typeid(double))
    {
        highestValue = DBL_MAX;  lowestValue = -DBL_MAX;
    }
    else
    {
        throw("Error: Calculator accepts only int, unsigned int and float data types.");
    }

    // check the operation
    if (funName == "add")
    {
        if ((checkvalue - add(a,b,highestValue, lowestValue)) < 1e-38)
            { cout << " : Passed" << endl;   return true; }
        else
            return false;
    }
    else if (funName == "sub")
    {
        if ((checkvalue-sub(a,b,highestValue, lowestValue) < 1e-38))
            { cout << " : Passed" << endl;   return true; }
        else
            return false;
    }

    else if (funName == "mul")
    {
        if ((checkvalue-mul(a,b,highestValue, lowestValue) < 1e-38))
            { cout << " : Passed" << endl;   return true; }
        else
            return false;
    }

    else if (funName == "Div")
    {
        if ((checkvalue-Div(a,b) < 1e-38))
            { cout << " : Passed" << endl;   return true; }
        else
            return false;
    }    
}