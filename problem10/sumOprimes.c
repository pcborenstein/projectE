#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define CEILING 2000000

int main(){
    bool BFarray[CEILING + 1];
    int i;
    int j;
    long int sumOprimes = 0;

    for(i = 0; i < CEILING; i++)
        BFarray[i] = true;

    BFarray[0] = false;
    BFarray[1] = false;

    for(i = 0; i < CEILING; i++)
       if(BFarray[i] == true){
            for(j = i; j < CEILING; j+=i)
                BFarray[j] = false;
            sumOprimes += i;
            }

    printf("%ld\n", sumOprimes);
    exit(EXIT_SUCCESS);
}
