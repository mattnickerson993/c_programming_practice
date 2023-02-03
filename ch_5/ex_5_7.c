
#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 100000
#define STORAGE_MAX 100000 /* storage for all chars from all lines */
/* 
	Goal: rewrite readlines to store lines in an array supplied by main, rather than calling alloc to maintain storage
	Method: use an array (storage) defined in main to hold all characters, pass the pointer each time each time a line is
			copied to lineptr array. Ensure the total storage does not exceed storage_max
*/
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines, char *storage, int storage_limit);
void writelines(char *lineptr[], int nlines);
void quicksort(char *lineptr[], int left, int right);
int get_ln(char *s, int i);

int main(void)
{	
	char storage[STORAGE_MAX];
	int nlines;
	if ((nlines = readlines(lineptr, MAXLINES, storage, STORAGE_MAX)) >= 0)
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


int readlines(char *lineptr[], int maxlines, char *storage, int storage_limit)
{
    int len, nlines;
    char line[MAXLEN];

    nlines = 0;
    while((len = get_ln(line, MAXLEN)) > 0){
		storage += len;
        if(nlines > maxlines || strlen(storage) > storage_limit){
            return -1;
        }
        else{
            line[len - 1] = '\0';
            strcpy(storage, line);
            lineptr[nlines++] = storage;
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