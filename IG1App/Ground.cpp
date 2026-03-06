#include "Ground.h"

Ground::Ground(GLdouble w, GLdouble h, Texture* tex) : EntityWithTexture()
{
	mMesh = Mesh::generateRectangleTexCor(w, h);
	setTexture(tex);
}