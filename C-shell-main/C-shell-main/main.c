#include "headers.h"
// Define a struct

char my_home_dir[4097];
char previous_dir[4097];
char current_add_1011[4097];
char address_of_event_storage[45464];
struct proc1 arr1555[800000];

void child_data()
{

    int status;
    pid_t pid;

    
    for (int i = 0; i < 800000; i++)
    {
        int status;
        pid_t result;
        pid_t pid = i;
        if (arr1555[pid].over==100)
        {
            result = waitpid(pid, &status, WNOHANG);
            if ((result==0))
            {
                arr1555[pid].over = 100;
                continue;
            }
            if (result == -1)
            {
                arr1555[pid].over = 0;
                continue;
            }
            else
            {
                arr1555[pid].over = 0;
                if (WIFEXITED(status))
                {
                    if (WEXITSTATUS(status) == 0)
                    {
                        printf("%s with (%d) ended sucessfully\n", arr1555[pid].name, arr1555[pid].pid);
                    }
                    else
                    {
                        printf("%s with (%d) did not end sucessfully\n", arr1555[pid].name, arr1555[pid].pid);
                    }
                }
                else if (WIFSIGNALED(status))
                {
                    printf("%s with (%d) was terminated by a signal\n", arr1555[pid].name, arr1555[pid].pid);
                }
            }
        }
    }
}

