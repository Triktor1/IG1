#include "BoxOutline.h"

BoxOutline::
BoxOutline(GLdouble l, Texture* tex1, Texture* tex2) : EntityWithTexture(tex1)
{
	mMesh = Mesh::generateBoxOutlineTexCor(l);
	boxTexture = tex2;
}

void BoxOutline::render(const glm::mat4& modelViewMat) const {
	if (mMesh != nullptr) {
		glm::mat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication
		mShader->use();
		mShader->setUniform("texture", mModulate);
		upload(aMat);

		//Activamos culling
		glEnable(GL_CULL_FACE);

		//Quitamos la cara delantera, y la repintamos con la textura de fuera
		glCullFace(GL_BACK);
		if (mTexture != nullptr) mTexture->bind();
		mMesh->render();
		if (mTexture != nullptr) mTexture->unbind();

		glCullFace(GL_FRONT);
		//Quitamos la cara trasera, y la repintamos con la textura de dentro
		if (boxTexture != nullptr) boxTexture->bind();
		mMesh->render();
		if (boxTexture != nullptr) boxTexture->unbind();

		//Desactivamos culling
		glDisable(GL_CULL_FACE);
	}
}