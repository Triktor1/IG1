#include "ColorMaterialEntity.h"

bool ColorMaterialEntity::mShowNormals = false;

ColorMaterialEntity::ColorMaterialEntity() :
	SingleColorEntity()
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

		if (mShowNormals) {
			glm::mat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
			Shader* shader = Shader::get("normals");
			shader->use();
			mMesh->render();
		}
	}
}
