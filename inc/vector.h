#ifndef _VECTOR_H_
#define _VECTOR_H_ 1

#include <stdio.h>

typedef struct {
	float x, y, z;
} Vector;
// typedef float Vector[3];    // this is a bad idea.

float dotProduct(Vector a, Vector b)
{
	return (a.x*b.x + a.y*b.y + a.z*b.z);
}

Vector crossProduct(Vector a, Vector b)
{
	Vector c = {a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x};
	return c;
}

float scalarTripleProduct(Vector a, Vector b, Vector c)
{
	return dotProduct(a,crossProduct(b,c));
}
 
Vector vectorTripleProduct(Vector a, Vector b, Vector c)
{
	return crossProduct(a,crossProduct(b,c));
}

int getVector(Vector* a)
{
	return scanf("%f,%f,%f", &(a->x), &(a->y), &(a->z));
}

void printVector(Vector a)
{
	printf("[%f, %f, %f]", a.x, a.y, a.z);
}

#endif /* _VECTOR_H_ */

