#include "Cube.h"

Cube::Cube(GLdouble l, glm::vec4 color) : SingleColorEntity(color)
{
	mMesh = Mesh::generateCube(l);
}

void Cube::render(const glm::mat4& modelViewMat) const {
	if (mMesh != nullptr) {
		glm::mat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		mShader->use();
		upload(aMat);

		//Activamos culling
		glEnable(GL_CULL_FACE);

		//Quitamos la cara delantera, y la repintamos con puntos
		glCullFace(GL_FRONT);
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
		mMesh->render();

		//Quitamos la cara trasera, y la repintamos con líneas
		glCullFace(GL_BACK);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		mMesh->render();

		//Reiniciamos glPolygonMode
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		//Desactivamos culling
		glDisable(GL_CULL_FACE);
	}
}
