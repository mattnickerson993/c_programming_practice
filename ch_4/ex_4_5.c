// assistance from https://clc-wiki.net/wiki/K%26R2_solutions:Chapter_4:Exercise_5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define OTHER_MATH '1'

int getop(char []);
void swap(char stack []);
void print_top(char stack[]);
void duplicate_top(void);
void clear(char stack[]);
void push(double);
double pop(void);
void handle_other_math(char s[]);
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
    case OTHER_MATH:
      handle_other_math(s);
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


// swap top two elements of stack
void swap(char stack []){
  char temp;
  int len = strlen(stack);
  if(len < 2){
    printf("Error: must have two elements in stack to swap");
    return;
  }
  temp = stack[len - 1];
  stack[len - 1] = stack[len - 2];
  stack[len - 2] = temp;

}
// duplicate element on top of stack
void duplicate_top(void)
{
    if(sp > MAXVAL - 1)
      printf("error: stack is full, can't duplicate\n");
    double temp = pop();
    push(temp);
    push(temp);

}

// print top element of stack
void print_top(char stack []){
  int len = strlen(stack);
  if (len == 0){
    printf("empty stack");
  }
  printf("Top: %ld", stack[len - 1]);
}

// clear stack
void clear(char stack[]){
  sp = 0;
  // memset(stack, 0, sizeof(stack));
}


// other ideas below
// https://clc-wiki.net/wiki/K%26R2_solutions:Chapter_4:Exercise_4
// void showTop(void)
// {
//     if(sp > 0)
//         printf("Top of stack contains: %8g\n", val[sp-1]);
//     else
//         printf("The stack is empty!\n");
// }

// 
// void swapItems(void)
// {
//     double item1 = pop();
//     double item2 = pop();

//     push(item1);
//     push(item2);
// }

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

void handle_other_math(char s[]){
  double op2;
  // strcmp returns 0 for match
  if(!strcmp(s, "sin")){
    // sin(x)
    push(sin(pop()));
  }
  else if (!strcmp(s, "exp")){
    // ie e^x
    push(exp(pop()));
  }
  else if(!strcmp(s, "pow")){
    // x ^ y
    op2 = pop();
    push(pow(pop(), op2));
  }
  else{
    printf("unsupported function\n");
  }
}


int getop(char s[]){
  int i, c;
  while((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  
  s[1] = '\0';
  // handle cases like sin, exp, pow
  if(isalpha(c)){
      i = 0;
      while(isalpha(s[i++] = c ))
        c = getch();     
      s[i - 1] = '\0';
      if(c != EOF)
        ungetch(c);
      return OTHER_MATH;
  }

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

