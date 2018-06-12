#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>

int main(void){
    int i, j;
    uint64_t factorials[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1 ,1};
    uint16_t powers[10];
    uint64_t digit = 0;

    /*
    for(i = 2; i < 10; i ++){
        factorial *= i;
        printf("%d | %ld\n", i, factorial);
    }
    if(factorial % 10 == 0){
        powers += 1;
        factorial /= 10;
    }
    j = factorial % 10;
    digit = powl(j, 10);
    printf("first digit to the power of 9: %d ^ 9 =  %ld\n", j, digit);
    */



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
    //faster method
    for(i = 0; i < 2; i++){
        for(j = 0; j < 11; j++){
            if((j ==0) && (i ==0))
                continue;
            factorials[i] *= ((i *10) + j);
            //printf("factorials[%d] = %ld, %d\n", i, factorials[i], j);

            //this should happen only twice for every decade
            if(i == 0){
                if(j == 6){
                    if(factorials[i] % 10 == 0){
                        printf("dropped a 0 for %d %d\n", i, j);
                        factorials[i] /= 10;
                    }else{
                        fprintf(stderr,"math failed\n");
                        exit(EXIT_FAILURE);
                    }
                }
            }else{
                if(j == 6){
                    if(factorials[i] % 100 == 0){
                        printf("dropped two 0s for %d %d\n", i, j);
                        factorials[i] /= 100;
                    }else{
                        fprintf(stderr,"math failed\n");
                        exit(EXIT_FAILURE);
                    }
                }
            }
        }
    }
    for(i = 0; i < 10; i++)
        while(factorials[i] %10 ==0)
            factorials[i] /= 10;

    for(i = 0; i < 10; i++)
        printf("numbers %2d through %2d : %ld\n",i * 10 + 1, (i + 1)*10, factorials[i]);
    uint64_t carry = 0;
    uint64_t digitSum;
    bool done = false;
    bool allZero;
    //100! will be about 100 digitis long
    //a 64 bit uint can hold 1.8e19
    uint64_t multipleStack[100];
    int msp = 0;

    //the multiple of 1-10 is the only possibility of a digit in the tens place
    digitSum = factorials[0] % 10;
    factorials[0] /= 10;

    printf("digitSum: %ld\n", digitSum);
    carry = 0;
    while(done == false){
        allZero = true;
        done = true;

        if(carry != 0){
            msp++;
            //multipleStack[msp] = carry;
            allZero = false;
            done = false;
        }
        multipleStack[msp] = 1;
        printf("multipleStack[%d] : %ld \n", msp, multipleStack[msp]);
        for(i = 0; i < 10; i++){
            printf("numbers %2d through %2d : %ld\n",i * 10 + 1, (i + 1)*10, factorials[i]);
            if(factorials[i] != 0){
                done = false;
            }
            if(factorials[i] % 10 != 0){
                allZero = false;
                multipleStack[msp] *= (factorials[i] % 10);
                printf("multipleStack[%d] : %ld \n", msp, multipleStack[msp]);
            }
            factorials[i] = (factorials[i] / 10);
        }
        printf("resulting multiple : %ld \n", multipleStack[msp]);
        for(i = 0; i < msp; i++){
            printf("stack %2d : %ld\n", i, multipleStack[i]);
            if(multipleStack[i] != 0){
                done = false;
            }
            if(multipleStack[i] % 10 != 0){
                allZero = false;
                multipleStack[msp] *= (multipleStack[i] % 10);
            }
            multipleStack[i] = (multipleStack[i] / 10);
        }

        if(allZero == false){
            digitSum += multipleStack[msp] % 10;
        }
        else
            printf("all 0\n");
        printf("\ndigit sum : %3ld this multipleStack : %ld \n", digitSum, multipleStack[msp]);
        carry = multipleStack[msp] / 10;
        if(multipleStack[msp] > 1000000000000000000){
            printf("numbers too big\n");
            break;
        }
        multipleStack[msp] = multipleStack[msp] / 10;
    }
    printf("answer: %ld\n", digitSum);
    printf("tested answer: %d\n", testSum);

            /*
        //drop less siginficant 0s as they do not add to the sum
        if((i == 2) || (i == 5)){
            printf("skipping %d\n", i);
            continue;
        }
        if(((i %10) == 2)){
            printf("skipping %d\n", i);
            continue;
        }
        if(factorial % 10 == 0){
            powers += 1;
            factorial /= 10;
        }
        //test if we will have an overflow
        if(factorial & (1ul << (64ul - 7ul))){
                printf("number is in danger of overflowing %ld\n", factorial);
                printf("powers: %ld, i: %d\n", powers, i);
                exit(EXIT_FAILURE);
        }
        if((i % 10) == 5){
            tens = i / 10;
            skip = (tens * tens * 10) + tens * 7 + 1;
            factorial *= skip;
            printf("skipping %d with %d\n", i, skip);
        }
        else
            factorial *= i;
    }

    printf("20! = %ld\n", factorial);
    for(;factorial != 0; factorial /= 10)
        sum += (factorial %10);
    printf("sum of digits of 20! = %d\n", sum);

    factorial = 1;
    for(i = 2; i < 21; i ++){
        //drop less siginficant 0s as they do not add to the sum
        if(factorial % 10 == 0){
            powers += 1;
            factorial /= 10;
        }
        //test if we will have an overflow
        if(factorial & (1ul << (64ul - 7ul))){
                printf("number is in danger of overflowing %ld\n", factorial);
                printf("powers: %ld, i: %d\n", powers, i);
                exit(EXIT_FAILURE);
        }
        factorial *= i;
    }
    printf("20! = %ld\n", factorial);
    sum = 0;
    for(;factorial != 0; factorial /= 10)
        sum += (factorial %10);
    printf("sum of digits of 20! = %d\n", sum);
    */
    exit(EXIT_SUCCESS);
}


