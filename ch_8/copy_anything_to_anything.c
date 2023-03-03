#include "syscall.h"

#define BUFSIZE 4096



int main(void){ /* copy input to output */
    char buf[BUFSIZE];
    int n;

    // 0, 1, 2 = stdnin, stdout, stderr
    while((n = read(0, buf, BUFSIZE)) > 0){
        write(1, buf, n);
    }
    return 0;

}