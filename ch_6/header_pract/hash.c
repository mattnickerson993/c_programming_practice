#include <string.h>
#include <stdlib.h>
#include "hash.h"

/* output hash value for given string */
unsigned hash(char *s){
    unsigned hashval;

    for(hashval = 0; *s != '\0'; s++){
        hashval = *s + 31 * hashval;
    }
    return hashval % HASHSIZE;

}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s){
    struct nlist *np;

    /* lookup entry in hashtab --- traverse linked list */
    for(np = hashtab[hash(s)]; np != NULL; np = np ->next){
        if(strcmp(s, np->name) == 0){
            return np; /* found name in hash table */
        }
    }
    return NULL; /* not found */    
}

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn){
    struct nlist *np;
    unsigned hashval;

    if((np = lookup(name)) == NULL){ /* not found */
        np = (struct nlist *) malloc(sizeof(*np));
        if(np == NULL || (np->name = str_dup(name)) == NULL){
            return NULL;
        }
        hashval = hash(name);
        // np gets added to the beginning of the linked list;
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }else{ /* already in hash table ---- name doesn't change but definition gets rewritten*/
        // free memory that held defn
        free((void *) np->defn);
    }
    if((np->defn = str_dup(defn)) == NULL){ /* memory not present */
        return NULL;
    }
    return np;
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

void undef(char *s){
    struct nlist *prev, *curr;

    unsigned hashval = hash(s);

    /* lookup entry in hashtab --- traverse linked list */
    for(prev = NULL, curr = hashtab[hashval]; curr != NULL; prev = curr, curr = curr ->next){
        if(strcmp(s, curr->name) == 0){
            if (prev != NULL){
                prev->next = curr->next;
            }else{
                hashtab[hashval] = curr->next;
            }
            free((struct nlist *) curr ->next );
            free((void *) curr->defn);
            free((void *) curr->name);
            return; /* found name in hash table */
        }
    }
    return; /* not found */    


}