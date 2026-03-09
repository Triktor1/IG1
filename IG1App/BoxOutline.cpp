#include "BoxOutline.h"

BoxOutline::
BoxOutline(GLdouble l, Texture* tex): EntityWithTexture()
{
	mMesh = Mesh::generateBoxOutlineTexCor(l);
	setTexture(tex);
}
