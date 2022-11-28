#include <iostream>
#include <cassert>
#include <cmath>
// #include <stdexcept>

using namespace std;

float get_squareRoot(float num)
{
    if (num < 0 )
    {
        throw(std::invalid_argument("Negative value passed into Sqrt function."));
    }
    
    return(sqrt(num));
}

bool testFunc(float Value, float Ans)
{
    double b;
    try
    {
        b = get_squareRoot(Value);

        if ( (b-Ans)<1e-38 )
        {
            cout << ": Passed" << endl;
            return true;
        }
        else
            return false;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
        
}

int main(int argc, char const *argv[])
{
    float f = 25;
    cout << "Testcase 1: ";
    assert( testFunc(f,5.0) );

    cout << "Testcase 2: ";
    float a = -25;
    assert( !testFunc(a,5.0) );

    cout << "Testcase 3: ";
    float a1 = 252154485.652254120012;
    assert( !testFunc(a1,5.0) );


    return 0;

    
}

