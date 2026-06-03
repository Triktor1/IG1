#ifndef COROLLAGRADIENT_H_
#define COROLLAGRADIENT_H_

#include "Entity.h"
#include <vector>

class CorollaWithGradient :
	public EntityWithColors
{
public:
	CorollaWithGradient(GLfloat w, GLfloat h, GLuint points = 40, GLuint Samples = 40);
};
#endif