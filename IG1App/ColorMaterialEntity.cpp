#include "ColorMaterialEntity.h"

bool ColorMaterialEntity::mShowNormals = false;

ColorMaterialEntity::ColorMaterialEntity(const glm::vec4& color) :
	EntityWithMaterial()
{
	//mShader = Shader::get("simple_light");
	setMaterial(Material(color));
}

void ColorMaterialEntity::render(const glm::mat4& modelViewMat) const
{
	if (mMesh != nullptr) {
		mShader->use();
		glm::mat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		upload(aMat);
		material.upload(*mShader);
		mMesh->render();

		if (mShowNormals) {
			Shader* shader = Shader::get("normals");
			shader->use();
			mMesh->render();
		}
	}
}

void ColorMaterialEntity::setColor(glm::vec4 color = glm::vec4(1, 1, 1, 1)) {
	material.setAmb(color);
	material.setDiff(color);
	material.setSpec(color);
}