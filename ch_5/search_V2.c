#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

/* 
    Goal: print lines that match pattern from first arg
    options:    -n = line numbering
                -x = inversion
*/

int getln(char line[], int max);


int main(int argc, char *argv[]){
    char line[MAXLINE];
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;

    printf("argc: %d\n", argc);
    for(int i = 0; i < argc; i++){
        printf("argv[%d]: %s\n", i, argv[i]);
    } 
    // determine options selected
    /* 
        Note: (*++argv)[0] === increment in the pointer array and get the first index of the what the pointer is pointing to
             *++argv[0] ==== increment to the next index of what the pointer is pointing to (ie not the next pointer) 
    */
    while(--argc > 0 && (*++argv)[0] == '-'){
        while(c = *++argv[0]){
            switch (c)
            {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                printf("find: illegal option %c\n", c);
                argc = 0;
                found = -1;
                break;
            }
        }
    }
    if(argc != 1){
        printf("Usage: find -x -n pattern\n");
        return 0;
    }
    else{
        while (getln(line, MAXLINE) > 0){
            lineno++;
            printf("strstr: %d\n", strstr(line, *argv) != NULL);
            // strstr == 0 or random number... != NULL === 0 or 1
            // -x option 1 = match except = 1 .... ie only print non matches
            // --no -x option =  1 = match except = 0 , ie only print matches
            if((strstr(line, *argv) != NULL) != except){
                if(number){
                    printf("%ld: ", lineno);
                }
                printf("%s", line);
                found ++;
            }
        }
    }
    return found;
}





// copy line to array (line), return length
int getln(char line[], int max){
    int c, i;
    i = 0;
    while(--max > 0 && (c = getchar()) != EOF && c != '\n'){
        line[i++] = c; 
    }
    if(c == '\n'){
        line[i++] = c;
    }
    line[i] = '\0';
    return i;
}
