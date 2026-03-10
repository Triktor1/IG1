#include "GlassParapet.h"
#include "Texture.h"

GlassParapet::GlassParapet(GLdouble l, Texture* tex) {
	mMesh = Mesh::generateBoxOutlineTexCor(l);
	setTexture(tex);
}

void GlassParapet::render(const glm::mat4& modelViewMat) const {
	if (mMesh != nullptr) {
		glm::mat4 aMat = modelViewMat * mModelMat;
		mShader->use();
		mShader->setUniform("texture", mModulate);

		glDepthMask(GL_FALSE);
		glEnable(GL_BLEND);

		glBlendFunc(GL_CONSTANT_ALPHA, GL_ONE_MINUS_CONSTANT_ALPHA);
		glBlendColor(1.0f, 1.0f, 1.0f, 0.5f);

		if (mTexture != nullptr) mTexture->bind();
		upload(aMat);
		mMesh->render();
		if (mTexture != nullptr) mTexture->unbind();

		glDisable(GL_BLEND);
		glDepthMask(GL_TRUE);
	}
}