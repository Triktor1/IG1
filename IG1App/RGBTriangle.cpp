#include "RGBTriangle.h"

RGBTriangle::RGBTriangle(GLdouble r) : EntityWithColors()
{
	mMesh = Mesh::generateRGBTriangle(r, 0, 0);
}

RGBTriangle::RGBTriangle(GLdouble r, GLdouble x, GLdouble y) : EntityWithColors()
{
	mMesh = Mesh::generateRGBTriangle(r, x, y);
}