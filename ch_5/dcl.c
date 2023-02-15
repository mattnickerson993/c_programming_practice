#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);

int gettoken(void);
int tokentype; /* type of last token */
char token[MAXTOKEN]; /* last token string */
char name[MAXTOKEN]; /* identifier name */
char datatype[MAXTOKEN]; /* data type = char, int, etc. */
char out[1000]; /* output string */

int main(void){
    while(gettoken() != EOF){ /* 1st token on line */
        strcpy(datatype, token); /* is the datatype */
        out[0] = '\0';
        dcl(); /* parse rest of line */
        if (tokentype != '\n'){
            printf("syntax error\n");
        }
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}

int gettoken(void){
    // resume here
    return 0;
}




/* dcl: parse a declarator */


void dcl(void){

    int ns;

    for(ns = 0; gettoken() == '*';) /* count *'s */
        ns++;
    dircl();
    while(ns-- > 0){
        strcat(out, " pointer to");    
    }
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


void dirdcl(void){
    int type;

    if(tokentype == '('){ /* ( dcl ) */
        dcl();
        if(tokentype != ')'){
            printf("error: missing )\n");
        }else if(tokentype == NAME){
            strcpy(name, token);
        }else{
            printf("error: expected name or (dcl)\n");
        }
        while((type = gettoken()) == PARENS || type == BRACKETS){
            if(type == PARENS){
                strcat(out, " function returning");
            }else{
                strcat(out, " array");
                strcat(out, token);
                strcat(out, " of");
            }
        }
    }
}