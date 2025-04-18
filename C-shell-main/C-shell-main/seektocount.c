#include "headers.h"
int seek_to_count(char target[], int string_length_of_base, int e, int f, int d)
{
    int tot = 0;
    char curr_directory_store[4097];
    getcwd(curr_directory_store, 4097);
    DIR *dir;
    dir = opendir(curr_directory_store);
    if (dir == NULL)
    {
        perror("Error:");
    }
    else
    {
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL)
        {
            /* code */
            if (entry->d_name[0] == '.')
            {
                continue;
            }

            if (isPrefix(target,entry->d_name) == 1)
            {
                // tot++;
                struct stat s1;
                stat(entry->d_name, &s1);
                if (S_ISDIR(s1.st_mode))
                {
                    if (f == 0)
                    {
                        tot++;
                    }
                }
                else
                {
                    /* code */
                    if (d == 0)
                    {
                        tot++;
                    }
                }

                // if(f==1)
                // {
                //     if(S_ISREG(s1.st_mode))
                //     {
                //         tot++;
                //     }
                // }
                // else if (d==1)
                // {
                //     if(S_ISDIR(s1.st_mode))
                //     {
                //         tot++;
                //     }
                // }
            }
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            {
                continue;
            }
            struct stat statbuf;
            stat(entry->d_name, &statbuf);
            if (S_ISDIR(statbuf.st_mode))
            {
                char new_dir[4097];
                chdir(entry->d_name);
                tot += seek_to_count(target, string_length_of_base, e, f, d);
                chdir(curr_directory_store);
            }
        }
    }

    return tot;
}