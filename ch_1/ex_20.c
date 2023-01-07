#include <stdio.h>

#define TAB_LENGTH 4

/*
Goal: 
    write a program that replaces tabs in the input with the proper number of blanks --- assuming tab = 4 columns 
 */

int main(void){
    int i, c;
    while ((c = getchar()) != EOF){
        if(c == '\t'){
            for(i = 0; i < TAB_LENGTH; i++){
                putchar(' ');
            }
        }
        else putchar(c);
    }
}