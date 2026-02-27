#include "EntityWithTexture.h"
#include "Shader.h"
#include "Texture.h"

EntityWithTexture::EntityWithTexture() : mTexture(nullptr)
{
	mShader = Shader::get("texture");
}

void EntityWithTexture::render(const glm::mat4& modelViewMat) const {
	if (mTexture != nullptr && mMesh != nullptr) {
		glm::mat4 aMat = modelViewMat * mModelMat;
		mShader->setUniform("modeulate", mModulate);
		mTexture->bind();
		mMesh->render();
		mTexture->unbind();
		upload(aMat);
	}
}