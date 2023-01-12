#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

/*
Goal: write a function htoi(s) which converts a string of hexadecimal digits into its equivalent integer value
    Method: keep running total counting backwards multiply each int (0-f) by 16 ^ n (n counts down to 0)

 */
int htoi(char s[]);

int main(void){
    int res = 0;
    char s[] = "0X4f5d";
    res = htoi(s);
    if (res == -1){
        printf("Incompatible hex character input\n");
        return -1;
    }
    printf("Result: %d\n", res);
    return 0;
}


int htoi(char s[]){
    int i, n, res;
    int len = strlen(s);

    //  n is translated to = 0 - 15 ie 0-f in hex.
    res = 0;
    while(s[i] != '\0'){
        if (s[i] == '0' && (s[i + 1] == 'x' || s[i + 1] == 'X')){
            // skip optional hex chars
            i += 2;
            continue;
        }

        n = tolower(s[i]);
        if (n >= '0' && n <= '9'){
            // convert to 0 - 9
            n -= '0';
        }
        else if (n >= 'a' && n <= 'f'){
            // convert to 10 - 15
            n = n - 'a' + 10;
        }
        else{
            return -1;
        }

        // RUNNING TOTAL (IE FF = 15 x 16 + 15 x 1 -- COUNTING DOWN)
        res += n * (int)pow(16, len - i - 1);

        i++;

    }
     return res;

}