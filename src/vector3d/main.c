#include <stdio.h>
#include "vector3d.h"    // ../../inc/vector3d.h

int main()
{
	// Vector3D a = {3, 4, 5}, b = {4, 3, 5}, c = {-5, -12, -13};    // i know i'm lazy ...
	Vector3D a, b, c;

	printf("Please enter your vectors (\"x,y,z\") ...\n");
	printf("A = "); getVector3D(&a);
	printf("B = "); getVector3D(&b);
	printf("C = "); getVector3D(&c);

	printf("\nDoing the calculation ...");
	printf("\na . b = %f", dotProduct(a,b));
	printf("\na x b = "); printVector3D(crossProduct(a,b));
	printf("\na . (b x c) = %f", scalarTripleProduct(a,b,c));
	printf("\na x (b x c) = "); printVector3D(vectorTripleProduct(a,b,c));
	printf("\n");

	return 0;
}

