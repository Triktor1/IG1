#include "SingleColorEntity.h"

SingleColorEntity::SingleColorEntity(glm::vec4 color) :
	Abs_Entity(), mColor(color)
{
	mShader = Shader::get("simple");
}

void SingleColorEntity::render(const glm::mat4& modelViewMat) const {
	if (mMesh != nullptr) {
		glm::mat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		mShader->use();
		mShader->setUniform("color", mColor);
		upload(aMat);
		mMesh->render();
		mShader->setUniform("color", glm::vec4(0, 0, 0, 1));
	}
}

//Getter y setter de mColor
glm::vec4 SingleColorEntity::getColor() {
	return mColor;
}

void SingleColorEntity::setColor(glm::vec4 color = glm::vec4(1, 1, 1, 1)) {
	mColor = color;
}