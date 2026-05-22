#include "Sphere.h"


Sphere::Sphere(GLdouble radius, GLuint nParallels, GLuint nMeridians, GLfloat angleMax):
ColorMaterialEntity()
{
   mMesh = IndexMesh::generateSphere(radius, nParallels, nMeridians, angleMax);
}