#include <stdio.h>
#include <string.h>

#define MAXLEN 100

void reverse(char s[],int start, int end);


int main(void){
    char s[] = "ardvark";
    printf("string before: %s\n", s);
    reverse(s, 0, strlen(s) - 1);
    printf("string after: %s\n", s);
    return 0;
}

// recursive version
void reverse(char s[], int start, int end){
    if (start >= end){
        return;
    }
    int temp = s[start];
    s[start] = s[end];
    s[end] = temp;
    reverse(s, ++start, --end);
    // still want null char at end
    if(start == 0){
        s[end + 1] == '\0';
    }
}