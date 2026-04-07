#include "EntityWithTexture.h"
#include "Shader.h"
#include "Texture.h"

EntityWithTexture::EntityWithTexture() : mTexture(nullptr)
{
	mShader = Shader::get("texture");
}

void EntityWithTexture::render(const glm::mat4& modelViewMat) const {
	if (mMesh != nullptr) {
		glm::mat4 aMat = modelViewMat * mModelMat;
		mShader->use();
		mShader->setUniform("modulate", mModulate);

		glEnable(GL_BLEND);

		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		if (mTexture != nullptr) mTexture->bind();
		upload(aMat);
		mMesh->render();
		if (mTexture != nullptr) mTexture->unbind();

		glDisable(GL_BLEND);
	}
}