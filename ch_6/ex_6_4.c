#include <stdio.h>
#include <ctype.h>
#include <string.h>


#define MAXWORD 100
/* 
    Goal: write a program that prints the distinct words in its input sorted into the decreasing order of frequency of occurrence.
          precede each word by its count.
    Method: - binary tree used to establish words and counts. 
            - count distinct words
            - initialize array of pointers to nodes with length equivalent to # of disctinct words
            - sort array via quicksort based on counts
            - print
 */
struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};


struct tnode *addtree(struct tnode *, char *);
int treeprint(struct tnode *, int count);
int getword(char *, int);
int array_add(struct tnode *nodes[], struct tnode *, int count);
void quicksort(struct tnode *nodes[], int left, int right);

int main(void){
    char word[MAXWORD];
    struct tnode *root, *sorted_root;
    root = sorted_root = NULL;
    while((getword(word, MAXWORD) != EOF)){
        if(isalpha(word[0])){
            root = addtree(root, word);
        }
    }
    
    int count = treeprint(root, 0);
    printf("distinct word count: %d\n", count);
    struct tnode *nodes[count];
    // add to array
    int other_count = array_add(nodes, root, 0);
    // printf("other count: %d\n", other_count);
    quicksort(nodes, 0, count - 1);
    for(int i = 0; i < count; i++){
        // printf("%p\n", nodes[i]);
        printf("%4d : %s\n", nodes[i]->count, nodes[i]->word);
    }
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

int array_add(struct tnode *nodes[], struct tnode *p, int count){

    if(p == NULL){
        return count + 0;
    }
    nodes[count] = p;
    count++;
    count = array_add(nodes, p->right, count);
    count = array_add(nodes, p->left, count);

    // printf("added node, count: %d", count);
    return count;
}


int treeprint(struct tnode *p, int count){
    if(p == NULL){
        return count + 0;
    }
    count++;
    count = treeprint(p->right, count);
    // printf("%4d: %s\n", p->count, p->word);
    count = treeprint(p->left, count);
    return count;
}

void quicksort(struct tnode *nodes[], int left, int right)
{
	int i, last;
	void swap(struct tnode *nds[], int i, int j);
	if (left >= right)
		return;
	swap(nodes, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
        // printf("compare\n");
        // printf("%d : %d\n", nodes[i]->count, nodes[left]->count);
		if (nodes[i]->count > nodes[left]->count)
            // printf("if\n");
			swap(nodes, ++last, i);
	swap(nodes, left, last);
	quicksort(nodes, left, last - 1);
	quicksort(nodes, last + 1, right);
}

void swap(struct tnode *nodes[], int i, int j)
{
	struct tnode *temp;
	temp = nodes[i];
	nodes[i] = nodes[j];
	nodes[j] = temp;
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
