#include <iostream>
#include <string>
#include <vector>

#include "sortstringbylength.h"

using namespace std;

int main(int argc, char const *argv[])
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    std::vector< std::pair<int,std::string> > stringbin;

    while ((nread = getline(&line, &len, stdin)) != -1) 
    {
        string stringLine = line;
        stringbin.push_back(std::make_pair(nread, stringLine));
    }

    sortstringbylength(stringbin);

    return 0;
}
