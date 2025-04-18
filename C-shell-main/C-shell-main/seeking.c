#include "headers.h"
extern char current_add_1011[4097];
extern char previous_dir[4097];
void seek(const char *file1, int length_of_base, int change_flag, int f, int d,int* occured)
{
    char curr_dir[4097];
    getcwd(curr_dir, sizeof(curr_dir));
    DIR *dir = opendir(curr_dir);
    if (dir == NULL)
    {
        perror("Error in seek");
        return;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_name[0] == '.')
        {
            continue;
        }
        if (isPrefix(file1,entry->d_name) == 1)
        {
            struct stat s1;
            stat(entry->d_name, &s1);
            if (S_ISDIR(s1.st_mode))
            {
                if ((f != 1) && (change_flag==0))
                {
                    printf(ANSI_COLOR_BLUE "." ANSI_COLOR_RESET);
                    for (int i = length_of_base; i < strlen(curr_dir); i++)
                    {
                        printf(ANSI_COLOR_BLUE "%c" ANSI_COLOR_RESET, curr_dir[i]);
                    }
                    printf(ANSI_COLOR_BLUE "/" ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_BLUE "%s\n" ANSI_COLOR_RESET, entry->d_name);
                }
                if (change_flag == 1)
                {
                    
                    if (!(s1.st_mode & S_IXUSR))
                    {
                        printf("Missing Permissions for task!\n");
                        return;
                    }
                    char new_address_to_go[strlen(curr_dir) + strlen(entry->d_name) + 2];
                    // printf("%s\n",new_address_to_go);
                    snprintf(new_address_to_go, sizeof(new_address_to_go), "%s/%s", curr_dir, entry->d_name);
                    *occured = 1;
                    // printf("%s\n", new_address_to_go);
                    strcpy(previous_dir, current_add_1011);
                    chdir(new_address_to_go);
                    return;
                }
            }
            else
            {
                // printf(ANSI_COLOR_GREEN"%s/"ANSI_COLOR_RESET, curr_dir);
                // printf(ANSI_COLOR_GREEN"%s\n"ANSI_COLOR_RESET, entry->d_name);
            
                if ((d != 1))
                {
                    /* code */
                    if (!(s1.st_mode & S_IRUSR)&&(change_flag==1))
                    {
                        /* code */
                        printf("Missing Permmissions for task!\n");
                    }
                    if (change_flag == 1)
                    {
                        continue;
                    }
                    
                    printf(ANSI_COLOR_GREEN "." ANSI_COLOR_RESET);
                    for (int i = length_of_base; i < strlen(curr_dir); i++)
                    {
                        printf(ANSI_COLOR_GREEN "%c" ANSI_COLOR_RESET, curr_dir[i]);
                    }
                    printf(ANSI_COLOR_GREEN "/" ANSI_COLOR_RESET);
                    printf(ANSI_COLOR_GREEN "%s\n" ANSI_COLOR_RESET, entry->d_name);
                }
            }
        }
        struct stat statbuf;
        stat(entry->d_name, &statbuf);
        if (S_ISDIR(statbuf.st_mode))
        {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            {
                continue;
            }
            char new_dir[4097];
            // sprintf(new_dir, "%s/%s", curr_dir, entry->d_name);
            chdir(entry->d_name);
            seek(file1, length_of_base, change_flag, f, d,occured);
            if ((*occured) == 1)
            {
                return;
            }
            chdir(curr_dir);
        }
    }
    if (change_flag == 1)
    {
        return;
    }
    chdir(curr_dir);
}