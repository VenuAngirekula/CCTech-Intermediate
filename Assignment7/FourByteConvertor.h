#include <bitset>
#include <cmath>
using namespace std;


int * FourByteConvertor(float f)
{
    static int returnArray[4] = {0,0,0,0};
    int stringbitArray[32];

    std::bitset<32> bits(*reinterpret_cast<unsigned long*>(&f));
    std::string m = bits.to_string() ;

    int j = 0;
    for (int i = 0; i < m.length(); i++)
    {
        stringbitArray[i] = ( (int) m.at(i) ) -48;        

        if (stringbitArray[i]==1)
        {
            int Twopower = (7-(i+8)%8);
            returnArray[j] += pow(2,Twopower);   
        }    
        if ((i+1)%8 == 0)
            j++;
    }
    return returnArray;
}