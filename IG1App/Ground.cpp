#include "Ground.h"

Ground::Ground(GLdouble w, GLdouble h) : EntityWithColors()
{
	mMesh = Mesh::generateRectangle(w, h);

}

//Override al render de EntityWithColors, añadiendo distinción del tipo de renderizado en la parte posterior y anterior
void Ground::render(const glm::mat4& modelViewMat) const {
	if (mMesh != nullptr) {
		glm::mat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		mShader->use();
		aMat = glm::rotate(aMat, glm::radians(90.0f), glm::vec3(1.0, 0.0, 0.0));
		upload(aMat);
		mMesh->render();
	}
}