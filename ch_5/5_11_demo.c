
#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 100000

/* 
	Sort lines as in sort.c but use pointers to functions to demo utility
*/

char *lineptr[MAXLINES];


int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void q_sort(void *lineptr[], int left, int right,
			int (*comp)(void *, void *));

int numcmp(char *, char *);

int get_ln(char *s, int i);

int main(int argc, char *argv[])
{
	int nlines;
	int numeric = 0;

	if(argc > 1 && strcmp(argv[1], "-n") == 0){ /* strcmp returns 0 on match */
		numeric = 1;
	}
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
	{
		
		q_sort((void **) lineptr, 0, nlines -1,
				(int (*)(void*,void*))(numeric ? numcmp : strcmp));
		writelines(lineptr, nlines);
	
		return 0;
	}
	else
	{
		printf("error: input too big to sort\n");
		return 1;
	}
}

int get_ln(char s[], int lim)
{
	int c, i = 0;
	while (i < lim - 1 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}


#define ALLOCSIZE 10000


static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

// return value is a pointer
char *alloc(int n)
{
    if(allocbuf + ALLOCSIZE - allocp >= n) {/* it fits */
        allocp += n;
        return allocp - n; /* old pointer */
    }else /* not enough room */
        return 0;
}


void afree(char *p) /* free storage pointed to by p */
{
    if(p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while((len = get_ln(line, MAXLEN)) > 0){
        if(nlines > maxlines || (p = alloc(len)) == NULL){
            return -1;
        }
        else{
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    while(nlines-- > 0){
        printf("%s\n", *lineptr++);
    }
}


void q_sort(void *v[], int left, int right, int (*comp) (void *, void *))
{
	int i, last;
	void swap(void *v[], int, int);
	if (left >= right)
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if ((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	q_sort(v, left, last - 1, comp);
	q_sort(v, last + 1, right, comp);
}

void swap(void *v[], int i, int j)
{
	void *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}


#include <stdlib.h>

/* numcmpL compare s1 and s2 numerically  */

int numcmp(char *s1, char *s2)
{
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);
	if(v1 < v2){
		return -1;
	}
	else if (v1 > v2){
		return 1;
	}
	else{
		return 0;
	}
}


