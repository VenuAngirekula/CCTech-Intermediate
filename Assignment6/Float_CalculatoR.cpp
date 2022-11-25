#include <iostream>
#include <cassert>
#include <bits/stdc++.h>
#include "testingFunction.h"

using namespace std;

int main(int argc, char const *argv[])
{
   
    // ****** Addition test cases  ****** //
    cout << "Testcase 1" ;
    float a = 2.0, b = 3.5, c = 5.5;
    assert(Testfunc("add", a, b, c) );

    cout << "Testcase 2" ;
    float a2 = -2.0, b2 = 3.5, c2 = 1.5;
    assert(Testfunc("add", a2, b2, c2) );

    cout << "Testcase 3" ;
    float a3 = -1.00002568, b3 = 2.00002451, c3 = 0.99999883;
    assert(Testfunc("add", a3, b3, c3) );
    
    cout << "Testcase 4" ;
    float a4 = 1.00058202568f, b4 = 2.000585502451f, c4 = 3.00116752813f;
    assert(Testfunc("add", a4, b4, c4) );


    cout << "Testcase 5" ;
    double a5 = 1.00058202568, b5 = 10.00, c5 = 11.00058202568;
    assert(Testfunc("add", a5, b5, c5) );


    // ****** Subtraction test cases   ****** //
    cout << "Testcase 6";
    float a6 = -2.14748320255638f, b6 = 5.125685f, c6 = -7.27316820256f;
    assert(!Testfunc("sub", a6, b6, c6) );

    cout << "Testcase 7";
    double a7 = -2147483638, b7 = 11, c7 = -2147483649;
    assert(Testfunc("sub", a7, b7, c7) );

//     cout << "Testcase 8" << endl;
//     int a8  = 2147483647, b8 = -1; long int c8 = 2147483648;
//     assert(!Testfunc("sub", a8, b8, c8) );

//     cout << "Testcase 9" << endl;
//     int a9  = 2147483636, b9 = -1; long int c9 = 2147483637;
//     assert(Testfunc("sub", a9, b9, c9) );

//     cout << "Testcase 10" << endl;
//     int a10  = -2147483648, b10 = -10; long int c10 = -2147483638;
//     assert(Testfunc("sub", a10, b10, c10) );

//     cout << "Testcase 11" << endl;
//     unsigned int a11  = 2, b11 = 4; int c11 = -1;
//     assert(!Testfunc("sub", a11, b11, c11) ); 

//     // ****** Multiplication test cases   ****** //

//     // signed int
// //// OUTOF RANGE 
    cout << "Testcase 20" ;
    double a20  = 4.294967295, b20 = 10, c20 = 42.94967295;
    assert(Testfunc("mul", a20, b20, c20) );

//     cout << "Testcase 21" << endl;
//     unsigned int a21  = 10, b21 = 4294967295; unsigned long int c21 = 42949672960;
//     assert(!Testfunc("mul", a21, b21, c21) );

//     cout << "Testcase 22" << endl;
//     unsigned int a22  = 100, b22 = 1000; unsigned int c22 = 100000;
//     assert(Testfunc("mul", a22, b22, c22) );

//     cout << "Testcase 23" << endl;
//     unsigned int a23  = 2500, b23 = 63; unsigned int c23 = 157500;
//     assert(Testfunc("mul", a23, b23, c23) );
    
//     // ****** Division test cases ****** //
    cout << "Testcase 24" ;
    double a24  = -2.147483648, b24 = -50,c24 = 0.04294967296;
    assert(Testfunc("Div", a24, b24, c24) );

//     cout << "Testcase 25" << endl;
//     int a25  = 2147483647, b25 = 50; int c25 = 42949672;
//     assert(Testfunc("Div", a25, b25, c25) );

//     cout << "Testcase 26" << endl;
//     int a26  = 50, b26 = 2147483647; int c26 = 0;
//     assert(Testfunc("Div", a26, b26, c26) );
//     cout << "Testcase 26" << endl;

//     cout << "Testcase 27" << endl;
//     int a27  = -2147483648, b27 = 50; int c27 = -42949672;
//     assert(Testfunc("Div", a27, b27, c27) );

//     cout << "Testcase 28" << endl;
//     unsigned int a28  = 4294967295, b28 = 0; unsigned int c28 = 42949672;
//     assert(!Testfunc("Div", a28, b28, c28) );
    
    return 0;
}

