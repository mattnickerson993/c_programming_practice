// assistance --- https://github.com/ohkimur/the-c-programming-language-2nd-edition-solutions/blob/main/chapter_3/exercise_3_05/itob.c


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1000

void reverse(char line[], int len);
void itob(int n, char s[], int b);
char itoc(int a);

int main(void){
    int n = 4095;
    char s[MAX_LEN];
    int b = 16;
    itob(n, s, b);
    printf("%s\n", s);
}


void reverse(char line[], int len){
  int start, end, temp;
  start = 0;
  end = len - 1;
  while(start < end){
    // the ole swaperooo
    temp = line[end];
    line[end] = line[start];
    line[start] = temp;
    start ++;
    end --;
  }
  line[len] = '\0';
}

char itoc(int a)
{
    // converts int 0-15 to 0-f ect
  if (a <= 9)
  {
    return a + '0';
  }

  return a + 'a' - 10;
}


void itob(int n, char s[], int b)
{
  int i = 0, sign = n;

  do
  {
    // provides desired value for given digit
    s[i++] = itoc(abs(n) % b);
    // keep dividing by base until you hit zero
  } while (n /= b);
  

  switch (b)
  {
  case 2:
    s[i++] = 'b';
    s[i++] = '0';
    break;

  case 16:
    s[i++] = 'x';
    s[i++] = '0';
    break;
  }

  if (sign < 0)
  {
    s[i++] = '-';
  }

  s[i] = '\0';

  reverse(s, strlen(s));
}


// previous implmentation 
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