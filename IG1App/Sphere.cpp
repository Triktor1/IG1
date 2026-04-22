#include "Sphere.h"


Sphere::Sphere(GLdouble radius, GLuint nParallels, GLuint nMeridians):
ColorMaterialEntity()
{
   mMesh = IndexMesh::generateSphere(radius, nParallels, nMeridians);
}