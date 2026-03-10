#ifndef _H_Grass_H_
#define _H_Grass_H_
#include "EntityWithTexture.h"
class Grass :
    public EntityWithTexture
{
public:
    Grass(GLdouble w, GLdouble h, Texture* tex);
    virtual void render(const glm::mat4& modelViewMat) const override;
};
#endif