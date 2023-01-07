#include <stdio.h>

#define MAX_WORD_LEN 20
#define OUT_WORD  0
#define IN_WORD 1


/* print a histogram of the lengths of words in input */

int main(void){
    int c, i, state, current_len;
    int word_lens[MAX_WORD_LEN];

    // set array vals to 0
    for(i = 0; i < MAX_WORD_LEN; i++){
        word_lens[i] = 0;
    }

    state = OUT_WORD;
    current_len = 0;

    while((c = getchar()) != EOF){
        // in word and stay
        if( state == IN_WORD && (c != ' ' && c != '\n' && c != '\b' && c != '\t')){
            current_len ++;
        }
        // in word and out
        else if (state == IN_WORD && (c == ' ' || c == '\n' || c == '\b' || c == '\t'))
        {
            word_lens[current_len]++;
            current_len = 0;
            state = OUT_WORD;
        }
        // out word and in
        else if (state == OUT_WORD && (c != ' ' && c != '\n' && c &&'\b' && c != '\t')){            
            state = IN_WORD;
            current_len ++;
        }
        // out word and out -- do nothing
    }
    // output last word count if necessary
    if (current_len != 0){
        word_lens[current_len]++;
    }
    // make histogram horizontally
    printf("Horizontal \n");
    int k;
    for (i = 1; i < MAX_WORD_LEN; i++){
        printf("%d: ", i);
        if(word_lens[i] > 0){
            for(k = 1; k <= word_lens[i]; k++){
                printf("#");
            }
            printf("\n");
        }
        else{
            printf("\n");
        }
    }
    // make histogram vertically
    printf("\n\n\n");
    printf("Vertical\n");
    int j;
    for (j = MAX_WORD_LEN - 1; j > 0; j--){
        for (i = 1; i < MAX_WORD_LEN; i++){
            if (word_lens[i] >= j && i < 10){
                printf(" # ");
            }
            else if (word_lens[i] >= j && i > 9){
                printf("   #  ");
            }
            else if(i > 9){
                // need 6 here as digit takes two spaces
                printf("      ");
            }
            else{
                printf("   ");
            }
        }
        printf("\n");
    }
    for(i = 1; i < MAX_WORD_LEN; i++){
        if(i < 10){
            printf(" %d ", i);
        }
        else{
            // 4 spaces + 2 digits for digit
            printf("  %d  ", i);
        }
    }
    printf("\n");
}