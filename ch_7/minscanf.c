#include <stdio.h>
#include <stdarg.h>



int minscanf(char *fmt, ...);


int main(void){
    int a = 1, c = 255;
    double b = 2.55;
    char *s = "Hello world";
    int count;
    count = minscanf("Int: %d, Double: %f, String: %s\n", &a, &b, s);
    printf("expected count 3 result: %d\n", count);
    printf("Int: %d, Double: %f, String: %s\n", a, b, s);
    count = minscanf("hex: %x\n", &c);
    printf("expected count 1 result: %d\n", count);
    printf("hex: %x\n", c);
    count = minscanf("hex: %X\n", &c);
    printf("expected count 1 result: %d\n", count);
    printf("hex: %X\n", c);
    return 0;
}



/* minscanf: minimal printf with variable argument list */
int minscanf(char *fmt, ...){
    int success_scan = 0;
    va_list ap; /* points to each unnamed arg in turn */
    char *p, *sval;
    int ival;
    double dval;
    unsigned hexval;

    va_start(ap, fmt); /* make ap point to the 1st unamed arg */
    for(p = fmt; *p; p++){
       if(*p != '%'){
            // putchar(*p);
            continue;
       }
       switch (*++p)
       {
        case 'd': 
            ival = va_arg(ap, int);
            // printf("%d", ival);
            success_scan++;
            break;
        case 'x':
            hexval = va_arg(ap, unsigned int);
            // printf("%x", hexval);
            success_scan++;
            break;
        case 'X':
            hexval = va_arg(ap, unsigned int);
            // printf("%X", hexval);
            success_scan++;
            break;
        case 'f': 
            dval = va_arg(ap, double);
            // printf("%f", dval);
            success_scan++;
            break;
        case 's':
            for(sval = va_arg(ap, char *); *sval; sval++){
                // putchar(*sval);
                ;
            }
            success_scan++;
            break;    
        default:
            // putchar(*p);
            break;
       } 
    }
    va_end(ap);
    return success_scan;
}