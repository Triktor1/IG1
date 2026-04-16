#include "SingleColorEntity.h"
#include <vector>

class Torus :
	public SingleColorEntity
{
public:
	Torus(GLdouble R, GLdouble r, GLuint nPoints = 40, GLuint nSamples = 40);
};
