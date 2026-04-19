#ifndef SINGLECOLORENTITY_H
#define SINGLECOLORENTITY_H

#include "Entity.h"
class SingleColorEntity :
	public Abs_Entity
{
protected:
	glm::vec4 mColor;

public:
	SingleColorEntity(glm::vec4 color = glm::vec4(1.0));

	void render(const glm::mat4& modelViewMat) const override;

	glm::vec4 getColor();
	void setColor(glm::vec4);
};
#endif