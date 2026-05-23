#include "ColorMaterialEntity.h"
#include "EntityWithTexture.h"

#include <vector>

class Torus :
	public ColorMaterialEntity
{
public:
	Torus(GLdouble R, GLdouble r, GLuint nPoints = 40, GLuint nSamples = 40, GLfloat angleMax = 2 * std::numbers::pi, GLfloat angleMaxPoints = 2 * std::numbers::pi);
};


class Torus2TextHor :
	public EntityWithTexture {
public:
	Torus2TextHor(GLdouble R, GLdouble r, Texture* tex1, Texture* tex2, GLuint nPoints = 40, GLuint nSamples = 40);
	void render(const glm::mat4& modelViewMat) const override;

private:
	Texture* mTex2;
};