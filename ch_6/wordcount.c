#include <stdio.h>
#include <ctype.h>
#include <string.h>


#define MAXWORD 100

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};


struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);


int main(void){
    char word[MAXWORD];
    struct tnode *root;
    root = NULL;
    while((getword(word, MAXWORD) != EOF)){
        if(isalpha(word[0])){
            root = addtree(root, word);
        }
    }
    treeprint(root);
}

struct tnode *talloc(void);
char *str_dup(char *);

/* addtree add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w){
    int cond;

    if (p == NULL){ /* a new word has arrived */
        p = talloc(); /* make a new node */
        p->word = str_dup(w);
        p->count = 1;
        p->left = p->right = NULL;
        
    }else if((cond = strcmp(w, p->word)) == 0){
        p->count++;
    }
    else if (cond < 0 ){
       p->left = addtree(p->left, w);
    }
    else{
       p->right = addtree(p->right, w);
    }
    return p;

}

#include <stdlib.h>

/* talloc make a tnode */
struct tnode *talloc(void){
    return (struct tnode *) malloc(sizeof(struct tnode));
}

/* make a duplicate of s */
char *str_dup(char *s){
    char *p;

    p = (char *) malloc(strlen(s) + 1); /* +1 for '\0' */
    if(p != NULL){ /* memory available */
        strcpy(p, s);
    }
    return p; 
}

void treeprint(struct tnode *p){
    if(p == NULL){
        return;
    }
    treeprint(p->left);
    printf("%4d: %s\n", p->count, p->word);
    treeprint(p->right);
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
