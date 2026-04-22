#include "Ground.h"

Ground::Ground(GLdouble w, GLdouble h, GLuint rw, GLuint rh, Texture* tex) : EntityWithTexture(tex)
{
	mMesh = Mesh::generateRectangleTexCor(w, h, rw, rh);
}