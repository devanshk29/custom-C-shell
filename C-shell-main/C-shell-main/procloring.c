#include "headers.h"
extern char my_home_dir[4097];
extern char previous_dir[4097];

void proclore(int pid)
{
    // printf("pid : %d\n", pid);
    // pid of the currentm process
    // procecc status
    if (pid == 0)
    {
        pid = getpid();
    }
    printf("pid : %d\n", pid);
    char proc_status[4097];
    sprintf(proc_status, "/proc/%d/status", pid);
    FILE *fp = fopen(proc_status, "r");
    if (fp == NULL)
    {
        perror("Error in proclore");
        return;
    }
    // printf("Reached here\n");
    char status[4097];
    while (fgets(status, sizeof(status), fp))
    {
        if (strncmp(status, "VmSize", 6) == 0)
        {
            printf("Virtual memory : ");
            // printf("%s", status);

            for (int lambda1 = 7; lambda1 < strlen(status); lambda1++)
            {

                printf("%c", status[lambda1]);
            }
        }
        if (strncmp(status, "State", 5) == 0)
        {
            // printf("%s", status);
            printf("process Status : ");
            char c_state1 = 'Z';
            for (int lambda2 = 6; lambda2 < strlen(status); lambda2++)
            {
                if (status[lambda2] != '\t')
                {
                    printf("%c", status[lambda2]);
                    c_state1 = status[lambda2];
                    break;
                }
            }
            int terminal_pgid = getpgrp();
            // printf("terminal pgid %d\n", terminal_pgid);
            if ((c_state1 != 'z') && (c_state1 != 'Z'))
            {
                if (getpgid(pid) == terminal_pgid)
                {
                    printf("+\n");
                }
                else
                {
                    printf("\n");
                }
                /* code */
            }
            else
            {
                printf("\n");
            }

            printf("Process group :%d\n", getpgid(pid));
        }
        // process group id
        //  if (strncmp(status, "Pgid", 4) == 0)
        //  {
        //      printf("%s\n", status);
        //  }
    }
    fclose(fp);

    char proc_exe[4097];
    sprintf(proc_exe, "/proc/%d/exe", pid);
    char exe_path[4097];
    int a = readlink(proc_exe, exe_path, sizeof(exe_path));
    if (a < 0)
    {
        perror("Executable  path not accessible ");
    }
    else
    {

        printf("executable path: %s\n", exe_path);
    }
    return;
}