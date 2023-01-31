#include <stdio.h>
#include <ctype.h>


#define MAX 10

int getch(void);
void ungetch(int c);
int getint(int *pn);

int main(void)
{
	int n, array[MAX];
	for(n = 0; n < MAX && getint(&array[n]) != EOF; n++)
		printf("EOF: %d\n", EOF);
	return 0;
}

int getint(int *pn)
{
	int c, sign;

	while (isspace( c = getch())){
		;
	} /* skip white space */
		
	if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
		ungetch(c); /* it's not a number */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if( c == '+' || c == '-')
		c = getch();
		if(!isdigit(c)){ /* edge case where + or - isn't followed by digit */
			ungetch(c);
			return 0;
		}
	for(*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if( c != EOF)
		ungetch(c);
	return c;
}

int bufp = 0;
int buf[MAX];

int getch(void)
{
	return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp < MAX)
		buf[bufp++] = c;
}
