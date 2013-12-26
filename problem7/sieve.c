#include <stdio.h>
#include <stdlib.h>


typedef struct ints2 {
	//number
	int  num;
	//boolean, 1 indicates prime, 0 inicates not prime
	int  isPrime;
}	ints;

int arryInit(ints *arry, int size);
int eleminate(ints *arry, int size);
int printPrimes(ints *arry, int size);
int findPrime(ints *arry, int size);

int main(){
	int nthPrime=10001;
	int i=0, arrySize=120000, count=1, currentPrime;
	ints arry[arrySize];
	arryInit(arry, arrySize);
	findPrime(arry, arrySize);
	for(i=0; i<arrySize; i++){
		if(arry[i].isPrime==1){
			if(count==nthPrime){
				printf("%i ",arry[i].num);
			
			}
			currentPrime= arry[i].num;
			count++;				
		}
	}
	if(count<nthPrime){
		printf("%ith prime could not be found with the given array size.\nThe buffer size managed to find the %ith prime which is %i\n",
		nthPrime, count, currentPrime);
	}
	printf("\n");
	return 0;
}

//initialize the whole array with numbers 2 though the final number
int arryInit(ints *arry, int size){
	int i = 0;
	for (i =0 ; i<size; i++){
		arry[i].num=i+2;
		arry[i].isPrime=1;	
	}
}



//step through the ary and eleminate prime numbers
int findPrime(ints *arry, int size){
	int place=0; //out place withing the array
	
	while(place<size){
		if(arry[place].isPrime==1){//if prime
			eleminateForward(arry, place, size);
			//printf("eliminateing all %is\n", arry[place].num); //testprint
		}
	place++;
	}
}

//sets all muliples of the given place to not prime
int eleminateForward(ints *arry, int place, int size){
	int Pnumber= arry[place].num;
	place+=	Pnumber;//find the first multiple
	
	//make sure we are in range of the array
	while(place<size){
		arry[place].isPrime=0;	//set the multiple to not prime	
		place+=Pnumber;	//go to the next multiple
	}
}
