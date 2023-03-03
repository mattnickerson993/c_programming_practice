#include <stdio.h>
#include <fcntl.h>
#include "syscall.h"
#define PERMS 0666 /* RW for owner, group, others */
#define BUFSIZE 4096

void error(char *, ...);

/* cp: copy f1 to f2 */

int main(int argc, char *argv[]){
    int f1, f2, n;
    char buf[BUFSIZ];
    // continue here
}