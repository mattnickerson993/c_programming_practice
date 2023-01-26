#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

/* 
    Exercise: 4-8
    Goal: Suppose there will never be more than one character of pushback. Modify getch and ungetch accordingly.
 */
int buf = EOF;

int getch(void) /* get a (possibly pushed back) character */
{
    int c, temp;
    if(buf == EOF){
        c = getchar();
        return c;
    }
    else{
        temp = buf;
        buf = EOF;
        return temp;
    }
}

void ungetch(int c) /* push character back on input */
{
    if(buf != EOF){
        printf("ungetch: too many characters\n");
        return;
    }
    buf = c;
    return;
}

int main(void)
{
    // unget a character and get a character
    ungetch('a');
    printf("%c", getch());
    printf("\n");
    return 0;
}

