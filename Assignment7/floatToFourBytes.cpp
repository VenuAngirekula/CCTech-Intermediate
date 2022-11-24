#include <iostream>
#include <cassert>
#include "FourByteConvertor.h"

void printfunc(float f)
{
    int *b ;
    b = FourByteConvertor(f);
    cout << "{" ;
    for (int i = 0; i < 4; i++)
        cout << *(b+i) << ", " ;

    cout << "}" ;
}

bool TestingFunction(float f, int Ans[])
{
    
    int *b ;
    b = FourByteConvertor(f);
    for (int i = 0; i < 4; i++)
    {
        if (*(b+i) != Ans[i])
        {
            return false;
        }
        
    }
    cout << "Passed" << endl;
    return true;
}

int main(int argc, char const *argv[])
{
    cout << "Testcase 1" << "   ";
    int Ans[4] = {65, 44, 0, 0};
    assert( TestingFunction(10.75,Ans) );


    cout << "Testcase 2" << "   ";
    int Ans2[4] = {130, 116, 0, 0};
    assert( TestingFunction(12.5,Ans2) );

    return 0;
}
