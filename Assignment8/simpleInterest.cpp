#include <iostream>
#include <cassert>
#include "utilities.h"

using namespace std;

bool TestFunc(simpleInterest a, float Ans )
{
    if(a.get_interest() == Ans)
    {
        cout << ": Passed "<< endl;
        return true;
    }
    else
        return false;
}

int main(int argc, char const *argv[])
{
    
    cout << "Testcase: 1";
    simpleInterest a(1000,5,1);
    assert( TestFunc( a,50 ) );

    cout << "Testcase: 2";
    simpleInterest a2(500,2.5,2);
    assert( TestFunc( a2,25 ) );
    
    cout << "Testcase: 3";
    simpleInterest a3(20000,5,2.5);   
    assert( TestFunc( a3,2500) );

    
    return 0;
}
