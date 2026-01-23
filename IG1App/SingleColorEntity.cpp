#include "SingleColorEntity.h"

SingleColorEntity::SingleColorEntity(glm::vec4 color) :
	mColor(color)
{
	mShader->get("simple");
}

void SingleColorEntity::render(const glm::mat4& modelViewMat) const {
	if (mMesh != nullptr) {
		mShader->setUniform("color", mColor);
		mShader->use();
		mMesh->render();
	}
}

//Getter y setter de mColor
glm::vec4 SingleColorEntity::getColor() {
	return mColor;
}

void SingleColorEntity::setColor(glm::vec4 color = glm::vec4(1, 1, 1, 1)) {
	mColor = color;
}