#include <stdio.h>

int main(void){
    char *s = "tomato";
    int max = 4;
    printf("%.*s\n", max, s);


    char *hw = "hello world";
    printf(":%s:\n", hw);
    printf(":%10s:\n", hw);
    printf(":%.10s:\n", hw);
    printf(":%-10s:\n", hw);

    long long a = 255;
    printf("%lld\n", a);

    unsigned long long b = 225;
    printf("%llu\n", b);

    float c = 2.55;
    printf("%.2f\n", c);

    int e = 255, f = 15000;
    // left padding
    printf("%8d\n%8d\n", e, f);
    // pad left space with 0's
    printf("%08d\n%08d\n", e, f);

    // hexadecimal
    printf("%x\n", e);
    // cap hex
    printf("%X\n", e);

    /* printing to different locations
        s - buffer ( ie sprintf())
        n - buffer size
        f - stream (file)
        _s - safer version (c11)
        v - can pass var args list (va_list type)

        --- most others are derivates of this
    */

    float h = 23.567;
    double i = 11e+23;

    printf("Float variable is %f\n", h);
    printf("Double variable is %e\n", i);
}