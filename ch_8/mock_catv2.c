#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* cat: concatenate files -- version 2 */

int main(int argc, char *argv[]){
    clock_t begin = clock();
    
    FILE *fp;
    void filecopy(FILE *, FILE *);
    char *prog = argv[0]; /* program name for errors */

    if(argc == 1){ /* no arg; copy standard input */
        filecopy(stdin, stdout);
    }
    else{
        while(--argc > 0){
            if((fp = fopen(*++argv, "r")) == NULL){
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                exit(1);
            }else{
                filecopy(fp, stdout);
                fclose(fp);
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


/* filecopy: copy file ifp to ofp */
void filecopy(FILE *ifp, FILE *ofp){
    int c;

    // read chars from ifp and write to ofp
    while((c = getc(ifp)) != EOF){
        putc(c, ofp);
    }
}