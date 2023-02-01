#include <stdio.h>

#define MAXLEN 100
/* 
    Goal: write a pointer version of strcat(s, t) that copies the string t to the end of s
*/
void str_cat(char *s, char *t);

int main (void)
{
    char s[MAXLEN + MAXLEN] = "cat";
    char t[MAXLEN] = "inthehat";
    str_cat(s, t);
    printf("%s\n", s);
    return 0;
}

void str_cat(char *s, char *t){
    // need to avoid max_len
    while(*++s){ /* find the end of s */
        ;
    }

    while((*s++ = *t++) != '\0'){
        ;
    }
}