#include <stdio.h>

#define LINE_LIMIT 1000
/*
Goal: write a function that reverses a character string s
      use it to write a program that reverses input one line a time
Method:
      * parse each line and fill array with characters( including newline and null), also note length through newline
      * reverse array in place with temp variable -- tack null on end of reversed array
      * print out for display skipping first char -- which is a newline
      * account for newline display
 */

void reverse(char s[], int len);
int get_line(char line[], int max_line_len);

int main(void){

  int len, i;
  char line[LINE_LIMIT];

  while ((len = get_line(line, LINE_LIMIT)) > 0){
      reverse(line, len);
      // funky printing because the newlines start the array
      for(i = 1; i < len; i ++){
        printf("%c", line[i]);
      }
      // for display purposes
      printf("\n");
  }

  return 0;
}

// use the standard reversing array with temp var trick --- set last char to null for completeness
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

// return length of line (inclusive of newline character ---and tack null character on the end)
int get_line(char ln[], int limit){
  int c, i;

  for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++){
    ln[i] = c;
  }

  if (c == '\n'){
    ln[i] = '\n';
    i++;
  }

  ln[i] = '\0';

  return i;
}