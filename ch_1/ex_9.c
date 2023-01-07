#include <stdio.h>

#define ON_SPACE 0
#define OFF_SPACE 1

int main(void){
    
    int c, state;
    state = OFF_SPACE;

    while((c = getchar()) != EOF){
        if (state == OFF_SPACE && c == ' '){
            state = ON_SPACE;
            putchar(c);
        }
        else if(c != ' '){
            state = OFF_SPACE;
            putchar(c);
        }
        // else if(state == ON_SPACE && c == ' '){
        //     continue;
        // }
        // else if(state == ON_SPACE && c != ' '){
        //     state = OFF_SPACE;
        //     putchar(c);
        // }
        // else{
        //     putchar(c);
        // }
    }
}