#include <stdio.h>
#include <string.h>

/* 
    Write a version of strncopy(s, t, n). Where string t is copied to s and at most n characters are copied
    to prevent buffer overflow.
*/

void strn_copy(char *s, char *t, int n);


int main(void)
{
    char s[100];
    char *t = "hamburger";
    strn_copy(s, t, strlen(t));
    printf("s: %s\n", s);
    return 0;
}


void strn_copy(char *s, char *t, int n)
{
    int i;
    for(i = 0; i < n && *t != '\0'; i++){
        *s++ = *t++;
    }

    *s = '\0';
}