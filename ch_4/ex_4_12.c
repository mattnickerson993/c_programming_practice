#include <string.h>
#include <stdio.h>


#define MAXLEN 100

/* 
    Goal: write a recursive version of itoa
 */
enum boolean {FALSE, TRUE};
void itoa_helper(int n, char s[], int idx);
void itoa(int n, char s[]);
void reverse(char line[], int len);


int main(void){
    int i = 4367534;
    int idx = 0;
    char s[MAXLEN];
    
    itoa(i, s);
    printf("final: %s\n", s);
    return 0;
}

void reverse(char line[], int len){
  int idx, end, temp;
  idx = 0;
  end = len - 1;
  while(idx < end){
    // the ole swaperooo
    temp = line[end];
    line[end] = line[idx];
    line[idx] = temp;
    idx ++;
    end --;
  }
  line[len] = '\0';
}

void itoa_helper(int n, char s[], int idx){
    // printf("Here's idx: %d\n", idx);
    char digit;

    digit = n % 10 + '0';
    s[idx] = digit;

    if(n / 10){
        itoa_helper(n/10, s, ++idx);
    }
}    


void itoa(int n, char s[]){

    int is_negative = FALSE;
    
    if(n < 0){
        is_negative = TRUE;
        n = -n;
    }

    itoa_helper(n, s, 0);
    int len = strlen(s);
    if (is_negative){
        s[len] = '-';
        len++;
    int len = strlen(s);
    }
    reverse(s, len);
}