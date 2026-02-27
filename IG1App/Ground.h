#pragma once
#include "Entity.h"

class Ground :
    public EntityWithColors
{
public:
    Ground(GLdouble, GLdouble);
    void render(const glm::mat4& modelViewMat) const override;
};

