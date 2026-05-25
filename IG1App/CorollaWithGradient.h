#ifndef _H_CorollaWithGradient_H_
#define _H_CorollaWithGradient_H_
#include "Entity.h"
class CorollaWithGradient : public EntityWithColors
{
public:
	CorollaWithGradient(GLfloat height, GLfloat width, GLuint nParallels, GLuint nStops, glm::vec4 color1 = glm::vec4(0,0,0,1), glm::vec4 color2 = glm::vec4(0,0,0,1));

};

#endif