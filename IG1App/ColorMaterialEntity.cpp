#include "ColorMaterialEntity.h"

ColorMaterialEntity::ColorMaterialEntity(glm::vec4 color) :
	SingleColorEntity(color)
{
	mShader = Shader::get("simple_light");
}

void ColorMaterialEntity::render(const glm::mat4& modelViewMat) const
{
	if (mMesh != nullptr) {
		mShader->use();
		mShader->setUniform("color", mColor);
		upload(modelViewMat * mModelMat);

		mMesh->render();

		if (true) { //provisional
			glm::mat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
			Shader* shader = Shader::get("normals");
			shader->use();
			mMesh->render();
		}
	}
}
