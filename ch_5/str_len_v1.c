#include <stdio.h>


int str_len_v1(char *s);

int main(void){
    char *s = "happyhappyjoyjoy";
    char arr[10] = "abcdefgh";
    int len = str_len_v1(s);

    int lenA = str_len_v1(arr);
    int lenB = str_len_v1("deckthehalls");

    printf("Length: %d\n", len);
    printf("Length: %d\n", lenA);
    printf("Length: %d\n", lenB);
    
    return 0;
}


int str_len_v1(char *s){
    int i;
    for(i = 0; *s != '\0'; s++){
        i++;
    }
    return i;
}