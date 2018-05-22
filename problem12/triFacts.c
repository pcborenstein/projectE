#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void){

    uint32_t i, j;
    uint32_t triNum;
    uint32_t numFactors;
    uint32_t maxNumFactors = 0;

    i = 1;
    triNum = i;

    do{
        i++;
        triNum += i;
        numFactors = 0;
        //all factors will be at most half the number
        for(j = 1; j <= ((triNum >> 1) + 1) ; j++){
            //printf("%d %% %d = %d\n", triNum, j, (triNum%j));
            if((triNum % j) == 0){
                numFactors++;
            }
        }
        //add one more because a number divides itself in this problem
        numFactors++;
        if(numFactors > maxNumFactors){
            maxNumFactors = numFactors;
            printf("%d has %d factors\n", triNum, numFactors);
            printf("sanity check i: %d numFactors: %d triNum: %d\n",i,numFactors, triNum);
        }
        //print every 100ths value for snaity check
        if((i % 1000) == 0)
            printf("sanity check i: %d numFacotrs: %d triNum: %d\n",i,numFactors, triNum);
    }while(numFactors < 500);

    printf("Triangle number %d has %d factors\n", triNum, numFactors);

    return EXIT_SUCCESS;
}

