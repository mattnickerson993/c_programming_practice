#include <stdio.h>


#define XMAX 10
#define YMAX 10
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

struct point {
    int x;
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
};


int main(void){
    
    struct rect screen;
    struct point middle, add_res;
    struct point makepoint(int x, int y);
    struct point addpoint(struct point p1, struct point p2);
    int ptinrect(struct point p, struct rect r);
    struct rect canonrect(struct rect r);

    screen.pt1 = makepoint(0, 0);
    screen.pt2 = makepoint(XMAX, YMAX);
    middle = makepoint((screen.pt1.x + screen.pt2.x) / 2,
                       (screen.pt1.y + screen.pt2.y) /  2);
    printf("middle.x: %d\t middle.y: %d\n", middle.x, middle.y);
    add_res = addpoint(screen.pt1, screen.pt2);
    printf("addres.x: %d\t add_res.y: %d\n", add_res.x, add_res.y);

    printf("ptinrect: %d\n", ptinrect(makepoint(5, 5), screen));
    printf("ptinrect: %d\n", ptinrect(makepoint(15, 15), screen));
    
    struct point origin, *pp;

    origin.x = 12;
    origin.y = 11;
    pp = &origin;
    printf("origin is (%d,%d)\n", (*pp).x, (*pp).y);
    printf("origin addresses is %p\n", pp);
    printf("origin is (%d,%d)\n", pp->x, pp->y);
}

/* makepoint: make a point from x and y components */
struct point makepoint(int x, int y){
    struct point temp;

    temp.x = x;
    temp.y = y;
    return temp;
}

/* addpoint: add two points */
struct point addpoint(struct point p1, struct point p2){
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

/* ptinrect: return 1 if p in r, 0 if not */    
int ptinrect(struct point p, struct rect r){
    return p.x >= r.pt1.x && p.y >= r.pt1.y
            && p.y < r.pt2.y && p.x < r.pt2.x;
}

/* canonicalize coordinates of rectangle */
struct rect canonrect(struct rect r){
    struct rect temp;

    temp.pt1.x = min(r.pt1.x, r.pt2.x);
    temp.pt1.y = min(r.pt1.y, r.pt2.y);
    temp.pt2.x = max(r.pt1.x, r.pt2.x);
    temp.pt2.y = max(r.pt1.y, r.pt2.y);
    return temp;
}
