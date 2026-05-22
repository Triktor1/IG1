#include "ColorMaterialEntity.h"
#include <vector>

class Torus :
	public ColorMaterialEntity
{
public:
	Torus(GLdouble R, GLdouble r, GLuint nPoints = 40, GLuint nSamples = 40, GLfloat angleMax = 2 * std::numbers::pi, GLfloat angleMaxPoints = 2 * std::numbers::pi);
};