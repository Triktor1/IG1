#include "Box.h"
#include "Mesh.h"
#include "Texture.h"

Box::Box(GLdouble l, Texture* tex1, Texture* tex2) : EntityWithTexture(), l(l)
{
	mMesh = Mesh::generateBoxOutlineTexCor(l);
	mMeshTapa = Mesh::generateRectangleTexCor(l, l, 1, 1);
	mMeshTapa->load();
	mMeshFondo = Mesh::generateRectangleTexCor(l, l, 1, 1);
	mMeshFondo->load();
	setTexture(tex1);
	mTexture = tex2;
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

		glm::mat4 tapaMat = aMat * glm::translate(glm::mat4(1.0f), glm::vec3(0, l / 2.0, 0)) * rotTapa;

		glm::mat4 fondoMat = aMat * glm::translate(glm::mat4(1.0f), glm::vec3(0, -l / 2.0, 0)) * rotFondo;

		// CARA DELANTERA
		glCullFace(GL_BACK);
		if (EntityWithTexture::mTexture != nullptr) 
			EntityWithTexture::mTexture->bind();

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

		if (EntityWithTexture::mTexture != nullptr) 
			EntityWithTexture::mTexture->unbind();

		// CARA TRASERA
		glCullFace(GL_FRONT);
		if (Box::mTexture != nullptr) 
			Box::mTexture->bind();
		
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

		if (Box::mTexture != nullptr) 
			Box::mTexture->unbind();

		//Desactivamos culling
		glDisable(GL_CULL_FACE);
	}
}