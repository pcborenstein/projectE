#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

int main(void){

    volatile double powa;
    volatile uint8_t * pPowa = (uint8_t *) &powa;
    int i;
    clock_t begin,end;


    begin = clock();
    /*
       string to hold the number
       To guestimate the required length,
       2^10 is about 1,000 (1024)
       a^(b*c) = (a^(b))^c)
       1000^100 means we will get about 1 followed by 3*100 0's
       +1 for null terminator
       +10 to make the guess robust within a generious magnitude of 10^10
    */
    char numStr[1 + (3 * 100) + 1 + 10];


    for(i = 0; i < sizeof(double); i++)
        pPowa[i] = 0;

    //bits 62-51 set the exponent of a double with an offset of 1023
    pPowa[7] = (1023 + 1000) >> 4;
    pPowa[6] = ((1023 + 1000) & 0xf) << 4;

    //value is 1 + the fraction so the following line is incorrect
    //pPowa[0] = 1;

    sprintf(numStr,"%.0f", powa);
    /*
    //visualize the number
    printf("%f - double decimal\n", powa);

    printf(" - double hex value: 0x");
    printf("\n");
    printf("%s - string value\n",numStr);
    */



    /*
       If you have about 300 digits,
       the most they would be is 9*300.
       2700 is far less than the max value of a 32 bit uint (2^32 =4.2 billion)
       */
    uint32_t sum = 0;
    i = 0;
    while(numStr[i] != '\0'){
        sum += numStr[i] - '0';
        i++;
    }
    end = clock();
    double elapsedTime = (double)(end-begin)/CLOCKS_PER_SEC;

    printf("answer: %d\n", sum);
    printf("Took %f seconds\n", elapsedTime);

    exit(EXIT_SUCCESS);
}
