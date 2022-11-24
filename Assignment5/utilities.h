#include <climits>
using namespace std;

template <class T> T add(T a, T b,T highestValue, T lowestValue)
{   

    if(a >= 0 ? b <= highestValue - a : b >= lowestValue - a)
        return (a+b);        
    else
        cout << "Results exceeds the Range of datatype" << endl;
        return false;
}

template <class T> T sub(T a, T b,T highestValue, T lowestValue)
{
    
    if (typeid(a) == typeid(int))
    {
        if (a > 0 ? b >= a - highestValue : b <= a - lowestValue )
            return (a-b);        
        else
            cout << "Results exceeds the Range of datatype" << endl;
        return false;
    }
    else
    {
        if (b <= a - lowestValue)
            return (a-b);        
        else
            cout << "Results exceeds the Range of datatype" << endl;
        return false;
    }
}

template <class T> T mul(T a, T b,T highestValue, T lowestValue)
{
  
    if( ( a<0 && b<0 ) && ((a >= highestValue/b ) || (b >= highestValue/a) ) ) 
    {
       return (a*b);
    }
    else if( (a>0 && b>0) && ((a <= highestValue/b ) || (b <= highestValue/a) ) )
    {
        return (a*b);
    }
    else if( (a<0 && b>0) && a >= lowestValue/b)
    {
        return (a*b);
    }
    else if( (a>0 && b<0) && a <= lowestValue/b)
    {
        return (a*b);
    }
    else
        cout << "     Results exceeds the Range of datatype" << endl;
        return false;
}

template <class T> T Div(T a, T b)
{
    if (b==0)
    {
        cout << "     Results NAN due 1/0 division" << endl;
        return false;
    }
    
    return (a/b);
}