#pragma once
#include "Entity.h"
class SingleColorEntity :
	public Abs_Entity
{
private:
	glm::vec4 mColor;

public:
	SingleColorEntity(glm::vec4);

	void render(const glm::mat4& modelViewMat) const override;

	glm::vec4 getColor();
	void setColor(glm::vec4);
};

