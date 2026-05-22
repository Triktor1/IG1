#include "Disk.h"

Disk::Disk(GLdouble R, GLdouble r, GLuint nRings, GLuint nSamples, GLfloat angleMax):
ColorMaterialEntity(){
	std::vector<glm::vec2> profile;

	GLdouble alphaStep = (R-r) /nRings;
	GLdouble alpha = r;
	for (int i = 0; i <= nRings; ++i) {
		profile.emplace_back(alpha + alphaStep * i, 0);
	}
	mMesh = IndexMesh::generateByRevolution(profile, nSamples, angleMax);
}