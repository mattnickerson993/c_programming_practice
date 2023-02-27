#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]){
    if(argc != 1){
        printf("Usage: upper/lower");
        return -1;
    }

    int c;
    printf("%s\n", argv[0]);
    if(strcmp(argv[0], "./upper") == 0){
        while ((c = getchar()) != EOF){
            putchar(toupper(c));
        }
    }
    else if (strcmp(argv[0], "./lower") == 0)
    {
        while ((c = getchar()) != EOF){
            putchar(tolower(c));
        }
    }else{
        printf("Error:improper file name\n");
        return -1;
    }
    printf("\n");
    return 0;
    
}