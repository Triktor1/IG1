#include "Sphere.h"


Sphere::Sphere(GLdouble radius, GLuint nParallels, GLuint nMeridians):
ColorMaterialEntity()
{
    std::vector<glm::vec2> profile;

	GLdouble alphaStep = 2 * std::numbers::pi / (float)nParallels;
	GLdouble alpha = std::numbers::pi / 2;
	for (int i = 0; i <= nParallels/2; ++i) {
		profile.emplace_back(radius * cos(alphaStep * i - alpha), radius * sin(alphaStep * i - alpha));
	}
    mMesh = IndexMesh::generateByRevolution(profile, nMeridians);
}