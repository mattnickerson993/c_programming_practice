#include <stdio.h>

#define MAXLINE 1000

int get_ln(char *s, int i);

int main(void){
    // int day, year;
    // char monthname[20];

    // ex: 25 Dec 1988
    // scanf("%d %s %d", &day, monthname, &year);

    // ex: mm/dd/yy
    // int day, month, year;
    // scanf("%d/%d/%d", &month, &day, &year);
    // printf("day: %d\tmonth: %d\tyear: %d\n", day, month, year);

    int day, year, month;
    char monthname[20];
    char line[MAXLINE];
    while(get_ln(line, sizeof(line)) > 0){
        if(sscanf(line, "%d %s %d", &day, monthname, &year) == 3){
            printf("valid: %s\n", line); /* 25 Dec 1988 */
        }else if(sscanf(line, "%d/%d/%d", &month, &day, &year) == 3){
            printf("valid: %s\n", line); /* mm/dd/yyyy */
        }else{
            printf("invalid: %s\n", line);
        }
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
