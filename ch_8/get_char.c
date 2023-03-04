#include "syscall.h"
#include <stdio.h>

#define BUFSIZE 4096

/* getchar: unbufferred single char input */

// read 1 char at a time
// int get_char(void){
//     char c;

//     return (read(0, &c, 1) == 1 ) ? (unsigned char) c: EOF;
// } 


// buffered version -- ie put all chars in buffer initially and read them from buffer
int get_char(void){
    static char buf[BUFSIZE];
    static char *bufp = buf;
    static int n = 0;

    if (n == 0){ /* buffer is empty --- reads on first and last pass */
        // printf("first read\n");
        n = read(0, bufp, sizeof buf);
        // printf("n: %d\n", n);
        bufp = buf;
    }
    return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
} 


int main(void){
    int c;

    while((c = get_char()) != EOF){
        // printf("called\n");
        printf("%c", c);
    }
    printf("\n");
    return 0;
}
