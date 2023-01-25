#include <stdio.h>


void qsort(int v[], int i, int j);

int main(void){
    int i;
    int nums[] = {5, 9, 3, 6, 7, 8, 24, 32};
    int size = sizeof(nums) / sizeof(int);
    // printf("size: %d", size);A
    qsort(nums, 0, size);
    for(i = 1; i <= size; i++){
        printf("%d", nums[i]);
    }
    printf("\n");

    return 0;
}



void qsort(int v[], int left, int right){
    int i, last;
    void swap(int v[], int i, int j);

    if(left >= right){
        return;
    } 
    swap(v, left, (left+right)/2);
    last = left;
    for(i = left + 1; i <= right; i++){
        if(v[i] < v[left]){
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);

}

/* swap: interchange v[i] and v[j] */

void swap(int v[], int i, int j){
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}