#include <stdio.h>

int main(void){
    int x = 1, y = 2, z[10];
    int *ip;

    ip = &x;
    printf("ip: %p\t *ip: %d\n", ip, *ip);
    y = *ip;
    printf("y: %d\n", y);
    *ip = 0;
    printf("ip: %p\t *ip: %d\n", ip, *ip);
    printf("x: %d\t y:%d \n", x, y);
    ip = &z[0];
    printf("ip: %p\t *ip: %d\n", ip, *ip);

}