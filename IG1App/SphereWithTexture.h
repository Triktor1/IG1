#ifndef SPHEREWITHTEXTURE_H_
#define SPHEREWITHTEXTURE_H_
#include "EntityWithTexture.h"
class SphereWithTexture :
    public EntityWithTexture
{
public:
	SphereWithTexture(GLdouble radius, GLuint nParallels, GLuint nMeridians, Texture* tex1);
};
#endif