#include <stdio.h>
#include <stdlib.h>


char isPalin(int test);
char *deComp(int whole);
void nextValues(int *num1, int *num2);

int main(){
	//largest number possible fom multiplying 2 3 digit numbers together
	char myBool=0;
	int palins[3000], i=0, j=0;
	int num1=999, num2=999;
	int largestNum= 0;
	for(num1=100;num1<1000; num1++){
		for(num2=num1; num2<1000; num2++){
			if(isPalin(num1*num2)){
				palins[i]=num1*num2;
				i++;
			}
		}
	}
	printf("%i\n",i);
	for(j=0; j<(i+1); j++){
		if(palins[j]>largestNum){
			largestNum=palins[j];
		}
	}
	printf("%i\n", largestNum);
	return 0;
}

void nextValues( int *num1, int *num2){
	if(
		(*num1 -1) * *num2
		>
		*num1 * (*num2 -1)
	){
		*num1=*num1 -1;
	}else{
		*num2=*num2 -1;	
	}
}
char isPalin( int test){
	//first consider if we are testing a 6 diit number
	char ret=0; //initialize false
	char* arry = (char *)malloc(7*sizeof(char));
	sprintf( arry, "%i", test);
	if(test>=100000){
		if((arry[0]==arry[5]) &&
		(arry[1]==arry[4]) &&
		(arry[2]==arry[3])){
			ret=1;
		}
	}else{
		if((arry[0]==arry[4]) &&
		(arry[1]==arry[3])){
			ret=1;
		}
	}
	free(arry);
	return ret;
}
