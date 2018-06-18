#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char * mergeSort(char * nameList, int listLen);
char * selectSort(char * nameList, int listLen);

int main(void){
    FILE * fName = fopen("names.txt", "r");

    char buff[50000];
    char namesUnsorted[6000][20];
    int nameCount = 0;

    char * pBuff;

    pBuff = fgets(buff, 50000, fName);

    if(pBuff != buff)
        perror("problem with fgets\n");

    uint32_t indexBuff = 0;
    uint32_t indexChar = 0;
    while(buff[indexBuff] != '\0'){
        if(buff[indexBuff] == ','){
            namesUnsorted[nameCount][indexChar] = '\0';
            indexChar = 0;
            nameCount++;
        }else if(buff[indexBuff] != '"'){
            namesUnsorted[nameCount][indexChar] = buff[indexBuff];
            indexChar++;
            if(indexChar > 20){
                fprintf(stderr, "found name longer than 20 chars\n");
                exit(EXIT_FAILURE);
            }
        }
        indexBuff++;
    }
    //add null the the last name found
    namesUnsorted[nameCount][indexChar] = '\0';
    nameCount++;

    char * namesSorted;


#define SORT_COUNT  (1000)
    int i;
    for(i = 0; i < 0; i++)
        printf("%d : %s\n", i, namesUnsorted[i]);


    //char namesUnsorted2[SORT_COUNT][20] = {"AMY", "ANNA", "REBECCA", "VIRGINIA", "KATHLEEN", "PAMELA"};
    //namesSorted = selectSort(&namesUnsorted[0][0], 5);
    namesSorted = mergeSort(&namesUnsorted[0][0], nameCount);

    printf("\nAfter sort: \n");
    int nameLen;
    int j;
    int nameSum;
    uint64_t totalSum = 0;
    for(i = 0; i < nameCount; i++){
        nameSum = 0;
        nameLen = strlen(&namesSorted[i * 20]);
        for(j = 0; j < nameLen; j++)
            nameSum += (namesSorted[i * 20 + j] - 'A' + 1);
        nameSum *= (i + 1);
        totalSum += nameSum;
        printf("%4d %11s %6d\n", (i+1), &namesSorted[i * 20], nameSum);
    }
    printf("grand total: %ld\n", totalSum);


    /*
    char namesUnsorted2[5][20] = {"cbd", "aab", "aa", "aaa"};
    for(i = 0; i < 4; i++)
        printf("%s\n", namesUnsorted2[i]);

    char * namesSorted2 = selectSort(&namesUnsorted2[0][0], 4);
    for(i = 0; i < 5; i++)
        printf("%s\n", &namesSorted2[i * 20]);
        */
    exit(EXIT_SUCCESS);
}

