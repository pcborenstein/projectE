#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

int main(int argc, char ** argv){

    uint64_t iterrations = 0;
    uint64_t maxIterrations = 0;
    uint64_t answer;
    uint64_t seq = 13;
    uint64_t i;

    clock_t begin = clock();


    for(i = 2; i < 1000000; i++){
        seq = i;
        iterrations = 0;
        while(seq > 1){
            iterrations++;
            //LSb is 1 if odd
            if(seq & 1)
                seq = (seq * 3) + 1;
            else
                seq >>= 1;
        }
        if(iterrations > maxIterrations){
            maxIterrations = iterrations;
            answer = i;
        }

    }

    clock_t end = clock();
    float time = (float)(end-begin)/CLOCKS_PER_SEC;

    printf("%ld has %ld steps\n",answer, maxIterrations);
    printf("Took %f seconds\n",time);
    return(EXIT_SUCCESS);

}
