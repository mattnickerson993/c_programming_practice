#include <stdio.h>

#define BUFFER 100
/* 
    Goal: rewrite get_ln function using pointers

*/
int get_ln(char *s, int limit);

int main(void){

    char s[BUFFER];
    while((get_ln(&s[0], BUFFER)) > 0){
        printf("s: %s", s);
    }
    printf("\n");
    return 0;
}


// returns length of line including newline char, also copies line to array
int get_ln(char *s, int limit){
    int i, c;

    for(i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++){
        *s++ = c;
    }
    if(c == '\n'){
        *s++ = c;
        i++;
    }
    *s = '\0';

    return i;
}