#include "headers.h"
extern char my_home_dir[];
extern char previous_dir[];
// extern char address_of_event_storage[];
void warp(const char address[], int to_print_flag)
{
    // printf("Haya\n");
    // printf("%s\n", my_home_dir);
    // printf("rghergherghtrhr\n");

    // printf("rghergherghtrhr\n");
    char current_dir[4097];
    getcwd(current_dir, sizeof(current_dir));
    int change_to_dir;
    if (strcmp("~", address) == 0)
    {
        /* code */
        // printf("HaYaar\n");
        change_to_dir = chdir(my_home_dir);
    }
    else if (strcmp("-", address) == 0)
    {
        /* code */
        // printf("%s\n", previous_dir);
        change_to_dir = chdir(previous_dir);
    }
    else
    {
        change_to_dir = chdir(address);
    }
    if (change_to_dir == -1)
    {
        perror("Error in warp");
    }
    else
    {
        // printf("%s\n", current_dir);
        char to_print[4097];
        getcwd(to_print, sizeof(to_print));
        if (to_print_flag == 1)
        {
            printf("%s\n", to_print);
        }

        strcpy(previous_dir, current_dir);
    }
}
