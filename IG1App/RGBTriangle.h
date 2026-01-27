#pragma once
#include "Entity.h"
class RGBTriangle :
    public EntityWithColors
{
public:
    RGBTriangle(GLdouble);
    RGBTriangle(GLdouble, GLdouble, GLdouble);

    void render(const glm::mat4& modelViewMat) const;
};