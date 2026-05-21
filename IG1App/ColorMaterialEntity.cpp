#include "ColorMaterialEntity.h"

bool ColorMaterialEntity::mShowNormals = false;

ColorMaterialEntity::ColorMaterialEntity(const glm::vec4& color) :
	EntityWithMaterial()
{
	mShader = Shader::get("light");
	setMaterial(Material(color));
}


void ColorMaterialEntity::setColor(glm::vec4 color = glm::vec4(1, 1, 1, 1)) {
	material.setAmb(color);
	material.setDiff(color);
	material.setSpec(color);
}