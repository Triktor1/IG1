#pragma once
#include "SingleColorEntity.h"
class Cube :
    public SingleColorEntity
{
public:
	Cube(GLdouble l, glm::vec4 color = glm::vec4(0, 0, 0, 1));
	void render(const glm::mat4& modelViewMat) const;
};

