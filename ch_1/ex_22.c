# include <stdio.h>

#define LIMIT 1000
#define FOLD_LIMIT 25



/*
 C Division
 for ceil(A/B) ---> (A + (B - 1)) / B
 for round(A/B) ---> (A + (B/2)) / B
 */

/* Goal: fold long lines(beyond a given length into two or more lines -- using last non-blank character)
   Method: 
         * input each line into an array and record its length
         * split line into n = ceiling(len/fold_limit) lines if line is beyond fold limit
         * find last non-blank character for each folded line and only output to this point
         * output each line to non blank char limit, stop when you hit null char
 */

int get_ln(char s[], int limit);
int find_last_non_blank(char s[], int start, int end);

int main(void){
    
    int len, split_lines_ceil, i, j;
    char line[LIMIT];

    while((len = get_ln(line, LIMIT)) > 0){
        // number of folds
        split_lines_ceil = (len + (FOLD_LIMIT - 1)) / FOLD_LIMIT;
        int start, end, last_non_blank;

        for(i = 0; i < split_lines_ceil; i++){
            // start and end of current fold
            start = i * FOLD_LIMIT;
            end = FOLD_LIMIT * (i + 1);
            // adjusted end of fold is blank chars are at end
            last_non_blank = find_last_non_blank(line, start, end);
            // output
            for(j= start; j < last_non_blank; j++){
                if(line[j] == '\0'){
                    break;
                }
                printf("%c", line[j]);
            }
            printf("\n");
        }

    }

    return 0;
}

// find last character in array section that is not blank (ie chop off trailing blanks)
int find_last_non_blank(char s[], int start, int end){
    int i;
    for (i = end; end >= start; i--){
        if (s[i] != ' '){
            return i;
        };
    }
    return i;
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