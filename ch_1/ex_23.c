#include <stdio.h>


#define LIMIT 200
#define MULTILINE_COMMENT 0
#define COMMENT 1
#define NO_COMMENT -1
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

// test
int get_ln(char s[], int limit);
int check_comment(char s[]);
int find_star(char s[]);

int main(void){
    int len, state, multi_line, stop;

    char current_line[LIMIT];
    printf("//remove me\n");
    printf("/*remove me\n");
    while( (len = get_ln(current_line, LIMIT)) > 0){ // remove me
        // check if comment, multline comment or none and handle appropriately
        state = check_comment(current_line);
        if (state == COMMENT){
            printf("\n");
            continue;
        }
        else if(state == MULTILINE_COMMENT){
            multi_line = TRUE;
            while(multi_line == TRUE){
                // skip lines until ending comment is found
                get_ln(current_line, LIMIT);
                if(find_star(current_line) == 1){
                    multi_line = FALSE;
                }
            }   
            continue;
        }
        printf("%s", current_line);
    }
    return 0;
}


// returns length of line including newline char, also copies line to array
int get_ln(char s[], int limit){
    int i, c;

    for(i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++){
        s[i] = c;
    }
    if(c == '\n'){
        s[i] = c;
        i++;
    }
    s[i] = '\0';

    return i;
}

// return true if comment, false if not
int check_comment(char s[]){
    int i;
    int in_block_quote = FALSE;
    int in_comment = FALSE;
    int in_quote = FALSE;

    for(i = 0; s[i] != '\0'; i++){
        if(!in_block_quote && !in_comment && s[i] == '"'){
            in_quote = TRUE;
        }
        else if(!in_block_quote && !in_comment && s[i] == '"' && in_quote){
            in_quote = FALSE;
        }
        if(!in_quote && s[i] == '/' )
    }
    if (s[i] == '/'){
        // special case to handle
        if(s[i + 1] == '*'){
            return 0;
        }
        return 1;
    }
    return -1;
}

int find_star(char s[]){
    
    int i;
    for(i = 0; s[i] != '\0'; i++){
        if (s[i] == '*' && s[i + 1] == '/'){
            return 1;
        }
    }
    return -1;
}