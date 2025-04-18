#include "headers.h"
extern char my_home_dir[4097];
extern char previous_dir[4097];
char* generate_absolute_address(const char original_address[])
{
    char cwd1[4097];
    getcwd(cwd1, sizeof(cwd1));

    char *to_return = (char *)malloc(sizeof(char) * (3+strlen(original_address)+strlen(cwd1)));
    int curr_index = 0;
    for (int i = 0; i < strlen(cwd1); i++)
    {
        to_return[curr_index] = cwd1[i];
        curr_index++;
    }
    to_return[curr_index] = '/';
    curr_index++;
    for (int i = 0; i < strlen(original_address); i++)
    {
        to_return[curr_index] = original_address[i];
        curr_index++;
    }
    to_return[curr_index] = '\0';
    return to_return;
}