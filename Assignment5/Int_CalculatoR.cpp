#include <iostream>
#include <cassert>
#include <typeinfo>
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
    else
    {
        highestValue = UINT_MAX;  lowestValue = 0; 
    }

    // check the operation
    if (funName == "add")
    {
        if (checkvalue == add(a,b,highestValue, lowestValue))
            return true;
        else
            return false;
    }
    else if (funName == "sub")
    {
        if (checkvalue==sub(a,b,highestValue, lowestValue))
            return true;
        else
            return false;
    }

    else if (funName == "mul")
    {
        if (checkvalue==mul(a,b,highestValue, lowestValue))
            return true;
        else
            return false;
    }

    else if (funName == "Div")
    {
        if (checkvalue==Div(a,b))
            return true;
        else
            return false;
    }    
}

int main(int argc, char const *argv[])
{
   
    // ****** Addition test cases  ****** //
    cout << "Testcase 1" << endl;
    int a = 2147483647; int b = 10; int c = 2147483657;
    assert(!Testfunc("add", a, b, c) );

    cout << "Testcase 2" << endl;
    int a6 = -2147483647, b6 = 10, c6 = -2147483637;
    assert(Testfunc("add", a6, b6, c6) );

    cout << "Testcase 3" << endl;
    int a7 = 2147483637, b7 = 10, c7 = 2147483647;
    assert(Testfunc("add", a7, b7, c7) );
    
    cout << "Testcase 4" << endl;
    unsigned int a2 = 4294967295, b2 = 10; unsigned long int c2 = 4294967305;
    assert(!Testfunc("add", a2, b2, c2) );

    cout << "Testcase 5" << endl;
    unsigned int a3 = 4294967285, b3 = 10, c3 = 4294967295;
    assert(Testfunc("add", a3, b3, c3) );


    // ****** Subtraction test cases   ****** //
    cout << "Testcase 6" << endl;
    int a4 = -2147483638, b4 = 10, c4 = -2147483648;
    assert(Testfunc("sub", a4, b4, c4) );

    cout << "Testcase 7" << endl;
    int a5 = -2147483638, b5 = 11; long int c5 = -2147483648;
    assert(!Testfunc("sub", a5, b5, c5) );

    cout << "Testcase 8" << endl;
    int a8  = 2147483647, b8 = -1; long int c8 = 2147483648;
    assert(!Testfunc("sub", a8, b8, c8) );

    cout << "Testcase 9" << endl;
    int a9  = 2147483636, b9 = -1; long int c9 = 2147483637;
    assert(Testfunc("sub", a9, b9, c9) );

    cout << "Testcase 10" << endl;
    int a10  = -2147483648, b10 = -10; long int c10 = -2147483638;
    assert(Testfunc("sub", a10, b10, c10) );

    cout << "Testcase 11" << endl;
    unsigned int a11  = 2, b11 = 4; int c11 = -1;
    assert(!Testfunc("sub", a11, b11, c11) ); 

    // ****** Multiplication test cases   ****** //
    // int
//// OUTOF RANGE - Same sign
    cout << "Testcase 12" << endl;
    int a12  = -2147483648, b12 = -100; long int c12 = 21474836480;
    assert(!Testfunc("mul", a12, b12, c12) );
    cout << "Testcase 13" << endl;
    int a13  = 2147483647, b13 = 1000; long int c13 = 21474836470;
    assert(!Testfunc("mul", a13, b13, c13) );
//// IN RANGE - Same sign
    cout << "Testcase 14" << endl;
    int a14  = -89550, b14 = -10; int c14 = 895500;
    assert(Testfunc("mul", a14, b14, c14) );
    cout << "Testcase 15" << endl;
    int a15  = 202, b15 = 10; int c15 = 2020;
    assert(Testfunc("mul", a15, b15, c15) );

//// OUTOF RANGE - diff sign
    cout << "Testcase 16" << endl;
    int a16  = -2147483648, b16 = 22; long int c16 = -47244640256;
    assert(!Testfunc("mul", a16, b16, c16) );
    cout << "Testcase 17" << endl;
    int a17  = 2147483648, b17 = -22; long int c17 = -47244640256;
    assert(!Testfunc("mul", a17, b17, c17) );

//// IN RANGE - diff sign
    cout << "Testcase 18" << endl;
    int a18  = -5658552, b18 = 10; int c18 = -56585520;
    cout << "Testcase 19" << endl;
    assert(Testfunc("mul", a18, b18, c18) );
    int a19  = 5658552, b19 = -10; int c19 = -56585520;
    assert(Testfunc("mul", a19, b19, c19) ); 

    // signed int
//// OUTOF RANGE 
    cout << "Testcase 20" << endl;
    unsigned int a20  = 4294967295, b20 = 10; unsigned long int c20 = 42949672960;
    assert(!Testfunc("mul", a20, b20, c20) );

    cout << "Testcase 21" << endl;
    unsigned int a21  = 10, b21 = 4294967295; unsigned long int c21 = 42949672960;
    assert(!Testfunc("mul", a21, b21, c21) );

    cout << "Testcase 22" << endl;
    unsigned int a22  = 100, b22 = 1000; unsigned int c22 = 100000;
    assert(Testfunc("mul", a22, b22, c22) );

    cout << "Testcase 23" << endl;
    unsigned int a23  = 2500, b23 = 63; unsigned int c23 = 157500;
    assert(Testfunc("mul", a23, b23, c23) );
    
    // ****** Division test cases ****** //
    cout << "Testcase 24" << endl;
    int a24  = -2147483648, b24 = -50; int c24 = 42949672;
    assert(Testfunc("Div", a24, b24, c24) );

    cout << "Testcase 25" << endl;
    int a25  = 2147483647, b25 = 50; int c25 = 42949672;
    assert(Testfunc("Div", a25, b25, c25) );

    cout << "Testcase 26" << endl;
    int a26  = 50, b26 = 2147483647; int c26 = 0;
    assert(Testfunc("Div", a26, b26, c26) );
    cout << "Testcase 26" << endl;

    cout << "Testcase 27" << endl;
    int a27  = -2147483648, b27 = 50; int c27 = -42949672;
    assert(Testfunc("Div", a27, b27, c27) );

    cout << "Testcase 28" << endl;
    unsigned int a28  = 4294967295, b28 = 0; unsigned int c28 = 42949672;
    assert(!Testfunc("Div", a28, b28, c28) );
    
    return 0;
}

