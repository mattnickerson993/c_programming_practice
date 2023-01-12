#include <stdio.h>

/* 
Goal: Write an alternative version of squeeze(s1, s2) that deletes each character in s1 that matches
      any character in the string s2
 */
void squeeze(char s1[], char s2[]);
void delete_all(char s[], int c);

int main(void){
    char s1[] = "hippopatamus";
    char s2[] = "giraffe";
    printf("String 1 initial: %s\n", s1);

    squeeze(s1, s2);
    printf("String 2: %s\n", s2);
    printf("String 1 squeezed: %s\n", s1);
    return 0;
}

void squeeze(char s1[], char s2[]){
    int i;
    for(i = 0 ; s2[i] != '\0'; i++){
        delete_all(s1, s2[i]);
    }
}

void delete_all(char s[], int c){
    int i, j;
    for(i = j = 0; s[i] != '\0'; i++){
        if (s[i] != c){
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}
