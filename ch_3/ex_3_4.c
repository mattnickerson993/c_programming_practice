#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAXLEN 1000
void itoa(int n, char s[]);
void itoa_v2(int n, char s[]);
void reverse(char line[], int len);


int main(void){
    int i = -378;
    char s[MAXLEN];
    char s_1[MAXLEN];
    itoa(i, s);
    itoa_v2(i, s_1);
    printf("%s\n", s);
    printf("%s\n", s_1);
    return 0;
}


// use the standard reversing array with temp var trick --- set last char to null for completeness
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

void itoa(int n, char s[]){
    int i, sign;

    if((sign = n) < 0){
        n = -n;
    }
    i = 0;
    do{
        s[i++] = n % 10 + '0';
    }while((n /= 10) > 0);
    if(sign < 0){
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s, strlen(s));
}

void itoa_v2(int n, char s[]){
    int i, sign;
    i = 0;
    sign = n;

    do{
        s[i++] = abs(n % 10) + '0';
    }while(n /= 10);

    if(sign < 0){
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s, strlen(s));
}