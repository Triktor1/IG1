#include "RGBTriangle.h"

RGBTriangle::RGBTriangle(GLdouble r) : EntityWithColors()
{
	mMesh = Mesh::generateRGBTriangle(r);
}