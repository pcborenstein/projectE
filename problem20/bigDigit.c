#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>

int main(void){
    int i, j;
    //100! has at most 200 digits
    //every uint64_t will hold 10 digits
    //any overflow get added to the higher element
    //start the lowest element at 1;
    uint64_t numParts[20];
    for(i  = 0; i < 20; i++)
        numParts[i] = 0;
    numParts[0] = 1;
    uint16_t powers[10];
    uint64_t digit = 0;


    //calculate sum of 20! digits
    uint64_t testFact = 1;
    for(i = 2; i < 21; i++)
        testFact*= i;
    printf("20! = %ld\n", testFact);
    int testSum = 0;
    while(testFact > 0){
        testSum += testFact % 10;
        testFact /= 10;
    }

    int sum = 0;
    int tens;
    int skip;
    uint64_t multiple;
    for(i = 2; i < 100; i++){
        //skip multiples of 10
        multiple = i;
        if(multiple % 10 == 0)
            multiple /= 10;
        for(j = 0; j < 20; j++)
            numParts[j] *= multiple;
        for(j = 0; j < 19; j++){
            if(numParts[j] >= 10000000000ul){
                numParts[j+1] += numParts[j] / 10000000000ul;
                numParts[j] = numParts[j] % 10000000000ul;
            }
        }
    }

    for(j = 0; j < 20; j++)
        printf("j | %ld\n", numParts[j]);

    uint64_t digitSum = 0;
    for(j = 0; j < 20; j++){
        while(numParts[j] !=0){
            digitSum += numParts[j] % 10;
            numParts[j] /= 10;
        }
    }
    printf("answer: %ld\n", digitSum);



    exit(EXIT_SUCCESS);
}


