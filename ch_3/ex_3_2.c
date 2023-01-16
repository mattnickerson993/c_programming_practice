#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

/* 
    Goal: write a function escape(s, t) that converts characters like newline and tab
    into visible escape sequences like \n and \t as is copies the string from t to s.
    Use a switch
 */

void escape(char s[], char t[]);

int main(void){
    char t[] = "tabs\tandnewlines\n";
    char s[MAX_LEN];
    escape(s, t);
    printf("t: %s\n", t);
    printf("s: %s\n", s);

    return 0;
}


void escape(char s[], char t[]){
    int i, j;
    i = j = 0;
    int len = strlen(t);
    while(i < len){
        switch (t[i])
        {
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            i++;
            break;
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            i++;
            break;
        default:
            s[j++] = t[i++];    
            break;
        }
    }
    s[j] = '\0';
}