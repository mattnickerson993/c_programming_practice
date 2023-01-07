#include <stdio.h>

int main(void){
    int c, nl;

    nl = 0;
    while((c = getchar()) != EOF){
        if (c == '\n')
            nl++;
    
    }
    printf("Line count: %d\n", nl);
}