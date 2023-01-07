#include <stdio.h>

/*
print Fahrenheit-Celsius table
for fahr = 0, 20, 40 ..., 300
*/

int main(void){
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("Fahrenheit Celcius\n");
    while (fahr <= upper){
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%3.0f %12.1f\n", fahr, celsius);
        fahr += step;
    }
}