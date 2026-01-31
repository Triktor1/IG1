#pragma once
#include "Entity.h"
class RGBTriangle :
    public EntityWithColors
{
private:
    GLdouble x = 0, y = 0, r = 100, alpha = 0;
public:
    RGBTriangle(GLdouble, GLdouble, GLdouble);

    void render(const glm::mat4& modelViewMat) const;
    void update() override;
};