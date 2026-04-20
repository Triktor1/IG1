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
		glm::mat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		upload(aMat);
		mShader->setUniform("color", mColor);
		mMesh->render();

		if (mShowNormals) {
			Shader* shader = Shader::get("normals");
			shader->use();
			mMesh->render();
		}
	}
}
