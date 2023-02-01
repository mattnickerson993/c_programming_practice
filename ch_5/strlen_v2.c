#include <stdio.h>


int strlen_v2(char *s);

int main(void){
    char *s = "bahumbug";

    printf("length: %d\n", strlen_v2(s));
    
    return 0;
}

int strlen_v2(char *s){
    char *p = s;
    while(*p != '\0')
        p++;
    return p - s;
}