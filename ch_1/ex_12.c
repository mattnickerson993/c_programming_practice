#include <stdio.h>

/* write a program that prints its input 1 word per line */


int main(void){
    int c;

    while ((c = getchar()) != EOF){
        if (c == ' '){
            putchar('\n');
        }
        else{
        putchar(c);
        }
    }
}