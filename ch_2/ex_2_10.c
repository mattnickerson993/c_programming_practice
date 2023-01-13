#include <stdio.h>

/* 
    Goal: rewrite the function "lower" which converts uppercase chars to lowercase chars
    Method: use a conditional expression rather than an if else
 */
int lower(int c);

int main(void){

    printf("A: %c\n", lower('A'));
    printf("E: %c\n", lower('E'));
    printf("X: %c\n", lower('x'));
    printf("a: %c\n", lower('a'));
    printf("b: %c\n", lower('b'));
    printf("q: %c\n", lower('q'));
    printf("7: %c\n", lower('7'));
    return 0;
}

int lower(int c){
    return (c <= 'Z' && c >= 'A') ? c + ('a' - 'A') : c;
}