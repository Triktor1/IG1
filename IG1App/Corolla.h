#ifndef _H_Corolla_H_
#define _H_Corolla_H_
#include "ColorMaterialEntity.h"
class Corolla :
    public ColorMaterialEntity
{
public:
    Corolla(GLfloat height, GLfloat width, GLuint nParallels, GLuint nStops);
};

#endif