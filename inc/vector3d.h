#ifndef _VECTOR3D_H_
#define _VECTOR3D_H_ 1

typedef struct {
	float x, y, z;
} Vector3D;
// typedef float Vector3D[3];    // this is a bad idea.

float    dotProduct(Vector3D a, Vector3D b);
Vector3D crossProduct(Vector3D a, Vector3D b);
float    scalarTripleProduct(Vector3D a, Vector3D b, Vector3D c);
Vector3D vectorTripleProduct(Vector3D a, Vector3D b, Vector3D c);

int  getVector3D(Vector3D *a);
void printVector3D(Vector3D a);

#endif /* _VECTOR3D_H_ */

