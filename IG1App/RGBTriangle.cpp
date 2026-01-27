#include "RGBTriangle.h"

RGBTriangle::RGBTriangle(GLdouble r) : EntityWithColors()
{
	mMesh = Mesh::generateRGBTriangle(r, 0, 0);
}

RGBTriangle::RGBTriangle(GLdouble r, GLdouble x, GLdouble y) : EntityWithColors()
{
	mMesh = Mesh::generateRGBTriangle(r, x, y);
}

void RGBTriangle::render(const glm::mat4& modelViewMat) const {
	if (mMesh != nullptr) {
		glm::mat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		mShader->use();
		upload(aMat);

		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		mMesh->render();
		glCullFace(GL_FRONT);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		mMesh->render();
		glDisable(GL_CULL_FACE);
	}
}