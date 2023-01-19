#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000
/*
    Goal: Write a version of iota that accepts three arguments instead of two. The third argument is a minimum field width
    ; the converted number must be padded with blanks on the left if necessary to make it wide enough
 */

void reverse(char line[], int len);
void orig_itoa(int n, char s[]);
void iota(int n, char s[], int min_width);

int main(void){
    int n = 255;
    int min_width = 10;
    char s[MAX_LEN];
    // orig_itoa(n, s);
    iota(n, s, min_width);
    printf("%s\n", s);
    printf("Actual Length: %d\n", strlen(s)); 
    return 0;
}


void orig_itoa(int n, char s[]){
    int i, sign;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do{
        s[i++] = n % 10 + '0';
    }while((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s, strlen(s));
}

void reverse(char line[], int len){
  int start, end, temp;
  start = 0;
  end = len - 1;
  while(start < end){
    // the ole swaperooo
    temp = line[end];
    line[end] = line[start];
    line[start] = temp;
    start ++;
    end --;
  }
  line[len] = '\0';
}

void iota(int n, char s[], int min_width){

    int i, sign, current_len;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do{
        s[i++] = n % 10 + '0';
    }while((n /= 10) > 0 && i < min_width);
    if (sign < 0)
        s[i++] = '-';
    //add empty spaces to make min_width requirement
    while(i < min_width){
        s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s, strlen(s));    
    
}