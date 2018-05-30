#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int countChars(char * str);

int main(int argc, char ** argv){

    char ones[10][10] = {"", {'o', 'n', 'e', '\0'}, "two", "three", "four", "five",
        "six", "seven", "eight", "nine"};
    char tens[10][10] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty",
        "seventy", "eighty", "ninety"};
    char hundreds[10][100] = {"","one hundred and ", "two hundred and ",
"three hundred and ", "four hundred and ", "five hundred and ", "six hundred and ",
"seven hundred and ", "eight hundred and ", "nine hundred and ",};
    char thousands[2][100] = {"", "one thousand"};

    char strangeNums[10][20] = {"ten", "eleven", "twelve", "thirteen",
        "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

    int i, j, k;
    int charCounts[3][10];
    int strangeCharCounts[10];

    for(i = 0; i < 10; i++)
        charCounts[0][i] = countChars(ones[i]);

    for(i = 0; i < 10; i++)
        charCounts[1][i] = countChars(tens[i]);

    for(i = 0; i < 10; i++)
        charCounts[2][i] = countChars(hundreds[i]);

    for(i = 0; i < 10; i++)
        strangeCharCounts[i] = countChars(strangeNums[i]);

    /*
    for(i = 0; i < 10; i++)
        printf("%2d %s\n", charCounts[2][i], hundreds[i]);
        */


    uint32_t total = 0;
    for(i = 0; i < 10; i++)
        for(j = 0; j < 10; j++)
            for(k = 0; k < 10; k++){
                if(j == 1){
                    total += (charCounts[2][i] + strangeCharCounts[k]);
                    //printf("%5d %3d %s%s\n", total, (charCounts[2][i] + strangeCharCounts[k]), hundreds[i], strangeNums[k]);
                }else{
                    total += (charCounts[2][i] + charCounts[1][j] + charCounts[0][k]);
                    //printf("%5d %3d %s%s%s\n", total, (charCounts[2][i] + charCounts[1][j] + charCounts[0][k]), hundreds[i],tens[j], ones[k]);
                }
                //take the "and" out of hundreds that in in 00
                if( i > 0 && j == 0 && k == 0)
                    total -= 3;
            }
    int thous = countChars(thousands[1]);
    total += thous;
    printf("total char count %d\n", total);
    exit(EXIT_SUCCESS);
}

int countChars(char * str){
    int num = 0;
    int i = 0;

    while(str[i] != '\0'){
        if(str[i] != ' ')
            num++;
        i++;
    }

    return num;
}
