#include <stdio.h>
#include <string.h>

// saves time -- no function call
#define is_upper(c) ((c) >= 'A' && (c) <= 'Z') ? 1 : 0 

// int is_upper(int);

int main(void){
    char *my_str = "Hello WORLD";
    for(; *my_str != '\0'; my_str++){
        if(is_upper(*my_str)){
            printf("Upper: %c\n", *my_str);
        }
        else{
            printf("Lower: %c\n", *my_str);
        }
    }
    return 0;
}


/* isupper: return 1 if char is uppercase, zero if not */
// saves space but increase time to perform function call
// int is_upper(int c){
//     return (c >= 65 && c <= 90);
// }

// int is_upper(int c){
//     return (strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZ", c) != NULL);
// }
