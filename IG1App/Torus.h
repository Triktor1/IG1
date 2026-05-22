#include "ColorMaterialEntity.h"
#include "EntityWithTexture.h"
#include "Texture.h"
#include <vector>

class Torus :
	public ColorMaterialEntity
{
public:
	Torus(GLdouble R, GLdouble r, GLuint nPoints = 40, GLuint nSamples = 40, GLfloat angleMax = 2 * std::numbers::pi, GLfloat angleMaxPoints = 2 * std::numbers::pi);
};

class TorusTwoTextureHor :
	public EntityWithTexture
{
public:
	TorusTwoTextureHor(Texture* tex1, Texture* tex2, GLdouble R, GLdouble r, GLuint nPoints = 40, GLuint nSamples = 40);
	virtual void render(const glm::mat4& modelViewMat) const override;
private:
	Texture* tex2;
	bool horizontal;
};

class TorusTwoTextureVer :
	public EntityWithTexture
{
public:
	TorusTwoTextureVer(Texture* tex1, Texture* tex2, GLdouble R, GLdouble r, GLuint nPoints = 40, GLuint nSamples = 40);
	virtual void render(const glm::mat4& modelViewMat) const override;
private:
	Texture* tex2;
};