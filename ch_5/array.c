#include <stdio.h>

/* working on distinctions/understand of arrays and pointers */

int main(void){
    char arr_1[10] = "abcdefghij";

    // printf("array start: %p\t array start: %p\t array start: %p\n", arr_1, &arr_1, &arr_1[0]);
    // printf("array[0]: %c\t array[0]: %c\t array[0]: %c\n", arr_1[0], *arr_1, *(&arr_1[0]));

    for(int i = 0; i < 10; i++){
        printf("array[%d]: %c\t  array[%d]: %c\n", i, arr_1[i], i, *arr_1);
        (*arr_1)++;
        // printf("array[%d]: %c\t array[%d]: %c\n", i, arr_1[i], i, (*arr_1)++);
    }
    return 0;
}