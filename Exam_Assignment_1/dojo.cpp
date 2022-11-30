#include <iostream>
#include <string>
#include <cassert>
#include <map>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "TestingFunction.h"

using namespace std;

std::map<std::string,std::array<int,2>> Read_testcases(std::string& Filename_Testcases);

int main(int argc, char const *argv[])
{
    /* Manual: Test cases used to develop the program */
    cout << "Testcase1: " ;
    string s = "Hiker.js"; std::array<int,2> Ans = {0,5};    
    assert(Testingfunction(s,Ans));

    cout << "Testcase2: " ;
    string s2 = "Hiker_tests.js"; std::array<int,2> Ans2 = {0,5};
    assert(Testingfunction(s2,Ans2));

    cout << "Testcase3: " ;
    string s3 = "Hiker_Tests.js"; std::array<int,2> Ans3 = {0,5};
    assert(Testingfunction(s3,Ans3));

    cout << "Testcase4: " ;
    string s4 = "Tests_Hiker.js"; std::array<int,2> Ans4 = {6,11};
    assert(Testingfunction(s4,Ans4));

    cout << "Testcase5: " ;
    string s5 = "src/test/lib/Tests_Hiker.js"; std::array<int,2> Ans5 = {19,24};   
    assert(Testingfunction(s5,Ans5));

    cout << "Testcase6: " ;
    string s6 = "hiker"; std::array<int,2> Ans6 = {0,5};      
    assert(Testingfunction(s6,Ans6));

    /* Automated : Using test cases provided Json file */
    cout << "\n********* Automated testing *********\n" << endl;
    std::string Filename_Testcases = "testcaselist";
    std::map<std::string,std::array<int,2>> testcases = Read_testcases(Filename_Testcases);

    map<std::string, std::array<int,2>>::iterator itr;
    int testind=1;
    for (itr = testcases.begin(); itr != testcases.end(); ++itr) 
    {
        cout << "Testcase" << testind << " :" ;    
        string s = itr->first; int Ans[2] = {4,9};    
        assert(Testingfunction(s,itr->second));
        testind++;
    }

    return 0;
}


std::map<std::string,std::array<int,2>> Read_testcases(std::string& Filename_Testcases)
{
    std::ifstream myfile (Filename_Testcases);
    std::string line, temp;
    int Ans[2];

    std::map<std::string,std::array<int,2>> testcases;

    while (std::getline(myfile, line))
    {
        int ind = line.find("[");
        if (ind != std::string::npos)
        {
            std::array<int,2> indices;
            int dummy;

            line.erase(std::remove(line.begin(), line.end(), '\"'), line.end());
            std::string fileName  = line.substr(0,line.find_last_of(": ")-1);
            std::string indexpart  = line.substr(line.find_last_of(": ")+1,-1);
            
            
            indexpart.erase(std::remove(indexpart.begin(), indexpart.end(), '['), indexpart.end());
            indexpart.erase(std::remove(indexpart.begin(), indexpart.end(), ']'), indexpart.end());
            indexpart = indexpart.substr(0,indexpart.find_last_of(","));

            std::string segment;
            stringstream ss(indexpart);
            int i = 0;
            while(getline(ss, segment, ','))
            {
                indices[i] = atoi(segment.c_str() );
                i++;
            } 
            testcases.insert(std::pair<std::string, std::array<int,2> > (fileName,indices));
       }      
    
    }
    return testcases;
}