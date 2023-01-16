#include <stdio.h>
#include <time.h>

#define MAX_LEN 1000000
/* 
    Goal: write a binary search function but with only one test inside the main loop
          measure difference in runtime

 */
int binsearch(int x, int v[], int n);
int binsearch_v2(int x, int v[], int n);


int main(void){
    // performance
    clock_t start, end;
    double cpu_time_used;

    int i, num;
    int nums[MAX_LEN];
    for (i = 1; i < MAX_LEN; i++){
        nums[i] = i;
    }

    num = 777;


    start = clock();
    printf("Answer: %d\n", binsearch(num, nums, MAX_LEN));
    end = clock();
    cpu_time_used= ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time v1: %f\n", cpu_time_used);

    start = clock();
    printf("Answer: %d\n", binsearch_v2(num, nums, MAX_LEN));
    end = clock();
    cpu_time_used= ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time v2: %f\n", cpu_time_used);
}

int binsearch(int x, int v[], int n){
    int low, high, mid;

    low = 0;
    high = n - 1;
    while(low <= high){
        mid = (low + high) / 2;
        if ( x < v[mid]){
            high = mid - 1;
        }
        else if ( x > v[mid]){
            low = mid + 1;
        } 
        else{
            return mid;
        }
    }
    return -1;
}

int binsearch_v2(int x, int v[], int n){
    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while(low <= high && mid != x){
        if ( x < v[mid]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        } 
        mid = (low + high) / 2;
    }

    return mid == x ? mid : -1;
}
