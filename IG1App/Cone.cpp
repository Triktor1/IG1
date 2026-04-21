#include "Cone.h"

Cone::Cone(GLdouble h, GLdouble r, GLdouble R, GLuint nRings, GLuint nSamples) : 
ColorMaterialEntity() 
{
	std::vector<glm::vec2> profile;
	GLdouble alphaStep = (R - r) / (float)nRings;
	GLdouble alpha = r;
	for (int i = nRings; i > 0; --i) {
		profile.emplace_back(alpha - alphaStep * i, h - alphaStep*i);
	}
	mMesh = IndexMesh::generateByRevolution(profile, nSamples);
}