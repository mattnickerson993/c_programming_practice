#include <stdio.h>
#include <limits.h>
#include <float.h>

/*
Goal: Write a program to determine the ranges of char, short, int and long variables
      (both signed and unsigned).
 */

int main(void){
    // 1 BYTE (2 ^ 8)
    printf("Char stats: \n");
    printf("bits: %d\n", CHAR_BIT);
    printf("Unsigned Char max: %d\n", UCHAR_MAX);
    printf("Signed Char max: %d\n", SCHAR_MAX);
    printf("Signed Char max: %d\n", SCHAR_MIN);
    printf("Char min: %d\n", CHAR_MAX);
    printf("Char min: %d\n", CHAR_MIN);
    printf("\n");
    // 2 BYTES (2 ^ 16)
    printf("\n");
    printf("Short stats: \n");
    printf("Unsigned Short Max: %u\n", USHRT_MAX);
    printf("Signed Short Max: %d\n", SHRT_MAX);
    printf("Signed Short Min: %d\n", SHRT_MIN);
    printf("\n");

    // 4 bytes (2 ^ 32)
    printf("Int stats: \n");
    printf("Unsigned int max: %u\n", UINT_MAX);
    printf("Signed int max: %d\n", INT_MAX);
    printf("Signed int min: %d\n", INT_MIN);
    printf("\n");

    // 8 bytes (2 ^ 64)
    printf("Long stats: \n");
    printf("Unsigned Long max: %lu\n", ULONG_MAX);
    printf("Signed Long max: %ld\n", LONG_MAX);
    printf("Signed Long min: %ld\n", LONG_MIN);
    printf("\n");

    // 8 bytes (2 ^ 64)
    printf("Long Long stats: \n");
    printf("Unsigned Long Long: %llu\n", ULLONG_MAX);
    printf("Signed Long Long Max: %lld\n", LLONG_MAX);
    printf("Signed Long Long Min: %lld\n", LLONG_MIN);
    printf("\n");
    return 0;
}



/*
Notes: 
https://stackoverflow.com/questions/29592898/do-long-long-and-long-have-same-range-in-c-in-64-bit-machine

C has two kinds of integral types :

traditionals : short, int, long, long long. It is up to each implementation to define what size
those types are. C just specifies that sizeof(short) <= sizeof(int) <= sizeof(long) <= sizeof(long long)
(ref 6.3.1.1 in final draft of C1X). With those types you can never be sure which one is 32 or 64 bits long
because it is explicitly implementation dependent
explicits : int8_t, int16_t, int32_t, int64_t - when they exist you can be sure of their size. Standard say
they should be declared in stdint.h, but unfortunately, they are all optional - that means you cannot be sure
they exist even if all major implementation support int16_t, int32_t and int64_t (ref : 7.20 and 7.20.1.1 of 
above draft) 
 */