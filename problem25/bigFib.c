#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>

int main(void){
    int i;
    //every uint64_t will hold 10 digits
    uint64_t numParts[100];
    uint64_t prevNumParts1[100];
    uint64_t prevNumParts2[100];
    for(i  = 0; i < 100; i++){
        prevNumParts1[i] = 0;
        prevNumParts2[i] = 0;
        numParts[i] = 0;
    }
    numParts[0] = 1;
    uint32_t index = 1;

    while(numParts[99] < 999999999ul){
        index++;
        for(i  = 0; i < 100; i++)
            prevNumParts2[i] = prevNumParts1[i];
        for(i  = 0; i < 100; i++)
            prevNumParts1[i] = numParts[i];
        for(i  = 0; i < 100; i++)
            numParts[i] = prevNumParts1[i] + prevNumParts2[i];
        for(i  = 0; i < 99; i++)
            if(numParts[i] >= 10000000000ul){
                numParts[i+1] += numParts[i] / 10000000000ul;
                numParts[i] = numParts[i] % 10000000000ul;
            }
    }
    printf("answer %d\n", index);
    exit(EXIT_SUCCESS);
}


