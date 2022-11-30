#include <string>
#include <algorithm>
#include <list>
#include <array>


std::list<std::string> get_checkwords();

std::array<int, 2> fileNameSelector(std::string& file_Name)
{
    std::string dotRemovedName, DirRemovedName;
    
    int index_of_dot = file_Name.find_last_of(".");
    dotRemovedName = file_Name.substr(0,index_of_dot);

    int index_of_slash = dotRemovedName.find_last_of("/");
    if (index_of_slash != std::string::npos)
    {
        DirRemovedName = dotRemovedName.substr(index_of_slash+1,-1);    
    }
    else
        DirRemovedName = dotRemovedName;
    
    std::list<std::string> checkwords = get_checkwords();

    std::list<std::string>::iterator it;
    for (it = checkwords.begin(); it != checkwords.end(); ++it)
    {
        std::string checkword = *it;
        std::string lowCase = DirRemovedName;
        std::transform(lowCase.begin(), lowCase.end(),
                    lowCase.begin(), ::tolower);

        std::size_t ind = lowCase.find(checkword);
        if (ind != std::string::npos)
        {
            DirRemovedName.erase(ind, checkword.length());
            break;
        }
    }    
    int start_Index = file_Name.find(DirRemovedName);
    int end_Index = start_Index + DirRemovedName.size();
    std::array<int,2> indices = {start_Index, end_Index};
    return indices;
}

std::list<std::string> get_checkwords()
{
    std::string keywords[3] = {"step","spec","test"};
    std::string sepCharacters[3] = {".","-","_"};
    std::list<std::string> Contaner;

    for (size_t i = 0; i < 3; i++)
    {        
        for (size_t j = 0; j < 3; j++)
        {
            Contaner.push_back(keywords[i]+"s"+sepCharacters[j]);
            Contaner.push_back(sepCharacters[j]+keywords[i]+"s");
        }
        Contaner.push_back(keywords[i]+"s");

        for (size_t j = 0; j < 3; j++)
        {
            Contaner.push_back(keywords[i]+sepCharacters[j]);
            Contaner.push_back(sepCharacters[j]+keywords[i]);
        }
        Contaner.push_back(keywords[i]);   
    }
    return Contaner;
}
    