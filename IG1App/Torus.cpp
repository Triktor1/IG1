#include "Torus.h"

Torus::Torus(GLdouble R, GLdouble r, GLuint nPoints, GLuint nSamples, GLfloat angleMax, GLfloat angleMaxPoints) :
	ColorMaterialEntity()
{
	std::vector<glm::vec2> profile;
	GLdouble alphaStep = angleMaxPoints / (float)nPoints;
	GLdouble alpha = angleMaxPoints;
	for (int i = 0; i <= nPoints; ++i) {
		profile.emplace_back(R + r * cos(alphaStep * i - alpha), r * sin(alphaStep * i - alpha));
	}
	mMesh = IndexMesh::generateByRevolution(profile, nSamples, angleMax);
}

TorusTwoTextureHor::TorusTwoTextureHor(Texture* tex1, Texture* tex2, GLdouble R, GLdouble r, GLuint nPoints, GLuint nSamples) :
	EntityWithTexture(tex1), tex2(tex2) {
	std::vector<glm::vec2> profile;
	GLdouble alphaStep = 2 * std::numbers::pi / (float)nPoints;
	GLdouble alpha = std::numbers::pi / 2;
	for (int i = 0; i <= nPoints; ++i) {
		profile.emplace_back(R + r * cos(alphaStep * i - alpha), r * sin(alphaStep * i - alpha));
	}
	mMesh = IndexMesh::generateByRevolution(profile, nSamples, std::numbers::pi);
}

void TorusTwoTextureHor::render(const glm::mat4& modelViewMat) const {
	if (mMesh != nullptr) {
		glm::mat4 aMat = modelViewMat * mModelMat;
		mShader->use();
		mShader->setUniform("modulate", mModulate);

		upload(aMat);
		if (mTexture != nullptr) mTexture->bind();
		mMesh->render();
		if (mTexture != nullptr) mTexture->unbind();

		aMat *= glm::rotate(glm::mat4(1.0f), glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));

		upload(aMat);
		if (tex2 != nullptr) tex2->bind();
		mMesh->render();
		if (tex2 != nullptr) tex2->unbind();
	}
}

TorusTwoTextureVer::TorusTwoTextureVer(Texture* tex1, Texture* tex2, GLdouble R, GLdouble r, GLuint nPoints, GLuint nSamples) :
	EntityWithTexture(tex1), tex2(tex2) {
	std::vector<glm::vec2> profile;
	GLdouble alphaStep = std::numbers::pi / (float)nPoints;
	GLdouble alpha = std::numbers::pi;
	for (int i = 0; i <= nPoints; ++i) {
		profile.emplace_back(R + r * cos(alphaStep * i - alpha), r * sin(alphaStep * i - alpha));
	}
	mMesh = IndexMesh::generateByRevolution(profile, nSamples, std::numbers::pi * 2);
}

void TorusTwoTextureVer::render(const glm::mat4& modelViewMat) const {
	if (mMesh != nullptr) {
		glm::mat4 aMat = modelViewMat * mModelMat;
		mShader->use();
		mShader->setUniform("modulate", mModulate);

		upload(aMat);
		if (mTexture != nullptr) mTexture->bind();
		mMesh->render();
		if (mTexture != nullptr) mTexture->unbind();

		aMat *= glm::rotate(glm::mat4(1.0f), glm::radians(180.0f), glm::vec3(1.0f, 0.0f, 0.0f));

		upload(aMat);
		if (tex2 != nullptr) tex2->bind();
		mMesh->render();
		if (tex2 != nullptr) tex2->unbind();
	}
}
