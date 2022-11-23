#include <iostream>
#include <string>
#include <cassert>
using namespace std;

bool echo_withStrings(int count, string* b)
{
    if (count==0)
    {
        cout << "\n";
        return true;
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            cout << b[i] << "  ";    
        }
        
        return true;
    }
    return false;
}

bool echo_withCommandLine(int count, char const *b[])
{
    if (count==0)
    {
        cout << "\n";
        return true;
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            cout << b[i] << "  ";    
        }
        
        return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    // string a[] = {};
    // assert( echo_withStrings(sizeof(a)/sizeof(a[0]), a) );

    string c[] = {"foo", "bar"};
    assert( echo_withStrings(sizeof(c)/sizeof(c[0]), c) );
    
    // assert( echo_withCommandLine(argc, argv) );
    
    return 0;

}

