
/* copy t to s */
void strcpy(char *s, char *t)
{
    int i;

    i = 0;
    while((s[i] = t[i]) != '/0'){
        i++;
    }
}

void strcpy_a(char *s, char *t)
{
    while((*s = *t) != '\0'){
        s++;
        t++;
    }
}

void strcpy_b(char *s, char *t)
{
    while((*s++ = *t++) != '\0'){
        ;
    }
}

void strcpy_c(char *s, char *t)
{
    while(*s++ = *t++){
        ;
    }
}