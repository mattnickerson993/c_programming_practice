#include <stdio.h>

int str_len(char *s); /* return length of string not including null char */


int main(void){
    char arr[13] = "hello, world";
    char *ptr = arr;
    char *ptr_a = &arr[0];
    printf("Length: %d\n", str_len("hello, world"));
    printf("Length: %d\n", str_len(arr));
    printf("Length: %d\n", str_len(&arr[0]));
    printf("Length: %d\n", str_len(ptr));
    printf("Length: %d\n", str_len(ptr_a));
    
    return 0;
}


int str_len(char *s){
    int n;
    for(n = 0; *s != '\0'; s++, n++){
        ;
    }
    return n;
}