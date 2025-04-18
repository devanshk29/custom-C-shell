#include "headers.h"

extern char my_home_dir[];
void prompt(int print_prev_status,char prev_process_name[])
{
    // Do not hardcode the prmopt
    struct utsname sytstem_info;
    char current_path[4097];
    getcwd(current_path, sizeof(current_path));
    
    uid_t uid = getuid();
    struct passwd *pw = getpwuid(uid);

    if (pw != NULL)
    {
        printf("<%s@", pw->pw_name);
    }
    else
    {
        perror("Error");
    }
    if (uname(&sytstem_info) == 0)
    {
        /* code */
        int flag = 0;
        if (strlen(my_home_dir) > strlen(current_path))
        {
            /* code */
            flag = -1;
        }
        else
        {
            for (int i = 0; i < strlen(my_home_dir); i++)
            {
                if (my_home_dir[i] != current_path[i])
                {
                    flag = -1;
                    break;
                }
            }
        }
        printf("%s:", sytstem_info.nodename);
        if (flag == 0)
        {
            printf("~");
            for (int i = strlen(my_home_dir); i < strlen(current_path); i++)
            {
                /* code */
                printf("%c", current_path[i]);
            }
        }
        else
        {
            printf("%s", current_path);
        }
        if (print_prev_status>2)
        {
            printf(" %s : %d",prev_process_name,print_prev_status);
        
        }
        
        printf(">");
    }

    // printf("<Everything is a file> ");
}
