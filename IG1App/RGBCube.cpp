#include "RGBCube.h"
#include "Cube.h"

RGBCube::RGBCube(GLdouble l) : EntityWithColors()
{
	mMesh = Mesh::generateRGBCubeTriangles(l);
	mModelMat = glm::translate(mModelMat, glm::vec3(l/2, l/2, -l/2));
}

void RGBCube::update() {
	alphaAct += alpha;

	switch (eje) {
	case 0:
		mModelMat = glm::rotate(glm::mat4(1), glm::radians(alpha), glm::vec3(1.0, 0.0, 0.0)) * mModelMat;
		break;
	case 1:
		mModelMat = glm::rotate(glm::mat4(1), glm::radians(alpha), glm::vec3(0.0, 0.0, 1.0)) * mModelMat;
		break;
	case 2:
		mModelMat = glm::rotate(glm::mat4(1), glm::radians(alpha), glm::vec3(0.0, 1.0, 0.0)) * mModelMat;
		break;
	}

	if (alphaAct >= 180) {
		alphaAct = 0;
		eje = (eje+1) % 3;
	}
}