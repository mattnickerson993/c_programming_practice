#include <stdio.h>

#define TAB_LENGTH 4

/*
Goal: Write a program that replaces a defined number of consecutive spaces with a tab
Method: Define an Tab length. Count space characters and replace when appropriate. Output spaces that
        don't reach the tab length standard.
 */

int main(void){

    int c, i, space_count, state;

    space_count = 0;

    while((c = getchar()) != EOF){
        // matched condition
        if (c == ' ' && space_count == TAB_LENGTH - 1){
            // putchar('\t');
            printf("tab");
            // output tab and reset
            space_count = 0;
        }
        else{
            if(c == ' ' && space_count < TAB_LENGTH - 1){
                space_count ++;
            }
            else{
                // not a space
                if (space_count > 0){
                    // output any stored spaces
                    for(i = 0; i < space_count; i++){
                        putchar(' ');
                    }
                    space_count = 0;
                }
                putchar(c);
            }
        }
    }
    printf("\n");
    return 0;
}