#include "RGBTriangle.h"

RGBTriangle::RGBTriangle(GLdouble r) : EntityWithColors()
{
	mMesh = Mesh::generateRGBTriangle(r, 0, 0);
}
	
void RGBTriangle::update() {
	mModelMat = glm::rotate(glm::mat4(1), glm::radians(alpha), glm::vec3(0.0, 0.0, 1.0)) * glm::rotate(mModelMat, glm::radians(-3*alpha), glm::vec3(0.0, 0.0, 1.0));
}

void RGBTriangle::moveRGBTriangle(GLdouble x, GLdouble y, GLdouble z) {
	mModelMat = glm::translate(mModelMat, glm::vec3(x, y, z));
}