#include <stdio.h>

#define MAXLEN 100
/* 
    Write the function strend(s, t) which returns 1 if the string t occurs at the end of the string s
    and 0 otherwise
*/

int str_end(char *s, char *t);

int main (void)
{
    // match
    char s[MAXLEN] = "inthehat";
    char t[MAXLEN] = "hat";
    printf("%d\n", str_end(s, t));
    // no match
    char s1[MAXLEN] = "inthecat";
    char t1[MAXLEN] = "hat";
    printf("%d\n", str_end(s1, t1));
    return 0;
}

int str_end(char *s, char *t){
    // starting address of t
    char *start_t = t;

    while(*++s); /* go to the end of s */
    while(*++t); /* go to the end of t */

    for( ; *s == *t; s--, t--){
        if(start_t == t){ /* if i make it to the start of t */
            return 0;
        }
    }
    return 1;

}