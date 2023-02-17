#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100


// struct key {
//     char *word;
//     int count;
// } keytab[NKEYS];


/* i like the way below better */
struct key{
    char *word;
    int count;
};

struct key keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0
};

#define NKEYS (sizeof keytab / sizeof(struct key))
// or (sizeof keytab / sizeof keytab[0])


int getword(char *, int);
int binsearch(char *, struct key *, int);


int main (void){
    int n;
    char word[MAXWORD];

    while(getword(word, MAXWORD) != EOF){
        if(isalpha(word[0])){
            if((n = binsearch(word, keytab, NKEYS)) >= 0 ){
                keytab[n].count++;
            }
        }
    }
    for(n = 0; n < NKEYS; n++){
        if(keytab[n].count > 0){
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
        }
    }
    return 0;
}

/* find word in tab[0] ... tab[n - 1] */
int binsearch(char *word, struct key tab[], int n){
    int cond;
    int low, high, mid;
    low = 0;
    high = n - 1;
    while(low <= high){
        mid = (low + high) / 2;
        if((cond = strcmp(word, tab[mid].word)) < 0){
            high = mid - 1;
        }
        else if(cond > 0){
            low = mid + 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}



int getword(char *word, int lim){
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    // move through spaces
    while(isspace(c = getch())){
        ;
    }
    // if we found a char that isn't a space prior to EOF
    if(c != EOF){
        *w++ = c;
    }
    // if its not alphabetical we don't care about it... mark null(ie end of word) and return it
    // also accounts for returning EOF
    if(!isalpha(c)){
        *w = '\0';
        return c;
    }
    // otherwise keep adding alphanum chars to word until limit
    for( ; --lim > 0; w++){
        if(!isalnum(*w = getch())){
            // stop if exception to alpha num is found -- put it back on the stack
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    // wont be EOF
    return word[0];
}

#define BUFSIZE 100000

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
