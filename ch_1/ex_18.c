
#include <stdio.h>

#define MAXLINE 1000
#define TABS_BLANKS_ONLY -1

/*
Goal: remove all trailing blanks and tabs, also skip any blank line or line with only blanks and tabs
Method:
    * copy all chars to array
    * remove blanks and tabs from end, stop when you hit something different
    * edge case when line is empty(ie just newline) and when line only contains blanks and tabs
    * if done properly --- can just print the array contents (including newline and null)
 */

int get_line(char line[], int max_line_len);
int remove_trailing_blanks(char line[], int length);


int main(void){
    int len, i, state;

    char current_line[MAXLINE];

    while((len = get_line(current_line, MAXLINE)) > 0){

        // edge case for blank line to delete -- everyline with a newline has a length of one
        if(len == 1){
            continue;
        }
        state = remove_trailing_blanks(current_line, len);

        // edge case for line of all blanks and or tabs. -1 if last char is tab or blank
        if (state == TABS_BLANKS_ONLY){
            continue;
        }
        // print char array if no edge cases
        printf("%s", current_line);
    }
}

int remove_trailing_blanks(char line[], int length){
    int i;
    
    for(i = length - 2; line[i] == ' ' || line[i] == '\t'; i--)
    ;

    line[i + 1] == '\n';
    line[i + 2] == '\0';

    // case for nothing but blanks and tabs
    if (i == TABS_BLANKS_ONLY){
        return -1;
    }
    else {
        return 0;
    }
}

int get_line(char line[], int max_line_len)
{
  int c, i;

  for (i = 0; i < max_line_len - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
  {
    line[i] = c;
  }

  if (c == '\n')
  {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';

  return i;
}
