#include <iostream>
#include <cassert>

bool isPrimeNumber(int N)
{
    if (N <= 1)
    {
        return false;
    }
    
    for (int i = 2; i < N; i++)
    {
        if (N%i==0)
        {
            return false;
        }
        
    }
    
    return true;
}


int main(int argc, char const* argv[] )
{
    assert(!isPrimeNumber(-1));
    assert(!isPrimeNumber(0));
    assert(!isPrimeNumber(1));
    assert(isPrimeNumber(2));
    assert(isPrimeNumber(3));
    assert(!isPrimeNumber(4));
    assert(isPrimeNumber(5));
    assert(!isPrimeNumber(102));
    assert(isPrimeNumber(499));
    assert(!isPrimeNumber(501));
    return 0;
}
