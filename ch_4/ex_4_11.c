#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);

/* reverse polish calculator */

/* 
  Ex 4-11: write getop without the need for ungetch (can also write it without getch)
 */
int main(void){
  int type;
  double op2;
  char s[MAXOP];

  while((type = getop(s)) != EOF){
    switch (type)
    {
    case NUMBER:
      // printf("num called");
      // printf("s : %s, len: %i\n", s, strlen(s));

      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0){
        push(pop() / op2);
      }
      else{
        printf("Error: zero divisor\n");
      }
      break;
    case '%':
      op2 = pop();
      if (op2 == 0.0){
        printf("Error: zero mod\n");
      }
      else{
        push(fmod(pop(), op2));
      }
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    default:
      printf("Error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}

#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

void push(double f){
  if(sp < MAXVAL){
    val[sp++] = f;
    // printf("pushing f: %f  sp: %i", f, sp);
  }
  else{
    printf("error: stack full, cant push %g\n", f);
  }
}

double pop(void){
  if(sp > 0){
    // printf("pop called: sp: %i", sp);
    return val[--sp];
  }
  else{
    printf("error: stack empty\n");
    return 0.0;
  }
}


#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[]){
  // just assign the char (c) to buf variable (which persists)
  // since buffer never decrements you also dont need the getch helper (it would just call getchar every time)
  static char buf = EOF;
  int i, c;
  if (buf == EOF || buf == ' ' || buf == '\t') {
        while ((s[0] = c = getchar()) == ' ' || c == '\t')
            ;
        s[1] = '\0';
  }else{
      c = buf;
  }
  if (!isdigit(c) && c != '.')
      return c;   /* not a number */
  i = 0;
  if (isdigit(c)) /* collect integer part */
      while (isdigit(s[++i] = c = getchar()))
          ;
  if (c == '.')   /* collect fraction part */
      while (isdigit(s[++i] = c = getchar()))
          ;
  s[i] = '\0';
  if (c != EOF)
      buf = c;
  return NUMBER;
}

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
  else{
    buf[bufp++] = c;
  }
}

