#include <stdio.h>
#include "hash.h"
/* "" -> relative path vs <> -> sys path */

/* 
    Goal: Write a function undef that will remove a name and definition from the table maintained by lookup and install.

*/

int main(void){
    struct nlist *p, *q;
    
    install("name", "matt");
    install("age", "36");
    install("dog", "Leo");

    p = lookup("name");
    printf("%s: %s\n", p->name, p->defn);
    install("name", "matthew");
    printf("%s: %s\n", p->name, p->defn);
    q = lookup("cowboy");
    printf("%s\n", q == NULL ? "NULL" : q->name);
    undef("cowboy");
    undef("name");
    p = lookup("name");
    printf("%s: %s\n", p == NULL ? "NULL" : p->name, p == NULL ? "NULL" : p->defn);
    install("name", "michelangelo");
    p = lookup("name");
    printf("%s: %s\n", p->name, p->defn);

}




