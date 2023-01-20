#include <stdio.h>

#define MAXLINE 1000

/* 
    Goal: write function strrindex(s, t) which returns the position of the
    rightmost occurence of t in s or -1 if there is none.

 */

int getln(char line[], int max);
int strindex(char source[], char searchfor[]);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main(void){
    char line[MAXLINE];
    int rightmost;
    int found = 0;

    while (getln(line, MAXLINE) > 0){
        if((rightmost = strrindex(line, pattern)) >= 0){
            printf("%s", line);
            // to verify functionality
            // printf("%d\n", rightmost);
            found ++;
        }
    }
    printf("\n");
    return found;
}


// return index of t in s, -1 if none
int strindex(char s[], char t[]){
    int i, j, k;

    for(i = 0; s[i] != '\0'; i++){
        for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
        ;
        if(k > 0 && t[k] == '\0'){
            return i;
        }
    }
    return -1;
}
// copy line to array (line), return length
int getln(char line[], int max){
    int c, i;
    i = 0;
    while(--max > 0 && (c = getchar()) != EOF && c != '\n'){
        line[i++] = c; 
    }
    if(c == '\n'){
        line[i++] = c;
    }
    line[i] = '\0';
    return i;
}

/* 
    Return right most position t in s.
    ex: t = ould
        s = could or should
        return 10

 */

int strrindex(char s[], char t[]){
    int i, j, k, rightmost;

    // default return value
    rightmost = -1;

    for(i = 0; s[i] != '\0'; i++){
        for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
        ;
        if(k > 0 && t[k] == '\0'){
            rightmost = i;
        }
    }

    return rightmost;
}