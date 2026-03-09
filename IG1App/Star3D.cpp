#include "Star3D.h"

Star3D::Star3D(GLdouble re, GLuint np, GLdouble h) : SingleColorEntity(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f))
{
	mMesh = Mesh::generateStar3D(re, np, h);
}
