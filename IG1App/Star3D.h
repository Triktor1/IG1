#ifndef _H_Star3D_H_
#define _H_Star3D_H_
#include "EntityWithTexture.h"
class Star3D :
    public EntityWithTexture
{
public:
    Star3D (GLdouble re, GLuint np, GLdouble h, Texture* text);
    void render(const glm::mat4& modelViewMat) const override;
    void update() override;

private:
    GLfloat alpha = 2.0f, alphaAct = 0;
};
#endif