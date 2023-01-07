#include <stdio.h>

/*
Convert celsius to fahrenheit 
with a range from 0 - 100 and a step of 10 */

int main(void){
    float cels, fahr;
    int lower, upper, step;
    lower = 0;
    upper = 100;
    step = 10;

    cels = lower;
    printf("Celsius Fahrenheit\n");
    while (cels <= upper){
        fahr = (9.0 / 5.0 * cels) + 32.0;
        printf("%3.0f %10.0f\n", cels, fahr);
        cels += step;
    }
}