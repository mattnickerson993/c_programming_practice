#include <stdio.h>


void printd(int n);

int main(void){
    int i = 102;
    printd(i);
    printf("\n");
    return 0;
}


void printd(int n){
    // output negative and set to positive
    if (n < 0){
        putchar('-');
        n = -n;
    }
    if(n / 10){ // ie not on last digit
        printd(n / 10);
    }

    putchar(n % 10 + + '0'); // last digit
}


