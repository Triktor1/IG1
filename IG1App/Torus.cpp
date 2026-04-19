#include "Torus.h"

Torus::Torus(GLdouble R, GLdouble r, GLuint nPoints, GLuint nSamples):
ColorMaterialEntity()
{
	std::vector<glm::vec2> profile;
	for(int i = 0; i <= nPoints; ++i) {
		GLdouble alpha = 2 * 3.1415926f * i / (float)nPoints;
		profile.emplace_back(R + r * cos(alpha), r * sin(alpha));
	}
	mMesh = IndexMesh::generateByRevolution(profile, nSamples);
}
