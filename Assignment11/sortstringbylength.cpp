
#include "sortstringbylength.h"

void sortstringbylength(std::vector< std::pair<int,std::string> > stringbin)
{
    std::cout << "Strings after sorting:" << std::endl;
    std::sort(stringbin.begin(), stringbin.end());
    for (std::vector< std::pair<int,std::string> >::iterator it = stringbin.begin(); \
            it != stringbin.end(); it++)
    {
        std::pair<int, std::string> len_and_strings = *it ;
        std::cout << len_and_strings.second;
    }
    
}
