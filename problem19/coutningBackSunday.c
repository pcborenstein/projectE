#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv){
                    //    1  2   3   4   5   6   7   8   9   10  11  12
    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char months[12][4] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
        "Aug", "Sep", "Oct", "Nov", "Dec"};
    char strDays[7][4] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

    int days = 0;
    int i, j;
    int year = 1900;
    int day = 0;
    int firstSundays = 0;

    for(year = 1900; year < 2001; year++){
        if((year % 4 == 0) && ((year %100 != 0) || (year % 400 == 0)))
            monthDays[1] = 29;
        else
            monthDays[1] = 28;
        //leap year condition
        for(j = 0; j < 12; j++){
            //printf("1 %s %d was a %s\n", months[j], year, strDays[days]);
            days = (days + monthDays[j]) % 7;
            if((year > 1900) && ((days % 7) == 6))
                firstSundays++;
        }


        //printf("%d days in year %d\n", days, year);

        //printf("1 Jan %d was a %s\n", (year + 1), strDays[days%7]);
    }

    printf("answer %d\n", firstSundays);

    exit(EXIT_SUCCESS);
}
