#ifndef COROLLA_H_
#define COROLLA_H_
#include "EntityWithMaterial.h"
#include <vector>

class Corolla :
	public EntityWithMaterial
{
public:
	Corolla(GLfloat w, GLfloat h, GLuint points = 40, GLuint Samples = 40);
};
#endif