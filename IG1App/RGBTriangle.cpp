#include "RGBTriangle.h"

RGBTriangle::RGBTriangle(GLdouble r, GLdouble x = 0, GLdouble y = 0) : EntityWithColors()
{
	mMesh = Mesh::generateRGBTriangle(r, x, y);
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
	alpha += 5.0;
	mModelMat = glm::rotate(glm::dmat4(1), glm::radians(alpha), glm::dvec3(0, 0, 1));
}