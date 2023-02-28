#include <stdio.h>
#include <stdarg.h>



void minprintf(char *fmt, ...);


int main(void){
    int a = 1, c = 255;
    double b = 2.55;
    char *s = "Hello world";
    minprintf("Int: %d, Double: %f, String: %s\n", a, b, s);
    minprintf("hex: %x\n", c);
    minprintf("hex: %X\n", c);
    return 0;
}



/* minprintf: minimal printf with variable argument list */
void minprintf(char *fmt, ...){
    va_list ap; /* points to each unnamed arg in turn */
    char *p, *sval;
    int ival;
    double dval;
    unsigned hexval;

    va_start(ap, fmt); /* make ap point to the 1st unamed arg */
    for(p = fmt; *p; p++){
       if(*p != '%'){
            putchar(*p);
            continue;
       }
       switch (*++p)
       {
        case 'd': 
            ival = va_arg(ap, int);
            printf("%d", ival);
            break;
        case 'x':
            hexval = va_arg(ap, unsigned int);
            printf("%x", hexval);
            break;
        case 'X':
            hexval = va_arg(ap, unsigned int);
            printf("%X", hexval);
            break;
        case 'f': 
            dval = va_arg(ap, double);
            printf("%f", dval);
            break;
        case 's':
            for(sval = va_arg(ap, char *); *sval; sval++){
                putchar(*sval);
            }
            break;    
        default:
            putchar(*p);
            break;
       } 
    }
    va_end(ap);
}