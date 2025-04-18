#include "headers.h"
extern char address_of_event_storage[];

void pastevents(int flag, int index, events_past *e1)
{
    
    FILE *ff = fopen(address_of_event_storage, "r");
    if (ff == NULL)
    {
        FILE *e_store1 = fopen(address_of_event_storage, "w");
        fprintf(e_store1, " ");
        fclose(e_store1);
    }
    else
    {
        fclose(ff);
    }
    // printf("%s\n", e1->instruction_executed);
    if (flag == 0)
    {
        // printf("Ha\n");
        e1->instruction_executed = strtok(e1->instruction_executed, "\n");
        // printf("haaaa\n");
        int curr_number_of_events = 0;
        FILE *f1 = fopen(address_of_event_storage, "r");
        char buffer[4096];
        while (fgets(buffer, sizeof(buffer), f1) != NULL)
        {
            curr_number_of_events++;
            // printf("%s\n", buffer);
            // printf("%d\n", strlen(buffer));
            if (curr_number_of_events == 1)
            {
                if (strcmp(buffer, " ") == 0)
                {
                    /* code */
                    // printf("HABHAI\n");
                    curr_number_of_events = 0;
                    break;
                }
            }
        }
        // printf("hfhewfehfefhfjfjjf\n");
        // printf("%d\n", curr_number_of_events);
        fclose(f1);
        // printf("yoyoyyo\n");

        // printf("%d\n", curr_number_of_events);
        if ((curr_number_of_events > 0))
        {
            // printf("yoyoyyo\n");
            FILE *f2 = fopen(address_of_event_storage, "r");
            // printf("yoyoyyo\n");
            events_past arr_of_events[curr_number_of_events];
            // printf("yoyoyyo\n");
            for (int i = 0; i < curr_number_of_events; i++)
            {
                fgets(buffer, sizeof(buffer), f2);
                char *temp = (char *)malloc(sizeof(char) * (strlen(buffer)+1));
                // for (int j = 0; j < strlen(buffer); j++)
                // {
                //     temp[j] = buffer[j];
                // }
                // temp = strtok(temp, "\n");
                strcpy(temp, buffer);
                temp[strlen(temp)-1] = '\0';
                arr_of_events[i].instruction_executed = temp;
            }
            fclose(f2);
            // printf("yoyoyyo\n");

            if (strcmp(arr_of_events[curr_number_of_events - 1].instruction_executed, e1->instruction_executed) == 0)
            {
                /* code */
                return;
            }

            FILE *f3 = fopen(address_of_event_storage, "w");

            /* code */
            if (curr_number_of_events == 15)
            {
                for (int i = 0; i < 14; i++)
                {
                    arr_of_events[i] = arr_of_events[i + 1];
                }
                char *temp2 = (char *)malloc(sizeof(char) * (strlen(e1->instruction_executed)+1));
                // for (int i = 0; i < strlen(e1->instruction_executed); i++)
                // {
                //     temp2[i] = e1->instruction_executed[i];
                // }
                strcpy(temp2, e1->instruction_executed);

                for (int i = 0; i < 14; i++)
                {
                    fprintf(f3, "%s\n", arr_of_events[i].instruction_executed);
                }
                fprintf(f3, "%s\n", temp2);
                fclose(f3);
                return;
            }
            char *temp2 = (char *)malloc(sizeof(char) * strlen(e1->instruction_executed));
            // for (int i = 0; i < strlen(e1->instruction_executed); i++)
            // {
            //     temp2[i] = e1->instruction_executed[i];
            // }
            strcpy(temp2, e1->instruction_executed);
            temp2 = strtok(temp2, "\n");
            temp2[strlen(temp2)] = '\0';
            for (int i = 0; i < curr_number_of_events; i++)
            {
                fprintf(f3, "%s\n", arr_of_events[i].instruction_executed);
            }

            fprintf(f3, "%s\n", temp2);
            fclose(f3);
        }
        else
        {
            // printf("yoyoyy23524o\n");
            FILE *f3 = fopen(address_of_event_storage, "w");
            char *temp2 = (char *)malloc(sizeof(char) * strlen(e1->instruction_executed)+1);
            // printf("yoyoyyo\n");
            strcpy(temp2, e1->instruction_executed);
            // temp2 = strtok(temp2, "\n");
            // printf("yoyoyyo\n");
            temp2[strlen(temp2)] = '\0';
            // printf("yoyoyyowqrweew\n");
            fprintf(f3, "%s\n", temp2);
            // printf("yoyoyyo4635536\n");
            fclose(f3);
        }
    }
    else if (flag == 1)
    {
        // printf("egddsfdb\n");
        FILE *f1 = fopen(address_of_event_storage, "r");
        char buffer[4096];
        // printf("Ha\n");
        while (fgets(buffer, sizeof(buffer), f1) != NULL)
        {
            printf("%s", buffer);
        }
        fclose(f1);
        return;
    }
    else if (flag == 2)
    {
        FILE *f1 = fopen(address_of_event_storage, "w");
        fprintf(f1, " ");
        fclose(f1);
    }
    else if (flag == 3)
    {
        int curr_number_of_events = 0;
        FILE *f1 = fopen(address_of_event_storage, "r");
        char buffer[4096];
        while (fgets(buffer, sizeof(buffer), f1) != NULL)
        {
            curr_number_of_events++;
        }
        if (curr_number_of_events == 0)
        {
            printf("No instrucction in record\n");
            return;
        }
        fclose(f1);
        if (curr_number_of_events > 0)
        {
            FILE *f2 = fopen(address_of_event_storage, "r");
            events_past arr_of_events[curr_number_of_events];
            for (int i = 0; i < curr_number_of_events; i++)
            {
                fgets(buffer, sizeof(buffer), f2);
                char *temp = (char *)malloc(sizeof(char) * (strlen(buffer)));
                for (int j = 0; j < strlen(buffer); j++)
                {
                    temp[j] = buffer[j];
                }
                temp = strtok(temp, "\n");

                arr_of_events[i].instruction_executed = temp;
            }
            fclose(f2);
            if ((curr_number_of_events) < index)
            {
                printf("Insufficient Number Of Instructions\n");
            }
            // printf("%d\n", curr_number_of_events);
            int curr = 0;
            for (int i = curr_number_of_events - 1; i >= 0; i--)
            {
                curr++;
                if (curr == index)
                {
                    e1->instruction_executed = arr_of_events[i].instruction_executed;
                    return;
                }
            }
            return;
        }
    }
}
