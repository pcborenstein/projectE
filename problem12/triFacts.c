#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int main(void){

    uint32_t i, j;
    uint32_t triNum;
    uint32_t numFactors;
    uint32_t maxNumFactors = 0;

    i = 1;
    triNum = i;

    clock_t begin = clock();

    do{
        i++;
        triNum += i;

        /*
        Every factor has a pair; 1 and the number itself,
        possibly 2 and half the number, possibly 3 and a third of the number (triNum).
        By identifying the maximum possible factor, I can reduce runtime.
        The first of all these pairs is at least less than the square root of the number.
        */
        //Start at 2 because we count a number divided by itself and 1  in this problem
        numFactors = 1;
        uint32_t maxPossibleFactor = (uint32_t)sqrt(triNum);
        for(j = 2; j<= maxPossibleFactor; j++){
            if((triNum % j) == 0)
                numFactors++;
        }
        numFactors *= 2;
        if(numFactors > maxNumFactors){
            maxNumFactors = numFactors;
        }
    }while(numFactors < 500);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Triangle number %d has %d factors\n", triNum, numFactors);
    printf("Took %f seconds\n", time_spent);

    return EXIT_SUCCESS;
}

