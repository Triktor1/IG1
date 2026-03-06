#pragma once
#include "EntityWithTexture.h"
#include "Texture.h"

class Ground :
    public EntityWithTexture
{
public:
    Ground(GLdouble, GLdouble, Texture*);
};

