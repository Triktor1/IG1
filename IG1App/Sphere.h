#ifndef SPHERE_H_
#define SPHERE_H_
#include "ColorMaterialEntity.h"
class Sphere :
    public ColorMaterialEntity
{
public:
    Sphere(GLdouble radius, GLuint nParallels, GLuint nMeridians, GLfloat angleMax = 2 * std::numbers::pi);
};

#endif