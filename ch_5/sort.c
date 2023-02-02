
#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 100000
/* 
    Goal: sort lines (a-z). 
    Method: Read all lines into an array of pointers. Sort each line via quicksort. Print sorted lines

*/
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void quicksort(char *lineptr[], int left, int right);
int get_ln(char *s, int i);

int main(void)
{
	int nlines;
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
	{
		quicksort(lineptr, 0, nlines - 1);
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
    int i;
    for(i = 0; i < nlines; i++){
        printf("%s\n", lineptr[i]);
    }
}


void quicksort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);
	if (left >= right)
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	quicksort(v, left, last - 1);
	quicksort(v, last + 1, right);
}

void swap(char *v[], int i, int j)
{
	char *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}