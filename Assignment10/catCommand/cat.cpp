#include <iostream>
#include <sys/stat.h>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

bool Is_Dir(const char *file)
{
    struct stat buf;
    stat(file, &buf);
    return S_ISDIR(buf.st_mode);
}

int main(int argc, char const *argv[])
{
    char c = 0;
    const char* programName = argv[0];

    if (argc==1)
    {
        while (1)
        {
            c = getchar();
            if (c==EOF)
                break;
            cout << c;
        }
    }
    for (int i = 1; i < argc; i++)
    {
        if(Is_Dir(argv[i]))
        {
           fprintf(stderr,"%s: %s: %s\n", programName, argv[i], strerror(EISDIR)); 
        }
        else
        {
                    FILE *fp = fopen(argv[i], "r");
                    if (fp==NULL)
                    {
                        fprintf(stderr,"%s: %s: %s\n", programName, argv[i], strerror(ENOENT)); 
                    }
                    else
                    {
                        while (1)
                        {
                            c = fgetc(fp);
                            if (c==EOF)
                                break;
                            cout << c;   
                        }       
                        fclose(fp) ;
                    }
        }
    }
    
    // else if (argc==2)
    // {   

    //     int i = 0;
    //     const char *fn = argv[1];
    //     FILE *fp = fopen(fn, "r");
    //     while (1)
    //     {
    //         c = fgetc(fp);
    //         if (c==EOF)
    //             break;
    //         cout << c;   
    //     }       
    //     fclose(fp) ;
    // }
    return 0;
}
