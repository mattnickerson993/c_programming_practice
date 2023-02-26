#ifndef STRUCT_DEF
#define STUCT_DEF

struct nlist { /* table entry */
    struct nlist *next; /* next entry in chain */
    char *name; /* defined name */
    char *defn; /* replacement text */
};
#endif

#ifndef HASHSIZE
#define HASHSIZE 101
#endif

static struct nlist *hashtab[HASHSIZE];
unsigned hash(char *s);
struct nlist *lookup(char *s);
char * str_dup(char *);
struct nlist *install(char *name, char *defn);
void undef(char *name);

