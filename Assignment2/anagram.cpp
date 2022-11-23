#include <iostream>
#include <cassert>
#include <string>
#include <bits/stdc++.h>

using namespace std;

bool checkifAnagram(string Mainword, string Word)
{
    // generate anagrams
    string:: iterator it;
    int len1 = Mainword.length();
    int len2 = Word.length();
    if (len1 != len2)
    {
        return false;
    }
    sort(Mainword.begin(), Mainword.end());
    sort(Word.begin(), Word.end());

    if( Mainword.compare(Word) == 0)
        return true;
    else
        return false;
    
}


int main(int argc, char const *argv[])
{
    string Mainword = "brio";

    assert(!checkifAnagram(Mainword, "boirn"));
    assert(checkifAnagram(Mainword, "boir"));
    // assert(checkifAnagram(Mainword, "boi"));
    return 0;
}
