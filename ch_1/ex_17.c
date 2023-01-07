#include <stdio.h>

#define MAXLINE 1000
#define MATCHLEN 80
#define MATCH_NOT_PRESENT 0
#define MATCH_PRESENT 1

/*
 Goal: print all lines with more than 80 chars
 Method:
    
 */
int getln(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
    int len, match;

    char line[MAXLINE];
    char longest[MAXLINE];

    match = MATCH_NOT_PRESENT;

    while ((len = getln(line, MAXLINE)) > 0)
    {
        if (len >= MATCHLEN)
        {   
            copy(longest, line);

            printf("Line Length: %i\n", len);
            printf("%s", line);
            if(!match){
                match = MATCH_PRESENT;
            }
        }
    }
    if(!match){
        printf("No lines of length %i or greater present\n", MATCHLEN);
    }
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