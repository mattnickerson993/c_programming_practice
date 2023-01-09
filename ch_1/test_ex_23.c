#include <stdio.h>


#define LIMIT 200
#define MULTILINE_COMMENT 0
#define COMMENT 1
#define NO_COMMENT -1
#define TRUE 1
#define FALSE 0

int get_ln(char s[], int limit);
int check_comment(char s[]);
int find_star(char s[]);

int main(void){
    int len, state, multi_line, stop;

    char current_line[LIMIT];
    
    while( (len = get_ln(current_line, LIMIT)) > 0){

        state = check_comment(current_line);
        if (state == COMMENT){
            printf("\n");
            continue;
        }
        else if(state == MULTILINE_COMMENT){
            multi_line = TRUE;
            while(multi_line == TRUE){

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



int check_comment(char s[]){
    int i;
    for(i = 0; s[i] == ' '; i++);
    if (s[i] == '/'){

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