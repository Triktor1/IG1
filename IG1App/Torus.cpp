#include "Torus.h"

Torus::Torus(GLdouble R, GLdouble r, GLuint nPoints, GLuint nSamples, GLfloat angleMax, GLfloat angleMaxPoints) :
	ColorMaterialEntity()
{
	std::vector<glm::vec2> profile;
	GLdouble alphaStep = angleMaxPoints / (float)nPoints;
	GLdouble alpha = angleMaxPoints;
	for (int i = 0; i <= nPoints; ++i) {
		profile.emplace_back(R + r * cos(alphaStep * i - alpha), r * sin(alphaStep * i - alpha));
	}
	mMesh = IndexMesh::generateByRevolution(profile, nSamples, angleMax);
}
