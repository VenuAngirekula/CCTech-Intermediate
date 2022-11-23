#include <iostream>
#include <cmath>
#include <climits>
#include <cassert>

bool closedtoNumber(int Number, int A[], int checkNum)
{
    int FinalNumber, diff;
    int minDiff = INT_MAX;
    for (int i = 0; i < sizeof(A); i++)
    {
        diff = abs( A[i] - Number );
        if (diff < minDiff)
        {
            minDiff = diff;
            FinalNumber = A[i];
        }
        else if ( diff == minDiff)
        {
            if (A[i] > 0)
            {
                FinalNumber = A[i];
            }
        }
        else
        {
        }
    }
    
    if (checkNum == FinalNumber)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

int main(int argc, char const *argv[])
{
    // closedtoNumber(TargetNumber, List, Answer);
    int A[] = {10,5,1,-2,-1,6,8,9,120};
    assert(closedtoNumber(0, A, 1));

    int B[] = {10,5,2,-2,6,8,9,120};
    assert(closedtoNumber(0, B, 2));

    return 0;
}