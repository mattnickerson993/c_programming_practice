# include <stdio.h>

int main(void){
    long nc;
    nc = 0;
    while(getchar() != EOF){
        ++nc;
    }
    printf("Char Count: %ld\n", nc);
}