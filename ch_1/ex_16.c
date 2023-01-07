#include <stdio.h>

#define MAXLINE 1000

/*
 Goal: read a set of lines and print the longest length and contents
 Method:
    * Repeatedly check line length (copying chars to line array in the process)
    * mark as max length if greater than longest and copy to "longest" array)
    * print max for length and contents of longest array
 */
int getln(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getln(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }
    printf("Longest Legnth: %i\n", max);
    printf("Line Contents: %s\n", longest);
    return 0;
}

int getln(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        i++;
}