char * mergeSort(char * nameList, int listLen){

    int i;

    /*
    printf("\nAll names recieved:\n");
    for(i = 0; i < listLen; i++)
        printf("%d %s\n",i, &nameList[i * 20]);
    */
    if(listLen > 3){
        int len1, len2;
        len1 = listLen / 2;
        len2 = listLen - len1;
        char * list1, * list2;
        char * sortedList1, * sortedList2;
        list1 = malloc(len1 * 20);
        list2 = malloc(len2 * 20);
        memcpy(list1, nameList, len1 * 20);
        memcpy(list2, &nameList[len1 * 20], len2 * 20);
        /*
        printf("breaking list %d into %d and %d lists\n", listLen, len1, len2);
        printf("\nUnsorted list 1:\n");
        for(i = 0; i < len1; i++)
            printf("%d %s\n",i, &list1[i * 20]);
        printf("\n");
        printf("\nUnsorted list 2:\n");
        for(i = 0; i < len2; i++)
            printf("%d %s\n",i, &list2[i * 20]);
        printf("\n");
        */
        sortedList1 = mergeSort(list1, len1);
        sortedList2 = mergeSort(list2, len2);
        /*
        printf("\nRetuned two soted lists sort for:\n");
        for(i = 0; i < len1; i++)
            printf("%d %s\n",i, &sortedList1[i * 20]);
        printf("and:\n");
        for(i = 0; i < len2; i++)
            printf("%d %s\n", i, &sortedList2[i * 20]);
        */
        free(list1);
        free(list2);
        char * sortedList;
        sortedList = malloc(listLen * 20);
        int index1, index2;
        int nameIndex1 = 0;
        int nameIndex2 = 0;
        int charIndex;
        while((nameIndex1 != len1) || (nameIndex2 != len2)){
            //if we have readched the len of either list
            if(nameIndex1 == len1){
                strncpy(&sortedList[(nameIndex1 + nameIndex2) * 20], &sortedList2[nameIndex2 * 20], 20);
                nameIndex2++;
            }else if(nameIndex2 == len2){
                strncpy(&sortedList[(nameIndex1 + nameIndex2) * 20], &sortedList1[nameIndex1 * 20], 20);
                nameIndex1++;
            }else{
                charIndex = 0;
                do{
                    if(charIndex == 20){
                        fprintf(stderr, "merge sort failed\n");
                        exit(EXIT_FAILURE);
                    }
                    if((sortedList1[(nameIndex1 * 20) + charIndex] == '\0')
                            && ( sortedList2[(nameIndex2 * 20) + charIndex] == 0)){
                        //if both names are the same
                        strncpy(&sortedList[(nameIndex1 + nameIndex2) * 20], &sortedList1[nameIndex1 * 20], 20);
                        nameIndex1++;
                        strncpy(&sortedList[(nameIndex1 + nameIndex2) * 20], &sortedList2[nameIndex2 * 20], 20);
                        nameIndex2++;
                        break;
                    }else if(sortedList1[(nameIndex1 * 20) + charIndex] == sortedList2[(nameIndex2 * 20) + charIndex]){
                        //same letter
                        charIndex++;
                        continue;
                    }else if(sortedList1[(nameIndex1 * 20) + charIndex] < sortedList2[(nameIndex2 * 20) + charIndex]){
                        //if name in list 1 comes first
                        strncpy(&sortedList[(nameIndex1 + nameIndex2) * 20], &sortedList1[nameIndex1 * 20], 20);
                        nameIndex1++;
                        break;
                    }else if(sortedList1[(nameIndex1 * 20) + charIndex] > sortedList2[(nameIndex2 * 20) + charIndex]){
                        strncpy(&sortedList[(nameIndex1 + nameIndex2) * 20], &sortedList2[nameIndex2 * 20], 20);
                        nameIndex2++;
                        break;
                    }else{
                        fprintf(stderr, "merge sort failed\n");
                        exit(EXIT_FAILURE);
                    }

                 }while(1);
            }
        }
        /*
        printf("name indexes %d == %d, %d == %d\n", nameIndex1, len1, nameIndex2, len2);
        printf("\ncombined lists\n");
        for(i = 0; i < listLen; i++)
            printf("%d %s\n", i, &sortedList[i * 20]);
            */

        free(sortedList1);
        free(sortedList2);
        return sortedList;
    }else{
        /*
        printf("\nBegining select sort for:\n");
        for(i = 0; i < listLen; i++)
            printf("%s\n", &nameList[i * 20]);
            */

        char * smallSorted = selectSort(nameList, listLen);
        /*
        printf("\nAfter select sort:\n");
        for(i = 0; i < listLen; i++)
            printf("%s\n", &smallSorted[i * 20]);
            */
        return smallSorted;
    }
}

char * selectSort(char * nameList, int listLen){
    char * sortedList;
    sortedList = malloc(listLen * 20);

    bool picked[5] = {false, false, false, false, false};
    bool considered[5] = {false, false, false, false, false};
    int namesConsidered;
    int namesSorted = 0;

    int i;
    int charIndex;
    char smallestValue;

    charIndex = 0;
    while(namesSorted < listLen){
        smallestValue = 0x7f;

        for(i = 0; i < listLen; i++){
            if((charIndex > 0) && (considered[i] == false))
                continue;
            if((picked[i] == false) && (nameList[i*20 + charIndex] < smallestValue))
                smallestValue = nameList[i*20 + charIndex];
        }

        //printf("smallesValue %c, %d\n", (char)smallestValue, (int)smallestValue);
        namesConsidered = 0;
        //find all names with smallestValue
        for(i = 0; i < listLen; i++){
            if((charIndex > 0) && (considered[i] == false))
                continue;
            if((picked[i] == false) && (nameList[i*20 + charIndex] == smallestValue)){
                considered[i] = true;
                namesConsidered++;
            }else{
                considered[i] = false;
            }
        }
        if(namesConsidered == 1){
            //only one name has the lowest character
            for(i = 0; i < listLen; i++)
                if(considered[i] == true){
                    picked[i] = true;
                    strncpy(&sortedList[namesSorted * 20], &nameList[i * 20], 20);
                    namesSorted++;
                }
            charIndex = 0;
        }else if(smallestValue == '\0'){
            //both match null if the names are the same
            for(i = 0; i < listLen; i++)
                if(considered[i] == true){
                    picked[i] = true;
                    strncpy(&sortedList[namesSorted * 20], &nameList[i * 20], 20);
                    namesSorted++;
                }
            charIndex = 0;
        }else{
            //move onto the next character
            charIndex++;
            if(charIndex == 20){
                fprintf(stderr, "select sort failed\n");
                exit(EXIT_FAILURE);
            }
        }
    }
    return sortedList;
}
