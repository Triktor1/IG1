#pragma once
#include "EntityWithTexture.h"
class Star3D :
    public EntityWithTexture
{
public:
    Star3D (GLdouble re, GLuint np, GLdouble h, Texture* text);
    void render(const glm::mat4& modelViewMat) const override;
    void update() override;

private:
    Texture* mTexture;
    GLfloat alpha = 2.0f, alphaAct = 0;
};