#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* 
  Ex: 4-9: 
    Goal: our getch and ungetch do not handle a pushed back EOF correctly. Decide what their properties ought
          to be if an EOF is pushed back, then implement your design
    Method: either change buf array to int type... this way buf will accept -1 (EOF) or handle
            or conditionally handle EOF getting passed to ungetch (below)

 */

/* reverse polish calculator */
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp;

int getch(void){
  // printf("getch bufp: %i\n", bufp);

  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
  if(bufp >= BUFSIZE){
    printf("ungetch: too many characters\n");
  }
  else if(c != EOF){
    buf[bufp++] = c;
  }
}

int main(void){
  int c;
  ungetch(EOF);

  while((c = getch()) != EOF)
  {
    putchar(c);
  }
  printf("\n");
  return 0;
}

int getch(void);
void ungetch(int);