int main()
{
    for (int i = 0; i < 800000; i++)
    {
        /* code */
        arr1555[i].over = 0;
    }

    getcwd(my_home_dir, sizeof(my_home_dir));
    char events_storage[] = "/events_data.txt";
    snprintf(address_of_event_storage, sizeof(address_of_event_storage), "%s%s", my_home_dir, events_storage);
    int to_print_prompt = 1;
    int to_print_forground = 0;
    char *previous_foreground;
    int current_number_of_loop43 = 0;
    events_past dummy;
    while (1)
    {
        // char input[4096];
        current_number_of_loop43++;
        char *input_initial = (char *)malloc(sizeof(char) * 4096);
        // fgets(input_initial, 4096, stdin);
        if (to_print_prompt == 1)
        {
            
            child_data();
            prompt(to_print_forground, previous_foreground);
            if (to_print_forground > 0)
            {
                to_print_forground = 0;
            }
            // printf("%d ", current_number_of_loop43);
            fgets(input_initial, 4096, stdin);
            // printf("curr number of loop %d\n", current_number_of_loop);
            // prompt();
        }
        else
        {
            to_print_prompt = 1;
            // snprintf(input, sizeof(input), "%s", dummy.instruction_executed);
            input_initial = (char *)malloc(sizeof(char) * (strlen(dummy.instruction_executed) + 1));
            strcpy(input_initial, dummy.instruction_executed);
            // printf("%s\n", input);
        }
        // int curr_ampersand = 0;
        int to_add_to_past_events = 1;
        char event2[strlen(input_initial) + 1];
        // snprintf(event2, sizeof(event2), "%s", input);
        strcpy(event2, input_initial);
        // printf("%s\n",event2);
        char *tokenizer;
        tokenizer = strtok(event2, " \t\n");
        if (tokenizer == NULL)
        {
            to_add_to_past_events = 0;
        }

        while (tokenizer != NULL)
        {
            if (strcmp(tokenizer, "pastevents") == 0)
            {
                to_add_to_past_events = 0;
                break;
                /* code */
            }
            tokenizer = strtok(NULL, " \t\n");
        }
        events_past struct_to_send;
        struct_to_send.instruction_executed = (char *)malloc(sizeof(char) * (strlen(input_initial) + 1));
        // snprintf(struct_to_send.instruction_executed, sizeof(char) * (strlen(input) + 1), "%s", input);
        strcpy(struct_to_send.instruction_executed, input_initial);
        // printf("%s\n", struct_to_send.instruction_executed);
        if (to_add_to_past_events == 1)
        {
            pastevents(0, 0, &struct_to_send);
            // printf("sfesgfs\n");
        }

        char delimitors1[] = "&;";
        char temp333[strlen(input_initial) + 1];
        strcpy(temp333, input_initial);
        // printf("%s\n", temp333);
        int ct = 0;
        for (int i = 0; i < strlen(input_initial); i++)
        {
            if (input_initial[i] == '&')
            {
                ct++;
            }
            if (input_initial[i] == ';')
            {
                ct++;
            }
        }

        // printf("%d\n", ct);
        int arr[ct];
        int curr_of_first_loop = 0;
        for (int i = 0; i < strlen(input_initial); i++)
        {
            if (input_initial[i] == '&')
            {
                arr[curr_of_first_loop++] = input_initial[i];
            }
            if (input_initial[i] == ';')
            {
                arr[curr_of_first_loop++] = input_initial[i];
            }
        }
        int tot_of_first_loop = curr_of_first_loop;
        curr_of_first_loop = 0;
        // printf("%d\n", tot_of_first_loop);
        // printf("%s\n",temp333);
        // printf("%d",strlen(temp333));
        char **arr_of_commands = (char **)malloc(sizeof(char *) * (ct + 1));

        char *temp_com = strtok(temp333, ";&");
        while (temp_com != NULL)
        {
            // printf("%s\n", command);
            arr_of_commands[curr_of_first_loop] = (char *)malloc(sizeof(char) * (strlen(temp_com) + 1));
            strcpy(arr_of_commands[curr_of_first_loop], temp_com);
            curr_of_first_loop++;
            temp_com = strtok(NULL, ";&");
        }
        arr_of_commands[curr_of_first_loop] = NULL;
        curr_of_first_loop = 0;
        int curr = 0;
        while (arr_of_commands[curr] != NULL)
        {
            // printf("Yes\n");
            /* code */
            // printf("%s\n", tok);
            char *input = (char *)malloc(sizeof(char) * (strlen(arr_of_commands[curr]) + 1));
            // char tp15[strlen(tok) + 1];
            // strcpy(tp15, tok);
            strcpy(input, arr_of_commands[curr]);
            // printf("\n%s ----------- \n", input);
            input[strlen(input)] = '\0';
            int is_it_bg = 0;
            if (curr_of_first_loop >= tot_of_first_loop)
            {
                is_it_bg = 0;
            }
            else
            {
                // printf("%c\n", arr[curr++]);
                if (arr[curr_of_first_loop] == '&')
                {
                    is_it_bg = 1;
                }
                else
                {
                    is_it_bg = 0;
                }
                curr_of_first_loop++;
            }
            // tok = strtok(NULL, ";&");
            // printf("%s\n", tok);

            int to_add_to_past_events = 1;
            int successful_completion_of_event = 1;
            char event_to_store[strlen(input) + 1];

            strcpy(event_to_store, input);

            events_past struct_to_store_this;
            // struct_to_store_this.instruction_executed = event_to_store;
            struct_to_store_this.instruction_executed = (char *)malloc(sizeof(char) * (strlen(event_to_store) + 1));
            // snprintf(struct_to_store_this.instruction_executed, sizeof(sizeof(char) * (strlen(event_to_store) + 1)), "%s", event_to_store);
            strcpy(struct_to_store_this.instruction_executed, event_to_store);
            // printf("%s\n", struct_to_store_this.instruction_executed);
            // // printf("%s", struct_to_store_this.instruction_executed);
            // // pastevents(0, 0, struct_to_store_this);
            // char *command;
            char delimators_for_commands[] = " \n\t";
            char *input2 = (char *)malloc(sizeof(char) * (strlen(input) + 1));
            strcpy(input2, input);
            // for (int i = 0; i < strlen(input); i++)
            // {
            //     input2[i] = input[i];
            // }
            input2[strlen(input)] = '\0';
            char *command_115 = malloc(sizeof(char) * (strlen(arr_of_commands[curr]) + 1));
            strcpy(command_115, arr_of_commands[curr]);
            curr++;
            char *command = strtok(command_115, delimators_for_commands);
            // printf("here\n");
            char spec3[] = "warp";
            char spec4[] = "peek";
            char spec5[] = "pastevents";
            char spec7[] = "proclore";
            char spec8[] = "seek";
            if (command == NULL)
            {
                continue;
            }

            if ((strcmp(spec3, command) == 0) && (is_it_bg == 0))
            {

                char *addr = (char *)malloc(sizeof(char) * (strlen(event_to_store) + 3));

                // strcpy(addr, event_to_store);
                snprintf(addr, strlen(event_to_store) + 3, "%s\n", event_to_store);
                // // printf("%s", addr);
                // // return 0;
                command = strtok(addr, " \n\t");

                int ct = 0;
                while (command != NULL)
                {
                    // printf("%s\n", command);
                    // printf("%s\n", command);
                    command = strtok(NULL, delimators_for_commands);
                    // printf("%s\n", command);
                    if (command == NULL)
                    {
                        break;
                    }
                    ct++;

                    if (command != NULL)
                    {
                        // printf("%s\n", command);
                        warp(command, 1);
                        // printf("%s\n", previous_dir);
                        // printf("%s\n", my_home_dir);
                    }
                }
                // printf("%d\n", ct);
                if (ct == 0)
                {
                    warp(my_home_dir, 1);
                }
                continue;
            }
            else if ((strcmp(spec4, command) == 0) && (is_it_bg == 0))
            {
                command = strtok(NULL, delimators_for_commands);
                if (command == NULL)
                {
                    peek("", 0, 0);
                }
                else
                {
                    // char address_to_peek[strlen(command) + 1];
                    // for (int i = 0; i < strlen(command); i++)
                    // {
                    //     address_to_peek[i] = command[i];
                    // }
                    // address_to_peek[strlen(command)] = '\0';
                    // // printf("%d\n", strlen(address_to_peek));
                    // command = strtok(NULL, delimators_for_commands);
                    // int ct_l = 0;
                    // int ct_a = 0;
                    // int flag_invalid = 0;
                    // while (command != NULL)
                    // {
                    //     if (command[0] != '-')
                    //     {
                    //         printf("Error: Invalid Flag\n");
                    //         flag_invalid = 1;
                    //         break;
                    //     }

                    //     for (int i = 1; i < strlen(command); i++)
                    //     {
                    //         if (command[i] == 'l')
                    //         {
                    //             ct_l = 1;
                    //         }
                    //         if (command[i] == 'a')
                    //         {
                    //             ct_a = 1;
                    //         }
                    //     }
                    //     command = strtok(NULL, delimators_for_commands);
                    // }
                    // if (flag_invalid == 1)
                    // {
                    //     continue;
                    // }
                    // peek(address_to_peek, ct_l, ct_a);
                    // continue;

                    int ct_l = 0;
                    int ct_a = 0;
                    int flag_invalid = 0;
                    while (command != NULL)
                    {
                        if (strcmp(command, "-l") == 0)
                        {
                            ct_l = 1;
                            /* code */
                        }
                        else if (strcmp(command, "-a") == 0)
                        {
                            ct_a = 1;
                            /* code */
                        }
                        else if (strcmp(command, "-la") == 0)
                        {
                            ct_l = 1;
                            ct_a = 1;
                            /* code */
                        }
                        else if (strcmp(command, "-al") == 0)
                        {
                            ct_l = 1;
                            ct_a = 1;
                            /* code */
                        }
                        else
                        {
                            break;
                        }
                        command = strtok(NULL, delimators_for_commands);
                    }
                    if (command == NULL)
                    {
                        peek("", ct_l, ct_a);
                        continue;
                    }
                    char address_to_peek[strlen(command) + 1];
                    strcpy(address_to_peek, command);
                    peek(address_to_peek, ct_l, ct_a);
                    continue;
                }
            }
            else if ((strcmp(spec5, command) == 0) && (is_it_bg == 0))
            {
                command = strtok(NULL, " \n");
                events_past e2;
                // e2.instruction_executed = "test";
                if (command == NULL)
                {
                    // printf("HAAA\n");
                    pastevents(1, 1, &e2);
                    // printf("%s\n", "HAAAAAAA");
                    continue;
                }
                // command = strtok(NULL, "\n");
                if (strcmp("purge", command) == 0)
                {
                    pastevents(2, 0, &e2);
                    continue;
                }
                if (strcmp("execute", command) == 0)
                {
                    
                    command = strtok(NULL, " \t\n");
                    int tot = 0;
                    for (int i = 0; i < strlen(command); i++)
                    {
                        if ((command[i] <= '9') && (command[i] >= '0'))
                        {
                            tot = tot * 10;
                            tot = tot + (command[i] - '0');
                        }
                    }
                    pastevents(3, tot, &e2);
                    // fprintf(stdin, "%s\n", e2.instruction_executed);
                    dummy.instruction_executed = e2.instruction_executed;
                    // printf("%s\n",dummy.instruction_executed);
                    // printf("%s\n", dummy.instruction_executed);
                    // printf("%s\n", input_initial);
                    to_print_prompt = 0;
                    continue;
                    // printf("%s\n",next1);
                }
            }
            else if ((strcmp(spec7, command) == 0) && (is_it_bg == 0))
            {
                int id_of_process = 0;
                while (command != NULL)
                {
                    command = strtok(NULL, " \n");
                    if (command == NULL)
                    {
                        break;
                    }
                    id_of_process = id_of_process * 10;
                    id_of_process = id_of_process + (command[0] - '0');
                }
                // printf("%d\n", id_of_process);
                proclore(id_of_process);
            }
            else if ((strcmp(spec8, command) == 0) && (is_it_bg == 0))
            {
                // printf("Ha\n");
                command = strtok(NULL, " \n\t");
                // char curr_address1[4097];
                // getcwd(curr_address1, 4097);
                // seek(command, strlen(curr_address1));
                int e = 0;
                int f = 0;
                int d = 0;
                getcwd(current_add_1011, sizeof(current_add_1011));
                while (command != NULL)
                {
                    /* code */
                    if (strcmp(command, "-e") == 0)
                    {
                        e = 1;
                        command = strtok(NULL, " \n\t");
                        continue;
                        /* code */
                    }
                    else if (strcmp(command, "-f") == 0)
                    {
                        f = 1;
                        command = strtok(NULL, " \n\t");
                        continue;
                        /* code */
                    }
                    else if (strcmp(command, "-d") == 0)
                    {
                        d = 1;
                        command = strtok(NULL, " \n\t");
                        continue;
                        /* code */
                    }
                    else
                    {
                        break;
                    }
                }
                if (command == NULL)
                {
                    /* code */
                    printf("Error: Invalid Command as no target specified for seek\n");
                    continue;
                }
                if ((f == 1) && (d == 1))
                {
                    printf("Invalid Flags\n");
                    continue;
                }

                char to_seek[4097];
                strcpy(to_seek, command);
                command = strtok(NULL, " \n\t");
                if (command == NULL)
                {
                    // base directory not given
                    // printf("%d %d %d\n", e, f, d);
                    // printf("%s\n", to_seek);
                    char curr_address11[4097];
                    getcwd(curr_address11, 4097);
                    // printf("%d\n", seek_to_count(to_seek, strlen(curr_address11), e, f, d));
                    int number_of_matches = seek_to_count(to_seek, strlen(curr_address11), e, f, d);
                    // if ((e == 1) && (number_of_matches != 1))
                    // {
                    //     chdir(curr_address11);
                    //     continue;
                    // }
                    if (number_of_matches==0)
                    {
                        printf("No matches found !\n");
                    }

                    int occured = 0;
                    seek(to_seek, strlen(curr_address11), 0, f, d, &occured);
                    chdir(curr_address11);
                    if ((number_of_matches == 1) && (e == 1))
                    {
                        seek(to_seek, strlen(curr_address11), 1, f, d, &occured);
                        /* code */
                    }

                    // chdir(curr_address11);
                    if ((number_of_matches != 1) || (e != 1))
                    {
                        /* code */
                        chdir(curr_address11);
                    }

                    // printf("%d\n", seek_to_count(to_seek, strlen(curr_address11), e, f, d));
                    // seek(to_seekk,strlen())
                }
                else
                {
                    char current_address11[4097];
                    getcwd(current_address11, 4097);
                    // chdir(command);
                    warp(command, 0);
                    int occured = 0;
                    char curr_address22[4097];
                    getcwd(curr_address22, 4097);
                    int number_of_matches = seek_to_count(to_seek, strlen(curr_address22), e, f, d);
                    // if ((e == 1) && (number_of_matches != 1))
                    // {
                    //     chdir(current_address11);
                    //     continue;
                    // }
                    // printf("%d\n", number_of_matches);
                    if (number_of_matches == 0)
                    {
                        printf("No matches found !\n");
                    }
                    seek(to_seek, strlen(curr_address22), 0, f, d, &occured);
                    // printf("%d\n", seek_to_count(to_seek, strlen(curr_address22), e, f, d));
                    if ((number_of_matches == 1) && (e == 1))
                    {
                        seek(to_seek, strlen(curr_address22), 1, f, d, &occured);
                    }
                    if ((number_of_matches != 1) || (e != 1))
                    {

                        chdir(current_address11);
                    }
                }
            }
            else if (strcmp("exit", command) == 0)
            {
                /* code */
                exit(0);
            }

            else
            {
                // successful_completion_of_event = 0;
                int ct_of_ampersand = 0;
                // for (int i = 0; i < strlen(struct_to_store_this.instruction_executed); i++)
                // {
                //     if (struct_to_store_this.instruction_executed[i] == '&')
                //     {
                //         ct_of_ampersand++;
                //     }
                // }
                if (is_it_bg == 0)
                {
                    /* code */
                    char *c_to_execute = (char *)malloc(sizeof(char) * (strlen(struct_to_store_this.instruction_executed) + 1));
                    char *new = (char *)malloc(sizeof(char) * (strlen(struct_to_store_this.instruction_executed) + 1));
                    strcpy(new, struct_to_store_this.instruction_executed);

                    c_to_execute = strtok(struct_to_store_this.instruction_executed, " \t\n");
                    int count_of_arguements = 0;
                    while (c_to_execute != NULL)
                    {

                        count_of_arguements++;
                        c_to_execute = strtok(NULL, " \t\n");
                    }
                    char **arguements = (char **)malloc(sizeof(char *) * (count_of_arguements + 1));
                    c_to_execute = strtok(new, " \t\n");
                    int i = 0;

                    while (c_to_execute != NULL)
                    {
                        arguements[i] = (char *)malloc(sizeof(char) * (strlen(c_to_execute) + 1));
                        strcpy(arguements[i], c_to_execute);
                        // printf("%s\n", arguements[i]);
                        i++;
                        c_to_execute = strtok(NULL, " \t\n");
                    }
                    arguements[count_of_arguements] = NULL;

                    const char *bin_address = "/bin/";
                    char final_address[strlen(bin_address) + strlen(arguements[0]) + 1];
                    snprintf(final_address, sizeof(final_address), "%s%s", bin_address, arguements[0]);

                    struct timeval start, end;
                    gettimeofday(&start, NULL);
                    pid_t child_proc = fork();
                    if (child_proc < 0)
                    {
                        printf("Error in fork\n");
                    }
                    else if (child_proc == 0)
                    {

                        int is_it_error = execv(final_address, arguements);
                        if (is_it_error == -1)
                        {
                            // printf("Error: Invalid Command\n");
                            // perror("Error");
                            printf("Invalid Command\n");
                            exit(EXIT_FAILURE);
                        }
                    }
                    else
                    {
                        waitpid(child_proc, NULL, 0);
                        gettimeofday(&end, NULL);
                        double time_taken;
                        time_taken = (end.tv_sec - start.tv_sec) * 1e6;
                        time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;
                        int t = time_taken;
                        if (t > 2)
                        {
                            printf("Time taken :%d seconds\n", t);
                            to_print_forground = t;
                            previous_foreground = (char *)malloc(sizeof(char) * (strlen(command) + 1));
                            strcpy(previous_foreground, command);
                        }
                    }
                }
                else
                {
                    char *bg = (char *)malloc(sizeof(char) * (strlen(struct_to_store_this.instruction_executed) + 1));
                    strcpy(bg, struct_to_store_this.instruction_executed);
                    char *curr_comm = (char *)malloc(sizeof(char) * (strlen(bg) + 1));
                    strcpy(curr_comm, bg);
                    // int i_1 = 0;
                    // while (curr_comm != NULL)
                    {
                        // i_1++;
                        // ct_of_ampersand++;
                        char *c_to_execute;
                        char *new = (char *)malloc(sizeof(char) * (strlen(curr_comm) + 1));
                        char new2[strlen(curr_comm) + 1];
                        strcpy(new2, curr_comm);
                        strcpy(new, curr_comm);
                        // printf("%s\n", curr_comm);
                        c_to_execute = strtok(new, " \t\n");
                        int count_of_arguements = 0;
                        // // printf("%s\n", curr_comm);
                        while (c_to_execute != NULL)
                        {
                            count_of_arguements++;
                            c_to_execute = strtok(NULL, " \t\n");
                        }
                        char **arguements = (char **)malloc(sizeof(char *) * (count_of_arguements + 1));
                        c_to_execute = strtok(new2, " \t\n");
                        int j = 0;
                        while (c_to_execute != NULL)
                        {
                            arguements[j] = (char *)malloc(sizeof(char) * (strlen(c_to_execute) + 1));
                            strcpy(arguements[j], c_to_execute);
                            j++;
                            c_to_execute = strtok(NULL, " \t\n");
                        }
                        arguements[count_of_arguements] = NULL;
                        const char *bin_address = "/bin/";
                        char final_address[strlen(bin_address) + strlen(arguements[0]) + 1];
                        snprintf(final_address, sizeof(final_address), "%s%s", bin_address, arguements[0]);
                        pid_t child_proc = fork();
                        if (child_proc < 0)
                        {
                            printf("Error in fork\n");
                        }
                        else if (child_proc == 0)
                        {
                            setpgid(0, 0);
                            int succes1 = execv(final_address, arguements);
                            if (succes1 == -1)
                            {
                                //    perror("Error ");
                                
                                printf("Invalid command \n");
                                exit(EXIT_FAILURE);
                            }
                        }
                        else
                        {
                            // if (i_1 > ct_of_ampersand)
                            // {
                            //     waitpid(child_proc, NULL, 0);
                            // }
                            arr1555[child_proc].over = 0;
                            arr1555[child_proc].pid = child_proc;
                            arr1555[child_proc].name = (char *)malloc(sizeof(char) * (strlen(command) + 1));
                            strcpy(arr1555[child_proc].name, command);
                            // printf("%s\n", arr1555[child_proc].name);
                            printf("%d\n", child_proc);
                            // signal(SIGCHLD, child_data);
                            arr1555[child_proc].over = 100;
                        }
                        // curr_comm = strtok(NULL, "&");
                    }
                }
            }
        }
    }
    // printf("%d\n", isPrefix("test23", "test2"));
    return 0;
}
