#ifndef __PEEKING_H
#define __PEEKING_H
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_PURPLE "\e[0;35m"
#define ANSI_COLOR_YELLOW "\e[0;33m"
void peek(const char address[],int l,int a);
int cmprt(const void *a, const void *b);
struct string_for_sort{
    char *word_to_sort;
    int type;
};
void substring(char s[], int start, int end);
#endif