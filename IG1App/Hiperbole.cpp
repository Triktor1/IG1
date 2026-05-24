#include "Hiperbole.h"
#include <cmath>
Hiperbole::Hiperbole(GLdouble w, GLdouble h, GLuint nPoints, GLuint nSamples, GLfloat angleMax) :
	ColorMaterialEntity()
{
	std::vector<glm::vec2> profile;
	
	float offset = 7.50f;

	float x, y, difW, difH;
	difW = ((std::numbers::pi*2.0) / (nPoints-1));
	difH = h / (nPoints - 1);

	//for (int i =for (int i = nPoints - 1; i >= 0; --i) {; i >= 0; --i) {
	for (int i = 0; i <= nPoints - 1; ++i) {
		y = i * difH;

		x = offset + w/2.0 + (w/2 - offset) * cos(difW * i)/2;

		profile.emplace_back(x, y);
	}

	mMesh = IndexMesh::generateByRevolution(profile, nSamples, angleMax);
}