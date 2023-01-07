#include <stdio.h>

/* copy input to ouput: v1 */

int main(void){
    int c;
    c = getchar();
    while (c != EOF){
        putchar(c);
        c = getchar();
    }
}