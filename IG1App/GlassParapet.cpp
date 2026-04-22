#include "GlassParapet.h"
#include "Texture.h"

GlassParapet::GlassParapet(GLdouble l, Texture* tex):EntityWithTexture(tex){
	mMesh = Mesh::generateBoxOutlineTexCor(l);
}

void GlassParapet::render(const glm::mat4& modelViewMat) const {
	if (mMesh != nullptr) {
		glm::mat4 aMat = modelViewMat * mModelMat;
		mShader->use();
		mShader->setUniform("modulate", mModulate);

		glDepthMask(GL_FALSE);
		glEnable(GL_BLEND);

		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		if (mTexture != nullptr) mTexture->bind();
		upload(aMat);
		mMesh->render();
		if (mTexture != nullptr) mTexture->unbind();

		glDisable(GL_BLEND);
		glDepthMask(GL_TRUE);
	}
}