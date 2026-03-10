#ifndef _H_EntityWithTexture_H_
#define _H_EntityWithTexture_H_
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Entity.h"

class Texture;

class EntityWithTexture : public Abs_Entity
{
protected:
	Texture* mTexture;
	bool mModulate = false;

public:
	EntityWithTexture();
	virtual void render(const glm::mat4& modelViewMat) const override;
	void setTexture(Texture* tex) { mTexture = tex; };
};
#endif