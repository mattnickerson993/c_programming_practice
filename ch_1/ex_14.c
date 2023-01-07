#include <stdio.h>

#define ALPHA_SIZE 26
#define NUM_SIZE 10
#define CAPS_SIZE 26

/*
Goal:
    * print a histogram of frequencies of characters from given input 
Methodology: 
    * realize a character is just a small int
    * array size needs to equal all alphanumerical characters
    * knowing the size of each char set ( lowercase, uppercase, nums)
    *   -segment each set in the array if ascii number falls in that set
    *   - then make sure you are currectly grabbing it for display
 */

int main(void){
   
    int i, c, j, total;
    total = ALPHA_SIZE + NUM_SIZE + CAPS_SIZE;
    int char_nums[total];
    
    // initialize char_nums values to 0
    for( i = 0; i < total; i++){
        char_nums[i] = 0;
    }


    while((c = getchar()) != EOF){
        // lowercase and place in first segement
        if(c >= 'a' && c <= 'z'){
            char_nums[c - 'a']++;
        }
        // num and place in second segment
        else if(c >= '0' && c <= '9'){
            char_nums[c - '0' + ALPHA_SIZE]++;
        }
        // uppercase in third segment
        else if (c >= 'A' && c <= 'Z'){
            char_nums[c - 'A' + ALPHA_SIZE + NUM_SIZE]++;
        }
    }

// histogram display

    printf("Char counts Below -----------\n");
    
    for (i = 0; i < ALPHA_SIZE; i++){
        printf("%c: ", 'a' + i);
        for(j = 0; j < char_nums[i]; j++){
            printf("#");
        }
        printf("\n");
    }

    printf("Num counts Below -----------\n");
    
    for (i = ALPHA_SIZE; i < ALPHA_SIZE + NUM_SIZE; i++){
        printf("%c: ", '0' + i - ALPHA_SIZE);
        for(j = 0; j < char_nums[i]; j++){
            printf("#");
        }
        printf("\n");
    }

    printf("Caps counts Below -----------\n");
    
    for (i = ALPHA_SIZE + NUM_SIZE; i < total; i++){
        printf("%c: ", 'A' + i - ALPHA_SIZE - NUM_SIZE);
        for(j = 0; j < char_nums[i]; j++){
            printf("#");
        }
        printf("\n");
    }

}
