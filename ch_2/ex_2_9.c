#include <stdio.h>


/* 
 Goal: x &= (x - 1) always deletes the rightmost 1-bit in x --- makes sense as the integer must differ by 1
    - rewrite bitcount using this principle
    - as a result a faster version can be written as every successful loop through x &= (x - 1) indicates the presence
      of a 1.

 */

int bitcount(unsigned x);
int bitcount_v2(unsigned x);

int main(void){
    int x = 9;
    // printf("%d\n", x &= (x -1));
    printf("%d\n", bitcount(8));
    printf("%d\n", bitcount_v2(8));
    printf("%d\n", bitcount(75));
    printf("%d\n", bitcount_v2(75));
    printf("%d\n", bitcount(0));
    printf("%d\n", bitcount_v2(0));
    printf("%d\n", bitcount(255));
    printf("%d\n", bitcount_v2(255));
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

int bitcount_v2(unsigned x){
    int b;

    for(b = 0; x != 0; x &= (x-1)){
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