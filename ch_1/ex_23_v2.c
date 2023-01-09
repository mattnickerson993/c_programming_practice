// credit to -- https://github.com/ohkimur/the-c-programming-language-2nd-edition-solutions/blob/main/chapter_1/exercise_1_23/c_remove_comments.c


#include <stdio.h>
#define LIMIT 100000
#define TRUE (1 == 1)
#define FALSE !TRUE

/* 
Goal: write a program to remove all comments from a c program
    Guidelines - c comments don't nest
               - include // and /star syntax ... star in this case = *
    Method:
        parse each line and copy to array
        check if first non-blank char is a / --- if so don't output this line
        instead just output newline and move on
        handle special case of /star by searching for matching star/ and skipping all those lines */

int get_str(char s[], int limit);
void remove_comments(char from[], char to[]); 


int main(void){
    int len;
    char full_string[LIMIT];
    char no_comments[LIMIT];

    get_str(full_string, LIMIT);
    remove_comments(full_string, no_comments);
    printf("%s", no_comments);

    return 0;

}


// copy to array
int get_str(char str[], int limit)
{
  int c, i = 0;

  while (i < limit - 1 && (c = getchar()) != EOF)
  {
    str[i++] = c;
  }
  str[i] = '\0';

  return i;
}

void remove_comments(char str[], char no_com_str[])
{
  int in_quote = FALSE;
  int line_comment = FALSE;
  int block_comment = FALSE;

  int i = 0, j = 0;
  while (str[i] != '\0')
  {
    if (!block_comment)
    {
      if (!in_quote && str[i] == '"')
    {
      in_quote = TRUE;
    }
    else if (in_quote && str[i] == '"')
    {
      in_quote = FALSE;
    }
    }

    if (!in_quote)
    {
      if (str[i] == '/' && str[i + 1] == '*' && !line_comment)
      {
        block_comment = TRUE;
      }

      if (str[i] == '*' && str[i + 1] == '/')
      {
        block_comment = FALSE;
        i += 2;
      }

      if (str[i] == '/' && str[i + 1] == '/')
      {
        line_comment = TRUE;
      }

      if (str[i] == '\n')
      {
        line_comment = FALSE;
      }

      if (line_comment || block_comment)
      {
        ++i;
      }
      else if (!line_comment || !block_comment)
      {
        no_com_str[j++] = str[i++];
      }
    }
    else
    {
      no_com_str[j++] = str[i++];
    }
  }

  no_com_str[j] = '\0';
}
