#include "headers.h"

int isPrefix(char *str1, char *str2)
{
    int i = 0;
    while((str1[i] != '\0') && (str2[i] != '\0'))
    {
        if(str1[i] != str2[i])
        {
            return 0;
        }
        i++;
    }
    if (strlen(str1) > strlen(str2))
    {
        return 0;
    }
    else
    {
        return 1;
    }
        
}