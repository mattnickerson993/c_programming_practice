#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buffer */

int getch(void) /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void ungets(char s[]){
    int len = strlen(s);
    while(len){ /* load the string backwards so it can be retrieved in the desired order from the stack/buffer */
        ungetch(s[--len]);
    }
    return;
}

int main(void){
    char s[] = "test string.";
    int c;
    ungets(s);
    while((c = getch()) != EOF)
        printf("%c", c);
    printf("\n");

    return 0;
}


// other ideas--- 
//https://clc-wiki.net/wiki/K%26R2_solutions:Chapter_4:Exercise_7https://clc-wiki.net/wiki/K%26R2_solutions:Chapter_4:Exercise_7

// #include <stdio.h>
// #include <string.h>

// #define BUFSIZE 100
// char buf[BUFSIZE];
// int bufp = 0;

// int getch(void)
// {
// 	return bufp > 0 ? buf[--bufp] : getchar();
// }

// void ungetch(int c)
// {
// 	if(bufp >= BUFSIZE)
// 		printf("error: stack is full, can't execute ungetch()\n");
// 	else
// 		buf[bufp++] = c;
// }

// void ungets(char *s)
// {
// 	int i, len;
// 	len = strlen(s);
// 	if(BUFSIZE - bufp >= len)  // ungets() must do its own bounds checking
// 	{
// 		for(i = strlen(s) - 1; i >= 0; i--)
// 			ungetch(s[i]);
// 	}
// 	else
// 		printf("error: insufficient space in buffer, can't execute ungets()\n");
// }

// int main()
// {
// 	char s[] = "Rapa chika paka, raja babu\n";
// 	int c;
// 	ungets(s);
// 	while((c = getch()) != EOF)
// 		putchar(c);
// 	return 0;
// }