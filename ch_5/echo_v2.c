#include <stdio.h>

/* echo command line arguments: second version */

int main(int argc, char *argv[]){
    int i;
    while(--argc){
        printf("%s%s", *++argv, (argc > 1) ? " " : "");
    }
    printf("\n");
    return 0;
}