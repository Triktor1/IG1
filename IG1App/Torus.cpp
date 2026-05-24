#include "Torus.h"
#include "Texture.h"

Torus::Torus(GLdouble R, GLdouble r, GLuint nPoints, GLuint nSamples, GLfloat angleMax, GLfloat angleMaxPoints) :
	ColorMaterialEntity()
{
	std::vector<glm::vec2> profile;
	//GLdouble alphaStep = 2 * std::numbers::pi / (float)nPoints;
	//GLdouble alpha = std::numbers::pi / 2;
	GLdouble alphaStep = angleMaxPoints / (float)nPoints;
	GLdouble alpha = angleMaxPoints;
	for (int i = 0; i <= nPoints; ++i) {
		profile.emplace_back(R + r * cos(alphaStep * i - alpha), r * sin(alphaStep * i - alpha));
	}
	mMesh = IndexMesh::generateByRevolution(profile, nSamples, angleMax);
}

Torus2TextHor::Torus2TextHor(GLdouble R, GLdouble r, Texture* tex1, Texture* tex2, GLuint nPoints, GLuint nSamples) :
	EntityWithTexture(tex1)
{
	mTex2 = tex2;
	std::vector<glm::vec2> profile;
	GLdouble alphaStep = 2 *  std::numbers::pi / (float)nPoints;
	GLdouble alpha = std::numbers::pi / 2;
	for (int i = 0; i <= nPoints; ++i) {
		profile.emplace_back(R + r * cos(alphaStep * i - alpha), r * sin(alphaStep * i - alpha));
	}
	mMesh = IndexMesh::generateByRevolution(profile, nSamples, std::numbers::pi);
}

void Torus2TextHor::render(const glm::mat4& modelViewMat) const {
	if (mMesh != nullptr) {
		glm::mat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication

		mShader->use();
		mShader->setUniform("texture", mModulate);

		if (mTexture != nullptr) mTexture->bind();
		upload(aMat);
		mMesh->render();
		if (mTexture != nullptr) mTexture->unbind();

		if (mTex2 != nullptr) mTex2->bind();
		upload(aMat);

		glm::mat4 rot = glm::rotate(glm::mat4(1.0), glm::radians(180.0f), glm::vec3(0, 1, 0));
		glm::mat4 aMat2 = modelViewMat * rot;
		upload(aMat2);
		mMesh->render();
		if (mTex2 != nullptr) mTex2->unbind();
	}
}

Torus2TextVer::Torus2TextVer(GLdouble R, GLdouble r, Texture* tex1, Texture* tex2, GLuint nPoints, GLuint nSamples) :
	EntityWithTexture(tex1)
{
	mTex2 = tex2;
	std::vector<glm::vec2> profile;
	GLdouble alphaStep = std::numbers::pi / (float)nPoints;
	GLdouble alpha = std::numbers::pi;
	for (int i = 0; i <= nPoints; ++i) {
		profile.emplace_back(R + r * cos(alphaStep * i - alpha), r * sin(alphaStep * i - alpha));
	}
	mMesh = IndexMesh::generateByRevolution(profile, nSamples, std::numbers::pi * 2);
}

void Torus2TextVer::render(const glm::mat4& modelViewMat) const {
	if (mMesh != nullptr) {
		glm::mat4 aMat = modelViewMat * mModelMat; // glm matrix multiplication

		mShader->use();
		mShader->setUniform("texture", mModulate);

		if (mTexture != nullptr) mTexture->bind();
		upload(aMat);
		mMesh->render();
		if (mTexture != nullptr) mTexture->unbind();

		if (mTex2 != nullptr) mTex2->bind();
		upload(aMat);

		glm::mat4 rot = glm::rotate(glm::mat4(1.0), glm::radians(180.0f), glm::vec3(1, 0, 0));
		glm::mat4 aMat2 = modelViewMat * rot;
		upload(aMat2);
		mMesh->render();
		if (mTex2 != nullptr) mTex2->unbind();
	}
}