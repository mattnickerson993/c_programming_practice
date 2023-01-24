#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int argc, char **argv, char **envp){
    
    for(int i = 0; envp[i] != NULL; i++){
        printf("%d: %s\n", i, envp[i]);
    }
    // another way
    for(int i = 0; environ[i] != NULL; i++){
        printf("%d: %s\n", i, environ[i]);
    }
}


    