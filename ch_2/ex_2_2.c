#include <stdio.h>

#define LIMIT 1000
/* 
    Goal: write a loop equivalent for the get_ln function 
        without using the the && or || operator
 */

int get_ln(char s[], int limit);

int main(void){
    int len;
    char s[LIMIT];
    while ((len = get_ln(s, LIMIT)) > 0){
        printf("%s", s);
    }
    printf("\n");
}


// returns length of line including newline char, also copies line to array
int get_ln(char s[], int limit){
  int i = 0;
  int loop = 1;
  while (loop)
  {
    char c = getchar();

    if (i >= (limit - 1))
    {
      break;
    }
    else if (c == EOF)
    {
      break;
    }
    else if (c == '\n')
    {
      s[i] = c;
      i++;
      break;
    }

    s[i] = c;
    i++;
  }

  s[i] = '\0';

  return i;
}
