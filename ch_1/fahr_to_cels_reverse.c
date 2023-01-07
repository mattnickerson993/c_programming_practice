#include <stdio.h>

/*
use for loop to convert from fahrenheit temp to 
celsius temp ranging from 300 to 0
*/

int main(void){
    float fahr, cels;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("Fahrenheit Celsius\n");
    for (fahr = upper, fahr >= 0, fahr += step){
        printf("%3.0f %10.0f", fahr, ((5.0/9.0 * fahr) - 32));
    }

    
}