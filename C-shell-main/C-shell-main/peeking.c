#include "headers.h"
extern char my_home_dir[4097];
extern char previous_dir[4097];

void substring(char s[], int start, int end)
{
    for (int i = start; i < end + 1; i++)
    {
        printf("%c", s[i]);
    }
}
int cmprt(const void *a, const void *b)
{
    struct string_for_sort a1 = *((struct string_for_sort *)a);
    struct string_for_sort b1 = *((struct string_for_sort *)b);
    return (strcmp(a1.word_to_sort, b1.word_to_sort));
}
void peek(const char address[], int l, int a)
{
    char dir_temp[4097];
    getcwd(dir_temp, sizeof(dir_temp));
    DIR *ptr_to_current_directory = NULL;
    if (strcmp("~", address) == 0)
    {
        // printf("Ha\n");
        chdir(my_home_dir);
        ptr_to_current_directory = opendir(".");
        // chdir(dir_temp);
    }
    else if (strcmp("", address) == 0)
    {
        /* code */
        ptr_to_current_directory = opendir(".");
    }
    else if (strcmp(".", address) == 0)
    {
        /* code */
        ptr_to_current_directory = opendir(".");
    }
    else if (strcmp("-", address) == 0)
    {
        /* code */
        int a = chdir(previous_dir);
        if (a < 0)
        {
            perror("Error:");
        }

        ptr_to_current_directory = opendir(".");
    }
    else
    {
        int a = chdir(address);
        if (a < 0)
        {
            perror("Error:");
        }

        ptr_to_current_directory = opendir(".");
    }

    if (ptr_to_current_directory == NULL)
    {
        perror("Error:");
    }
    else
    {
        struct dirent *element_of_current_directory;
        element_of_current_directory = readdir(ptr_to_current_directory);
        int curr_size_of_arr = 1;
        int curr_number_of_elements = 0;
        size_t total_number_blocks_in_answer = 0;
        struct string_for_sort *arr = (struct string_for_sort *)malloc(curr_size_of_arr * sizeof(struct string_for_sort));
        while (element_of_current_directory != NULL)
        {
            if (element_of_current_directory == NULL)
            {
                break;
            }
            struct stat s;
            int pass_s = stat(element_of_current_directory->d_name, &s);

            if (pass_s == -1)
            {
                perror("Error:");
                break;
            }
            else
            {
                if (a == 0)
                {
                    if (element_of_current_directory->d_name[0] == '.')
                    {
                        element_of_current_directory = readdir(ptr_to_current_directory);
                        continue;
                    }
                }
                if (curr_number_of_elements == curr_size_of_arr)
                {
                    curr_size_of_arr = (curr_size_of_arr * 2);
                    arr = realloc(arr, curr_size_of_arr * sizeof(struct string_for_sort));
                }
                // if (l == 1)
                {
                    total_number_blocks_in_answer += s.st_blocks;
                }
                if (S_ISDIR(s.st_mode))
                {
                    arr[curr_number_of_elements].word_to_sort = element_of_current_directory->d_name;
                    arr[curr_number_of_elements].type = 0;
                }
                else if (s.st_mode & S_IXUSR)
                {
                    arr[curr_number_of_elements].word_to_sort = element_of_current_directory->d_name;
                    arr[curr_number_of_elements].type = 1;
                }

                else
                {
                    arr[curr_number_of_elements].word_to_sort = element_of_current_directory->d_name;
                    arr[curr_number_of_elements].type = 2;
                }
            }
            curr_number_of_elements++;
            element_of_current_directory = readdir(ptr_to_current_directory);
        }
        qsort(arr, curr_number_of_elements, sizeof(struct string_for_sort), cmprt);
        if (l == 1)
        {
            struct stat s1;
            char dir_curr_2[4097];
            getcwd(dir_curr_2, sizeof(dir_curr_2));
            int pass_s = stat(dir_curr_2, &s1);
            if (pass_s < 0)
            {
                perror("Error:");
            }
            printf("total %ld\n", total_number_blocks_in_answer);
        }

        for (int i = 0; i < curr_number_of_elements; i++)
        {
            if (l == 1)
            {
                struct stat s_for_a_tag;
                if (stat(arr[i].word_to_sort, &s_for_a_tag) < 0)
                {
                    /* code */
                    perror("Error:");
                }
                // printf("%s",s_for_a_tag.)
                if (S_ISDIR(s_for_a_tag.st_mode))
                {
                    printf("d");
                }
                else
                {
                    printf("-");
                }
                if (s_for_a_tag.st_mode & S_IRUSR)
                {
                    printf("r");
                }
                else
                {
                    printf("-");
                }
                if (s_for_a_tag.st_mode & S_IWUSR)
                {
                    printf("w");
                }
                else
                {
                    printf("-");
                }
                if (s_for_a_tag.st_mode & S_IXUSR)
                {
                    printf("x");
                }
                else
                {
                    printf("-");
                }
                if (s_for_a_tag.st_mode & S_IRGRP)
                {
                    printf("r");
                }
                else
                {
                    printf("-");
                }
                if (s_for_a_tag.st_mode & S_IWGRP)
                {
                    printf("w");
                }
                else
                {
                    printf("-");
                }
                if (s_for_a_tag.st_mode & S_IXGRP)
                {
                    printf("x");
                }
                else
                {
                    printf("-");
                }
                if (s_for_a_tag.st_mode & S_IROTH)
                {
                    printf("r");
                }
                else
                {
                    printf("-");
                }
                if (s_for_a_tag.st_mode & S_IWOTH)
                {
                    printf("w");
                }
                else
                {
                    printf("-");
                }
                if (s_for_a_tag.st_mode & S_IXOTH)
                {
                    printf("x");
                }
                else
                {
                    printf("-");
                }
                printf("\t");
                printf("%ld", s_for_a_tag.st_nlink);
                printf("\t");
                struct passwd *pw = getpwuid(s_for_a_tag.st_uid);
                struct group *gr = getgrgid(s_for_a_tag.st_gid);
                printf("%s", pw->pw_name);
                printf("\t");
                printf("%s", gr->gr_name);
                printf("\t");
                printf("%ld", s_for_a_tag.st_size);
                printf("\t\t");
                char *time = ctime(&s_for_a_tag.st_mtime);
                time[strlen(time) - 9] = '\0';
                // printf("%s", time);
                substring(time, 4, strlen(time) - 1);
                printf("\t\t");
            }
            if (arr[i].type == 0)
            {
                printf(ANSI_COLOR_BLUE " %s" ANSI_COLOR_RESET, arr[i].word_to_sort);
            }
            else if (arr[i].type == 1)
            {
                printf(ANSI_COLOR_GREEN " %s" ANSI_COLOR_RESET, arr[i].word_to_sort);
            }
            else
            {
                printf(" %s", arr[i].word_to_sort);
            }

            printf("\n");
        }
        closedir(ptr_to_current_directory);
        chdir(dir_temp);
    }
}