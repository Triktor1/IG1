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
		
		//Pongo esto porque da error en algunos dispositivos
		glEnable(GL_CULL_FACE);
		
		//Defino el método de render por delante y renderizo
		glCullFace(GL_FRONT);
		glPolygonMode(GL_FRONT, GL_LINE);
		mMesh->render();

		//Defino el método de render por detrás y renderizo
		glCullFace(GL_BACK);
		glPolygonMode(GL_BACK, GL_FILL);
		mMesh->render();

		//Lo dejo como estaba antes para no afectar a otros objetos
		glDisable(GL_CULL_FACE);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		upload(aMat);
	}
}