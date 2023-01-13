#include <stdio.h>

int bitcount(unsigned x);

int main(void){

    printf("%d\n", bitcount(255));
    return 0;
}


int bitcount(unsigned x){
    int b;

    for(b = 0; x != 0; x >>= 1){
        if(x & 01)
            b++;
    }
    return b;
}

/* 
Flow looks like this:
    for 15 (ie 1111)
    1111
    0111
    0011
    0001
    0000
 */