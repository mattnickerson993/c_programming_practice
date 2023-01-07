#include <stdio.h>

float fahr_to_cels(float fahr_temp);

int main(void){
    int i;
    float low, high, step;
    low = 0;
    high = 300;
    step = 20;
    printf("Fahr Cels\n");
    for(i = low; i <= high; i += step){
        // printf("%d\n", i);
        printf("%3d %6.1f\n", i, fahr_to_cels(i));
    }
}

float fahr_to_cels(float f){
    return (5.0/9.0) * (f - 32.0);
}