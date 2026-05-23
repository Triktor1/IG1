#pragma once
#include "ColorMaterialEntity.h"
class Exprimidor :
    public ColorMaterialEntity
{
public:
    Exprimidor(GLdouble w, GLdouble h, GLuint nRings, GLuint nSamples, GLfloat angleMax = 2 * std::numbers::pi);
};

