#include <stdio.h>
#include "vector3d.h"

float dotProduct(Vector3D a, Vector3D b)
{
	return (a.x*b.x + a.y*b.y + a.z*b.z);
}

Vector3D crossProduct(Vector3D a, Vector3D b)
{
	Vector3D c = {a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x};
	return c;
}

float scalarTripleProduct(Vector3D a, Vector3D b, Vector3D c)
{
	return dotProduct(a,crossProduct(b,c));
}
 
Vector3D vectorTripleProduct(Vector3D a, Vector3D b, Vector3D c)
{
	return crossProduct(a,crossProduct(b,c));
}

int getVector3D(Vector3D *a)
{
	return scanf("%f,%f,%f", &(a->x), &(a->y), &(a->z));
}

void printVector3D(Vector3D a)
{
	printf("[%f, %f, %f]", a.x, a.y, a.z);
}

