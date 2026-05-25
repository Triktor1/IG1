#include "CorollaWithGradient.h"

CorollaWithGradient::CorollaWithGradient(GLfloat height, GLfloat width, GLuint nParallels, GLuint nStops, glm::vec4 color1, glm::vec4 color2) {
	mMesh = IndexMesh::generateCorolla(height, width, nParallels, nStops, color1, color2);
}