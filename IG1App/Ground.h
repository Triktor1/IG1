#pragma once
#include "Entity.h"

class Ground :
    public EntityWithColors
{
    Ground(GLdouble, GLdouble);
    void render(const glm::mat4& modelViewMat) const override;
};

