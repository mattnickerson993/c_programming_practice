#include <stdio.h>

/*
Goal: write a function htoi(s) which converts a string of hexadecimal digits into its equivalent integer value
    Method - loop through string and convert to int. Display running total

 */
int htoi(char s[]);

int main(void){
    // HI 0 a
    char s[] = "\x48\x49\x30\x61";
    int res;
    res = htoi(s);
    if (res == -1 ){
        printf("Error: Incorrect input (must be a-z 0-9 A-Z)\n");
        return -1;
    }

    printf("res: %d\n", res);
}


int htoi(char s[]){
    int i, total;
    total = 0;

    for(i = 0; s[i] != '\0'; i++){
        if((s[i] >= '0' && s[i] <= '9' ) || (s[i] >= 'a' && s[i] <= 'z' || (s[i] >= 'A' && s[i] <= 'Z' ))){
            // printf("%c\n", (int)(s[i]));
            total += (int) s[i];
        }
        else{
            return -1;
        }
    }
    return total;

}