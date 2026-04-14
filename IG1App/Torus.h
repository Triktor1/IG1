#include "SingleColorEntity.h"

class Torus :
	public SingleColorEntity
{
public:
	Torus(GLdouble R, GLdouble r, GLuint nPoints = 40, GLuint nSamples = 40);
	void render(const glm::mat4& modelViewMat) const;
};
