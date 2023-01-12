#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define LIMIT 1000

int get_str(char str[], int limit);
int htoi(char hex[]);

int main(void){
    int res;
    char hex[LIMIT];
    get_str(hex, LIMIT);
    res = htoi(hex);

    printf("Value: %d\n", res);

}


int get_str(char str[], int limit){
    int i, c;
    i = 0;

    while(i < limit -1 && (c = getchar()) != EOF && c != '\n'){
        str[i] = c;
        i ++;
    }
    str[i] = '\0';

    return i;
}

int htoi(char s[])
{
	int i, n;
	n = 0;
	for (i = 0; ; ++i) {
		if (s[i] == '0' && (s[i+1] == 'x' || s[i+1] == 'X')) {
			i++;
			continue;
		}
		
		if (s[i] >= '0' && s[i] <= '9') {
			n = 16 * n + (s[i] - '0');
		} else if (s[i] >= 'a' && s[i] <= 'f') {
			n = 16 * n + (s[i] - 'a' + 10);
		} else if (s[i] >= 'A' && s[i] <= 'F') {
			n = 16 * n + (s[i] - 'A' + 10);
		} else {
			break;
		}
	}
	return n;
}