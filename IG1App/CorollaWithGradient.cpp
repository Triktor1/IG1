#include "CorollaWithGradient.h"

CorollaWithGradient::CorollaWithGradient(GLfloat w, GLfloat h, GLuint points, GLuint Samples) :
	EntityWithColors()
{
	mMesh = IndexMesh::generateCorollaGradient(w, h, points, Samples);
}