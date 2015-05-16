/*
 * 此题主要考察简单数学运算的实现以及函数的使用。
 * */

#include <stdio.h>
#include "vector.h"    // ../../inc/vector.h

int main(void)
{
	// Vector a = {3, 4, 5}, b = {4, 3, 5}, c = {-5, -12, -13};    // i know i'm lazy ...
	Vector a, b, c;

	printf("Please enter your vectors (\"x,y,z\") ...\n");
	printf("A = "); getVector(&a);
	printf("B = "); getVector(&b);
	printf("C = "); getVector(&c);

	printf("\nDoing the calculation ...");
	printf("\na . b = %f", dotProduct(a,b));
	printf("\na x b = "); printVector(crossProduct(a,b));
	printf("\na . (b x c) = %f", scalarTripleProduct(a,b,c));
	printf("\na x (b x c) = "); printVector(vectorTripleProduct(a,b,c));
	printf("\n");

	return 0;
}

