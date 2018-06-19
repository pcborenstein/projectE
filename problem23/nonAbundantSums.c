#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

uint32_t numSearch(uint32_t * pArray, uint32_t num, uint32_t len);

int main(){
    uint32_t i, j;
    //get abundant numbers
    j = 0;
    //make an assumption on how many abundant numbers we will find between 1 and 28123
    uint32_t abundantNums[8000];
    uint32_t numNums = 0;
    for(i = 1; i < 28123; i++){
        if(numNums == sizeof(abundantNums)/sizeof(uint32_t)){
            fprintf(stderr, "array too small\n");
            exit(EXIT_FAILURE);
        }
        //create a list of all factors
        uint32_t maxFactor = sqrt(i);
        uint32_t factorSum = 1;
        for(j = 2; j <= maxFactor; j++)
            if((i % j) == 0)
                if(j == (i / j))
                    factorSum += j;
                else
                    factorSum += j + (i / j);

        if(factorSum > i){
            abundantNums[numNums] =  i;
            numNums++;
        }
    }
    printf("found %d abundant sums\n", numNums);

    uint64_t nonSums = 0;
    for(i = 28124; i > 0; i--){
        //its only necessary to search down
        uint32_t match;
        uint32_t index;
        j = numNums;
        do{
            j--;
            if(abundantNums[j] > i)
                continue;
            match = i - abundantNums[j];
            //printf("searching for %d; abundantNums[%d] = %d\n", match, j, abundantNums[j]);
            index = numSearch(abundantNums, match, numNums);
            //printf("possible match found at index %d; abundantNums[%d] = %d\n", index, index, abundantNums[index]);
            if(abundantNums[index] == match)
                break;
        }while(j > 0);
        if(abundantNums[index] != match){
            nonSums += i;
        }
    }
    printf("answer %ld\n", nonSums);
}

uint32_t numSearch(uint32_t * pArray, uint32_t num, uint32_t len){

    if((len == 1) || (len == 0))
        return 0;
    uint32_t index = len/2;
    index--;
    //printf("given length %d, check mid %d\n", len, index);
    if(pArray[index] == num){
        //printf("match\n");
        return index;
    }else if(pArray[index] < num){
        //printf("%d is in the upper half because greater than %d at index %d\n", num, pArray[index], index);
        return((index + 1) + numSearch(&pArray[index + 1], num, len - index - 1));
    }else{
        //printf("%d is in the lower half because less than %d at index %d\n", num, pArray[index], index);
        return numSearch(pArray, num, index);
    }
}
