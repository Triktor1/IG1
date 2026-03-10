#ifndef _H_Ground_H_
#define _H_Ground_H_
#include "EntityWithTexture.h"
#include "Texture.h"

class Ground :
    public EntityWithTexture
{
public:
    Ground(GLdouble, GLdouble, GLuint, GLuint, Texture*);
};
#endif
