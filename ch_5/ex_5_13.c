#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINES 5000
#define MAX_LINE_LENGTH 1000
#define STORAGE_MAX (MAX_LINE_LENGTH * MAX_LINES) 

char *lineptr[MAX_LINES];
char storage[STORAGE_MAX];

void writelines(char *lineptr[], int nlines, int cutoff);
int readlines(char *lineptr[], int nlines, char *storage, int storage_limit);

/* 
    Goal: write the program tail, which prints the last n lines of input
          by default n is 10.

          readlines to an array of pointers, defining max lines and max length of line
          keep track of last idx and jump back accordingly (default n = 10)

*/

int main(int argc, char *argv[])
{   
    // only 1 or default option
    if(argc > 2){
        printf("Usage: print last n lines\n");
        return -1;
    }

    int num_lines, c, default_cutoff, manual_cutoff;
    num_lines = readlines(lineptr, MAX_LINES, storage, STORAGE_MAX);
    // printf("lines in this file: %d\n", num_lines);
    // default display 
    default_cutoff = 10;
    manual_cutoff = 0;

    while(--argc > 0 && (*++argv)[0] == '-'){
        // printf("argv now: %s\n", *argv);
        if(isdigit(c = *++argv[0])){
            if(manual_cutoff == 0){
                // printf("argv now: %s\n", *argv);
                manual_cutoff = atoi(*argv);
            }
            
        }

    }

    // printf("cutoff: %d\n", (!manual_cutoff) ? default_cutoff : manual_cutoff);

    // set cutoff as default or manual, make sure cutoff isnt larger than num lines
    int final_cutoff = (!manual_cutoff) ? default_cutoff : manual_cutoff;
    final_cutoff = (final_cutoff > num_lines) ? num_lines : final_cutoff;
     
    writelines(lineptr, num_lines, final_cutoff);
    return 0;
}


int get_ln(char s[], int lim);

int readlines(char *lineptr[], int maxlines, char *storage, int storage_limit)
{
    int len, nlines;
    char line[MAX_LINE_LENGTH];

    nlines = 0;
    while((len = get_ln(line, MAX_LINE_LENGTH)) > 0){
		storage += len;
        if(nlines > maxlines || strlen(storage) > storage_limit){
            return -1;
        }
        else{
            line[len - 1] = '\0'; /* get rid of newline character */
            strcpy(storage, line);
            lineptr[nlines++] = storage;
        }
    }
    return nlines;
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

void writelines(char *lineptr[], int nlines, int cutoff){
    while (cutoff-- > 0){
        // printf("nlines: %d\n", nlines);
        // printf("cutoff: %d\n", cutoff);
        printf("%s\n", lineptr[nlines - cutoff -1]);
    }
}
