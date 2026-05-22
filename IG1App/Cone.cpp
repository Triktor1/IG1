#include "Cone.h"

Cone::Cone(GLdouble h, GLdouble r, GLdouble R, GLuint nRings, GLuint nSamples, GLfloat angleMax) : 
ColorMaterialEntity() 
{
	std::vector<glm::vec2> profile;
	GLdouble alphaStep = (R - r) / (float)nRings;
	GLdouble alpha = r;
	profile.emplace_back(0, 0);
	for (int i = nRings; i > 0; --i) {
		profile.emplace_back(r + (R - r) * (float)i / nRings, h - (h * (float)i / nRings));
	}
	

	mMesh = IndexMesh::generateByRevolution(profile, nSamples, angleMax);
}