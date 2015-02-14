/* Problem

A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a2 + b2 = c2
For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/
#include <stdio.h>
#include <math.h>

#define MAX_C 500
#define MIN_C 334
#define MAX_B 499
#define MAX_A 332
#define SUM 1000

int main(){

	int a,b,c;


	printf("int max:%d sizeof: %d\n", 0x7fffffff, (int)sizeof(int));
	//set through a range of possible a values
	for(a = MAX_A; a > 0; a--){
		//figure out the max c based on the summation rule
		int maxC = SUM - (2 * a + 1);
		//revise if the max c value makes a right triangle impossible
		if(maxC > MAX_C)
			maxC = MAX_C;
		//the minimum c is the smallest possible hypotinus with the given A
		//the min c occures when B is at its max
		int maxB = (SUM - a) / 2 - 1;
		int minC = SUM - a -maxB;
		if(minC > MIN_C)
			minC = MIN_C;
		//set though c values
		for(c = minC; c < maxC; c++){
			b = SUM - a - c;
			//do we for a triangle?
			if(pow(c,2) == (pow(a,2) + pow(b,2))){
				printf("SOLUTION! a: %d, b: %d, c: %d\n", a, b, c);
				printf("product: %d\n",(c * b * a));
			}
		}
	}
}
