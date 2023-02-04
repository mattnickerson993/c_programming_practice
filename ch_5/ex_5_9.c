#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pda);


static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main(void){
    int days;
    int months;
    int day;

    day = day_of_year(2023, 2, 28);
    printf("day of year: %d\n", day);
    
    month_day(2024, 36, &months, &days);
    printf("Month of year: %d\n", months);
    printf("Day of month: %d\n", days);
    return 0;
}


/* month_day: set month, day for day of year */
void month_day(int year, int yearday, int *pmonth, int *pday){
    int i, leap;
    char *p;

    if(year < 0 || yearday < 0){
        printf("Please enter a valid year and yearday\n");
        return;
    }
    // leap year is every 4 years excluding years divisible by 100 or 400
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    p = &daytab[leap][1]; /* fist month */
    if((leap && (yearday > 366)) || (!leap && (yearday > 365))){
        printf("You've entered too many days in the year\n");
    }
    for(i = 1; yearday > *p; i++, p++){
        yearday -= *p; /* subtracts days in each month -- accounting for feb leap year */
    }
    
    *pmonth = i;
    *pday = yearday;
}



/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day){
    int i, leap;

    char *p;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    
    p = &daytab[leap][1]; /* first month */

    for(i = 1; i < month; i++){
        day += *p;
        p++; /* add all days from previous months to date, leap adds extra day for leap year feb */
    }

    
    return day;
}
