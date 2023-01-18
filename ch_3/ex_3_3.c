#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 1000
/* 
    Goal: Write a function to expand thats expands shorthand notation like a-z
    in the string s1 into the equivalent complete list abc...xyz.
    (does not handle edge cases that are out of order/reversed if g-a)
 */
void expand(char s1[], char s2[]);

int main(void){
    char str_one[] = "-0-7a-b-c-d-e-kA-V";
    char str_two[MAX_LEN];
    expand(str_one, str_two);
    printf("string 1: %s\n", str_one);
    printf("string 2: %s\n", str_two);
    return 0;
}


void expand(char s1[], char s2[]){
    int c1, c2;
    int i, j;
    i = j = 0;
    int len = strlen(s1);
    while(i < len){
        switch (s1[i])
        {
        case '-':
            if(i == 0 || i == len - 1){
                i++;
                break;
            }
            else if(isalpha(s1[i-1]) && islower(s1[i-1])){
                c1 = s1[i-1];
                c2 = s1[i + 1];
                c1++;
                while(c1 <= c2){
                    s2[j++] = c1;
                    c1++;
                }
                i+=2;
            }
            else if(isalpha(s1[i-1]) && isupper(s1[i-1])){
                c1 = s1[i-1];
                c2 = s1[i + 1];
                c1++;
                while(c1 <= c2){
                    s2[j++] = c1;
                    c1++;
                }
                i+=2;
            }
            else if(isdigit(s1[i-1])){
                c1 = s1[i-1];
                c2 = s1[i + 1];
                c1++;
                while(c1 <= c2){
                    s2[j++] = c1;
                    c1++;
                }
                i+=2;
            }
            break;
        
        default:
            s2[j++] = s1[i++];
            break;
        }
    }
    s2[j] = '\0';
}