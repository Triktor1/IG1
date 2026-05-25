#include "Corolla.h"

Corolla::Corolla(GLfloat height, GLfloat width, GLuint nParallels, GLuint nStops) {
	mMesh = IndexMesh::generateCorolla(height, width, nParallels, nStops);
}