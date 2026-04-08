#include "Box.h"
#include "Mesh.h"
#include "Texture.h"

Box::Box(GLdouble l, Texture* tex1, Texture* tex2) : l(l)
{
	mMesh = Mesh::generateBoxOutlineTexCor(l);
	mMeshTapa = Mesh::generateRectangleTexCor(l, l, 1, 1);
	mMeshFondo = Mesh::generateRectangleTexCor(l, l, 1, 1);
	setTexture(tex1);
	boxTexture = tex2;
}

void Box::render(const glm::mat4& modelViewMat) const {
	if (mMesh != nullptr) {
		glm::mat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication

		mShader->use();
		mShader->setUniform("texture", mModulate);

		//Activamos culling
		glEnable(GL_CULL_FACE);

		glm::mat4 rotTapa = glm::rotate(glm::mat4(1.0), glm::radians(-90.0f), glm::vec3(1, 0, 0));
		glm::mat4 rotFondo = glm::rotate(glm::mat4(1.0), glm::radians(90.0f), glm::vec3(1, 0, 0));

		glm::mat4 tapaMat = aMat *
			glm::translate(glm::mat4(1.0f), glm::vec3(-l / 2.0f, l / 2.0f, 0)) * //Muevo para alterar el ancla
			glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(0, 0, 1)) * //Hago la rotación
			glm::translate(glm::mat4(1.0f), glm::vec3(l / 2.0f, 0, 0)) * //Deshago el primer translate (solo en el eje x para mantener el ancla)
			rotTapa;

		glm::mat4 fondoMat = aMat * glm::translate(glm::mat4(1.0f), glm::vec3(0, -l / 2.0, 0)) * rotFondo;

		// CARA DELANTERA
		glCullFace(GL_BACK);
		if (mTexture != nullptr)
			mTexture->bind();

		//Malla principal
		upload(aMat);
		mMesh->render();

		//Malla de la tapa
		if (mMeshTapa != nullptr) {
			upload(tapaMat);
			mMeshTapa->render();
		}

		//Malla del fondo
		if (mMeshFondo != nullptr) {
			upload(fondoMat);
			mMeshFondo->render();
		}

		if (mTexture != nullptr)
			mTexture->unbind();

		// CARA TRASERA
		glCullFace(GL_FRONT);
		if (boxTexture != nullptr)
			boxTexture->bind();

		//Malla principal
		upload(aMat);
		mMesh->render();

		//Malla de la tapa
		if (mMeshTapa != nullptr) {
			upload(tapaMat);
			mMeshTapa->render();
		}

		//Malla del fondo
		if (mMeshFondo != nullptr) {
			upload(fondoMat);
			mMeshFondo->render();
		}

		if (boxTexture != nullptr)
			boxTexture->unbind();

		//Desactivamos culling
		glDisable(GL_CULL_FACE);
	}
}

void Box::update() {
	if (opening)
		angle += angleInterval;
	else
		angle -= angleInterval;

	if (angle > 180.0f) {
		opening = false;
		angle = 180;
	}
	else if (angle < 0.0f) {
		opening = true;
		angle = 0;
	}
}

void Box::load() {
	mMesh->load();
	mMeshTapa->load();
	mMeshFondo->load();
}