#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

int main(){

    uint64_t num = 600851475143;

    float bf = sqrt(num);
    uint32_t biggestPossibleFactor = (uint32_t) bf;
    uint32_t possibleFactor;
    uint32_t j;
    uint32_t bfbf;

    for(possibleFactor = biggestPossibleFactor; possibleFactor > 1; possibleFactor--){
        if((num % possibleFactor) != 0){
            continue;
        }

        //it the factor a prime?
        bf = sqrt(possibleFactor);
        bfbf = (uint32_t) bf;

        //quicker to come from the bottom
        for(j = 2; j <= bfbf; j++){
            if((possibleFactor % j) == 0){
                break;
            }
        }
        if(j > bfbf){
            printf("solution: %d\n",possibleFactor);
            return 0;
        }
    }
}
