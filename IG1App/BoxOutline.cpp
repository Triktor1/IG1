#include "BoxOutline.h"

BoxOutline::
BoxOutline(GLdouble l, Texture* tex1, Texture* tex2) : EntityWithTexture()
{
	mMesh = Mesh::generateBoxOutlineTexCor(l);
	setTexture(tex1);
	mTexture = tex2;
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
		if (EntityWithTexture::mTexture != nullptr) EntityWithTexture::mTexture->bind();
		mMesh->render();
		if (EntityWithTexture::mTexture != nullptr) EntityWithTexture::mTexture->unbind();

		glCullFace(GL_FRONT);
		//Quitamos la cara trasera, y la repintamos con la textura de dentro
		if (BoxOutline::mTexture != nullptr) BoxOutline::mTexture->bind();
		mMesh->render();
		if (BoxOutline::mTexture != nullptr) BoxOutline::mTexture->unbind();

		//Desactivamos culling
		glDisable(GL_CULL_FACE);
	}
}