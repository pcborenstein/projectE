#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

int main(void){

    int i, j;

    int factorSums[10000];
    uint32_t sum = 0;

    //create a list of all factors
    for(i = 1; i < 10000; i++){
        factorSums[i] = 0;
        int maxFactor = sqrt(i);
        for(j = 1; j <= maxFactor; j++)
            if((i % j) == 0)
                factorSums[i] += j + (i / j);
        //not supposed to add the number itself
        //even though 1 is considered...
        factorSums[i] -= i;
    }

    for(i = 1; i < 10000; i++){
        if((factorSums[i] != 1) && (factorSums[i] != i) &&
                (factorSums[i] < 10000) && (i == factorSums[factorSums[i]])){
            printf("found a pair: %d and %d\n", factorSums[i], factorSums[factorSums[i]]);
            sum += factorSums[i];
            sum += i;
            //ensure the match does not happen again for the great value
            factorSums[i] = 1;
        }

    }
    printf("sum %d\n", sum);

    exit(EXIT_SUCCESS);
}







