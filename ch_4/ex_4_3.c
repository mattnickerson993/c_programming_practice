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
  int i, c, sign;
  sign = 1;
  while((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  
  s[1] = '\0';
  if(!isdigit(c) && c != '.' && c != '-'){
    return c;
  }
  i = 0;

  if (c == '-'){
    int next = getch();
    // actually a subtract
    if(!(isdigit(next)) && next != '.'){
      ungetch(next);
      return c;
    }
    else{
      // its a negative number
      c = next;
      s[++i] = c;
    }
  }
  if(isdigit(c)){
    while(isdigit(s[++i] = c = getch()))
      ;
  }
  if(c == '.'){
    while(isdigit(s[++i] = c = getch()))
      ;
  }
  s[i] = '\0';
  if(c != EOF){
    ungetch(c);
  }
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

