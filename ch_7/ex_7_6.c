#include <stdio.h>
#include <string.h>

#define MAXLINE 256

int get_ln(char *line, int max, FILE *fp);
int compare_lines(char *linea, char *lineb);

int main(int argc, char *argv[]){
    char line_a[MAXLINE], line_b[MAXLINE];
    int len_a, len_b;
    char *prog;
    prog = argv[0];
    FILE *fp1, *fp2;

    if(argc != 3){
        printf("Error: must specify two files args\n");
        return 1;
    }
    fp1 = fopen(*++argv, "r");
    if(fp1 == NULL){
        printf("%s: can't open %s\n", prog, *argv);
        return 1;
    }

    fp2 = fopen(*++argv, "r");
    if(fp2 == NULL){
        printf("%s: can't open %s\n", prog, *argv);
        fclose(fp1);
        return 1;
    }

    while((len_a = get_ln(line_a, MAXLINE, fp1)) > 0 && (len_b = get_ln(line_b, MAXLINE, fp2)) > 0){
        if(len_a != len_b || strncmp(line_a, line_b, MAXLINE) != 0){
            printf("lines differ below:\n");
            printf("%s", line_a);
            printf("%s", line_b);
            fclose(fp1);
            fclose(fp2);
            return 1;
        }

    }
    fclose(fp1);
    fclose(fp2);
    printf("Files are equivalent\n");
    return 0;
}



int get_ln(char *line, int max, FILE *fp){
    if(fgets(line, max, fp ) == NULL){
        return 0;
    }
    else{
        return strlen(line);
    }    
}
