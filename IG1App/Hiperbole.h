#pragma once
#include "ColorMaterialEntity.h"
class Hiperbole :
    public ColorMaterialEntity
{
public:
    Hiperbole(GLdouble w, GLdouble h, GLuint nPoints, GLuint nSamples, GLfloat angleMax = 2 * std::numbers::pi);
};

