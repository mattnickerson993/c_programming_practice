#include <stdio.h>
#include <fcntl.h>
#include "syscall.h"
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>

void error(char *fmt, ...);
/* cat: concatenate files -- using read, write, open, close 
   runs roughly 2x as fast as mock_cat with fopen ect
*/

int main(int argc, char *argv[]){
    clock_t begin = clock();

    int fd;
    void filecopy(int, int);
    char *prog = argv[0]; /* program name for errors */

    if(argc == 1){ /* no arg; copy standard input */
        filecopy(0, 1);
    }
    else{
        while(--argc > 0){
            if((fd = open(*++argv, O_RDONLY, 0)) == -1){
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                exit(1);
            }else{
                filecopy(fd, 2);
                close(fd);
            }
        }
    }
    if(ferror(stdout)){
        fprintf(stderr, "%s: error writing stdout\n", prog);
    }
    
    clock_t end = clock();
    double time_spent = (double) (end - begin)/ CLOCKS_PER_SEC;
    printf("execution time: %f\n", time_spent);
    exit(0);
}

#define BUFSIZE 4096

/* filecopy: copy file ifp to ofp */
void filecopy(int fd_i, int fd_t){
    int n;
    char buf[BUFSIZE];

    while((n = read(fd_i, buf, BUFSIZE)) > 0){
        if(write(fd_t, buf, n) != n){
            error("cat: write error on file");
        }
    }

    // read chars from ifp and write to ofp
    // while((c = getc(ifp)) != EOF){
    //     putc(c, ofp);
    // }
}

#include <stdlib.h>
#include <stdarg.h>

/* error: print an error message and die */

void error(char *fmt, ...){
    
    va_list args;

    va_start(args, fmt);
    fprintf(stderr, "error: ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(1);
}