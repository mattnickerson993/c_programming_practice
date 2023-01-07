#include <stdio.h>

int main(void){
    int c;
    int blanks, tabs, nl;

    blanks = tabs = nl = 0;

    while ((c = getchar()) != EOF){
        if (c == '\n'){
            nl++;
        }
        else if(c == '\t'){
            tabs++;
        }
        else if (c == ' '){
            blanks++;
        }
    }
    printf("Blanks %d Tabs: %d Newlines: %d\n", blanks, tabs, nl);
    return 0;
}
