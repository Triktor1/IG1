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

		//mShader->setUniform("modulate", mModulate);
		mShader->setUniform("texture", mModulate);

		if (mTexture != nullptr) mTexture->bind();
		upload(aMat);
		mMesh->render();
		if (mTexture != nullptr) mTexture->unbind();
	}
}