#include <math.h>
#include <stdio.h>

int main(void){

    struct point {
        int x;
        int y;
    };

    // struct point maxpt = {3, 4};
    
    // printf("%d, %d\n", maxpt.x, maxpt.y);

    // double dist;
    // dist = sqrt((maxpt.x * maxpt.x) + (maxpt.y * maxpt.y));
    // printf("dist: %ld\n", dist);
    
    struct point pt_a = { 2, 3};
    struct point pt_b = { 4, 5};

    struct rect {
        struct point pt1;
        struct point pt2;
    };
    
    struct  rect my_rect =
    {
        pt_a,
        pt_b
    };

    printf("pt1 x: %d\t pt2 y: %d\n", my_rect.pt1.x, my_rect.pt2.y);
    


    return 0;
}
