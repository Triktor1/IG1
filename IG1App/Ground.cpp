#include "Ground.h"

Ground::Ground(GLdouble w, GLdouble h, GLuint rw, GLuint rh, Texture* tex) : EntityWithTexture()
{
	mMesh = Mesh::generateRectangleTexCor(w, h, rw, rh);
	setTexture(tex);
}