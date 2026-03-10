#ifndef _H_GlassParapet_H_
#define _H_GlassParapet_H_
#include "EntityWithTexture.h"
class GlassParapet :
    public EntityWithTexture
{
public:
	GlassParapet(GLdouble l, Texture* tex1);
	void render(const glm::mat4& modelViewMat) const override;
};
#endif
