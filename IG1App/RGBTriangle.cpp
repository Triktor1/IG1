#include "RGBTriangle.h"

RGBTriangle::RGBTriangle(GLdouble r, GLdouble x = 0, GLdouble y = 0) : EntityWithColors(), x(x), y(y), r(r)
{
	mMesh = Mesh::generateRGBTriangle(r, 0, 0);
	mModelMat = glm::translate(mModelMat, glm::vec3(x, y, 0));
}

void RGBTriangle::render(const glm::mat4& modelViewMat) const {
	if (mMesh != nullptr) {
		glm::mat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		mShader->use();
		upload(aMat);
		
		mMesh->render();
	}
}

void RGBTriangle::update() {
	mModelMat = glm::rotate(glm::mat4(1), glm::radians(alpha), glm::vec3(0.0, 0.0, 1.0)) * glm::rotate(mModelMat, glm::radians(-3*alpha), glm::vec3(0.0, 0.0, 1.0));
}