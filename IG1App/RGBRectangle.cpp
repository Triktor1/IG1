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
		glPolygonMode(0x0404, 0x1B01); //GL_FRONT, GL_LINE, no funciona en uno de los dispositivos por alguna razón
		glPolygonMode(0x0405, 0x1B02); //GL_BACK, GL_FILL, lo mismo, no funciona...
		upload(aMat);
		mMesh->render();
	}
}