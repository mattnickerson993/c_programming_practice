// assist from https://github.com/feperessim/The-C-Programming-Language/blob/master/Chapter%204/exercise2.c
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000
/* 
    convert string s (ascii) to a double --- accounting for scientific notation
    
*/

double atof_sample(char s[]);

int main(void){
    char s[MAXSIZE] = "123.45E-6";
    printf("%lf\n", atof_sample(s));
    return 0;

}

double atof_sample(char s[])
{
        double val, power, pot, e = 1.0;
        int i, sign, sign_pot;

        for (i = 0; isspace(s[i]); i++) /* skip white space */
                ;
        sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
                i++;
        // ultimately outputs double from string
        for (val = 0.0; isdigit(s[i]); i++)
                val = 10.0 * val + (s[i] - '0');
        if (s[i] == '.')
                i++;
        // same thing just tracks power (10, 100, 1000)
        for (power = 1.0; isdigit(s[i]); i++) {
                val = 10.0* val + (s[i] - '0');
                power *= 10;
        }
        // see if exp present
	    if (s[i] == 'e' || s[i] == 'E')
		    i++;	
        else	
            return sign * val / power;
        // get sign of sci notation
        if (s[i] == '-' || s[i] == '+')
            sign_pot = s[i++];
        // same as before --- ie how many decimals must i jump
        for (pot = 0.0; isdigit(s[i]); i++)
            pot = 10 * pot + (s[i] - '0');
        // number of decimals i must jump 10 ^ number of decimals i must jump
        while (pot != 0) {
            e *= 10;
            pot--;
        }
        if (sign_pot == '-')
            // 123.45e-6
            // ex: 1 * 12345/ 1000000/ 100   
            return sign * val/e/power; 
        else
            // 123.45e-6
            // ex: 1 * 12345 * 1000000/100   
            return sign * val * e / power;

}
