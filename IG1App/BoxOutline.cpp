#include "BoxOutline.h"

BoxOutline::
BoxOutline(GLdouble l): SingleColorEntity(glm::vec4(0.0, 0.0, 0.0, 1.0))
{
	mMesh = Mesh::generateBoxOutline(l);
}
