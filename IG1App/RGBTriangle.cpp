#include "RGBTriangle.h"

RGBTriangle::RGBTriangle(GLdouble r, GLdouble x = 0, GLdouble y = 0) : EntityWithColors()
{
	mMesh = Mesh::generateRGBTriangle(r, 0, 0);
	mModelMat = glm::translate(mModelMat, glm::vec3(x, y, 0));
}

void RGBTriangle::render(const glm::mat4& modelViewMat) const {
	if (mMesh != nullptr) {
		glm::mat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		mShader->use();
		upload(aMat);

		//Activamos culling
		glEnable(GL_CULL_FACE);

		//Quitamos la cara delantera, y la repintamos con líneas
		glCullFace(GL_FRONT);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		mMesh->render();

		//Quitamos la cara trasera, y la repintamos con relleno
		glCullFace(GL_BACK);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); //Dejamos el polygon mode en fill para los siguientes objetos
		mMesh->render();

		//Desactivamos culling
		glDisable(GL_CULL_FACE);
	}
}

void RGBTriangle::update() {
	alphaTriangle += -5.0;
	alpha += 2.0;

	mModelMat = glm::mat4(1.0f);
	mModelMat = glm::translate(mModelMat, glm::vec3(r * cos(glm::radians(alpha)) + x, r * sin(glm::radians(alpha)) + y, 0.0));
	mModelMat = glm::rotate(mModelMat, glm::radians(alphaTriangle), glm::vec3(0.0, 0.0, 1.0));
}