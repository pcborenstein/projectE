#include "maths.h"
#include <math.h>
int sumOfSquares(int n ){
	int sum;
	sum = n*(n+1)*(2*n+1)/6;
	
	return sum;
}
int sumOfNums(int n){
	int sum = n*(n+1)/2;
	return sum;
	}

int diff(int n){
	int sumOfSq = sumOfSquares(n);
	int sumOfN = sumOfNums(n);
	float sqOfN	= pow(sumOfN, 2);
	int result = sqOfN - sumOfSq;
	return result;
}
