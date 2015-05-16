#ifndef _VECTOR_H_
#define _VECTOR_H_ 1

#include <stdio.h>

typedef struct {
	float x, y, z;
} Vector;
// typedef float Vector[3];    // this is a bad idea.

float dotProduct(Vector a, Vector b);
Vector crossProduct(Vector a, Vector b);
float scalarTripleProduct(Vector a, Vector b, Vector c);
Vector vectorTripleProduct(Vector a, Vector b, Vector c);

int getVector(Vector* a);
void printVector(Vector a);

#endif /* _VECTOR_H_ */

