/* source https://clc-wiki.net/wiki/K%26R2_solutions:Chapter_5:Exercise_15*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLINES 5000
#define MAXLEN 100000




char *lineptr[MAXLINES];


int strcmp_f(char *s, char *t);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int reverse);

void q_sort(void *lineptr[], int left, int right,
			int (*comp)(void *, void *));

int numcmp(char *, char *);

int get_ln(char *s, int i);

int main(int argc, char *argv[])
{
	int nlines, c;
	int numeric = 0, reverse = 0, fold = 0;
    

	while(--argc > 0 && (*++argv)[0] == '-'){
		while(c = *++argv[0]){
			switch (c)
			{
			case 'n':
				printf("numeric\n");
				numeric = 1;
				break;
			case 'r':
				printf("reverse\n");
				reverse = 1;
				break;
			case 'f':
				printf("fold\n");
				fold = 1;
				break;
			default:
				break;
			}
		}
	}

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
	{
		
		q_sort((void **) lineptr, 0, nlines -1,
				(int (*)(void*,void*))(numeric ? numcmp : fold ? strcmp_f : strcmp));
		writelines(lineptr, nlines, reverse);
	
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

void writelines(char *lineptr[], int nlines, int reverse)
{
	int i = reverse ? nlines : 0;
    while(nlines-- > 0){
        printf("%s\n", reverse ? lineptr[--i] : lineptr[i++]);
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


/* strcmp_f */
int strcmp_f(char *s, char *t)
{
    for ( ; toupper(*s) == toupper(*t); s++, t++)
        if (*s == '\0')
            return 0;

    return toupper(*s) - toupper(*t);
}