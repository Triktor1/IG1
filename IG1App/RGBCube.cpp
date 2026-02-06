#include "RGBCube.h"
#include "Cube.h"

RGBCube::RGBCube(GLdouble l) : EntityWithColors()
{
	mMesh = Mesh::generateRGBCubeTriangles(l);
}