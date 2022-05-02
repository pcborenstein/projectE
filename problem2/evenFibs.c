#include <stdio.h>
#include <stdint.h>

#define MAX_NUM 4000000

int main(){

    uint64_t sumOfEvens = 0;
    uint32_t store1 = 1;
    uint32_t evenFib = 0;
    uint32_t fibNum = 1;

    while(store1 < MAX_NUM){
        fibNum = store1 + evenFib;

        evenFib = fibNum + store1;
        if(evenFib < MAX_NUM){
            sumOfEvens += evenFib;
        }
        store1 = evenFib + fibNum;
    }
    printf("\n");
    printf("solution %ld\n",sumOfEvens);
}
