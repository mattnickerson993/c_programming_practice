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
    "_dummy_underscore", 0,
    "my_underscore", 0,
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
    char word[MAXWORD];
    struct key *p;
    // printf("sizeof keytab: %lu\n", sizeof(keytab));
    // printf("sizeof key: %lu\n", sizeof(struct key));
    // printf("res: %d\n", strcmp("_dummy_underscore", keytab[7].word));
    // printf("res: %d\n", binsearch("_dummy_underscore", keytab, NKEYS));
    while(getword(word, MAXWORD) != EOF){
        // printf("word: %s\n", word);
        if(isalpha(word[0])){
            if((p = binsearch(word, keytab, NKEYS)) >= 0 ){
                p->count++;
            }
        }
    }
    for(p = keytab; p < keytab + NKEYS; p++){
        if(p->count > 0){
            printf("%4d %s\n", p->count, p->word);
        }
    }
    return 0;
}

// still needs pointer refactor
/* find word in tab[0] ... tab[n - 1] */
int binsearch(char *word, struct key tab[], int n){
    int cond;
    int low, high, mid;
    low = 0;
    high = n - 1;
    while(low <= high){
        mid = (low + high) / 2;
        printf("strcmp(%s, %s) = %d\n", word, tab[mid].word, strcmp(word, tab[mid].word));
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
    // if its not alphanumeric we don't care about it... mark null(ie end of word) and return it
    // also accounts for returning EOF
    if(!isalpha(c) && c != '_'){
        *w = '\0';
        return c;
    }
    // otherwise keep adding alphanum chars to word until limit
    for( ; --lim > 0; w++){
        c = getch();
        if(!isalnum(c) && c != '_'){
            // stop if exception to alpha num is found -- put it back on the stack
            ungetch(c);
            break;
        }
        *w = c;
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
