#include "RGBRectangle.h"

RGBRectangle::RGBRectangle(GLdouble w, GLdouble h) : EntityWithColors()
{
	mMesh = Mesh::generateRGBRectangle(w, h);
}

//Override al render de EntityWithColors, añadiendo distinción del tipo de renderizado en la parte posterior y anterior
void RGBRectangle::render(const glm::mat4& modelViewMat) const {
	if (mMesh != nullptr) {
		glm::mat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		mShader->use();
		glPolygonMode(GL_FRONT, GL_LINE);
		glPolygonMode(GL_BACK, GL_FILL);
		upload(aMat);
		mMesh->render();
	}
}