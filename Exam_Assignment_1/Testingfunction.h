#include <iostream>
#include <string>
#include "fileNameSelector.h"

bool Testingfunction(std::string& s, std::array<int,2> Ans)
{
    
    std::array<int, 2> p = fileNameSelector(s);

    if (Ans[0]==p[0] && Ans[1]==p[1]) 
    {
        std::cout << "Passed" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Failed" << std::endl;
        return false;
    }
}