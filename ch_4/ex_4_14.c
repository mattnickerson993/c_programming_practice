#include <stdio.h>

#define swap(t, x, y) {t temp = y; y = x; x = temp;}

/* 
    Goal: define a macro swap(t, x, y) that interchanges two arguments of type t
 */

int main(void){
    char s[] = "ab";
    swap(char, s[0], s[1]);
    printf("%s\n", s);

    int nums[] = {1, 3};
    swap(int, nums[0], nums[1]);
    int i;
    for(i = 0; i < 2; i++){
        printf("%d",nums[i]);
    }
    printf("\n");
    
    return 0;
}