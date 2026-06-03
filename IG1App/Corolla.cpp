#include "Corolla.h"

Corolla::Corolla(GLfloat w, GLfloat h, GLuint points, GLuint Samples ) :
	EntityWithMaterial()
{
	mMesh = IndexMesh::generateCorolla(w, h, points, Samples);
	setMaterial(Material(glm::vec4(1,1,0,1)));
}