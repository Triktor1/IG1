#include "Star3D.h"

Star3D::
Star3D(GLdouble re, GLuint np, GLdouble h, Texture* text) : EntityWithTexture()
{
	mMesh = Mesh::generateStar3DTexCor(re, np, h);
    setTexture(text);
}

void 
Star3D:: render(const glm::mat4& modelViewMat) const {
    if (mMesh != nullptr) {
        glm::mat4 aMat = modelViewMat * mModelMat;
        mShader->use();
        upload(aMat);
        mMesh->render();

        glm::mat4 inv = glm::scale(glm::dmat4(1.0), glm::dvec3(1.0, 1.0, -1.0));
        glm::mat4 aMat2 = modelViewMat * mModelMat * inv;
        upload(aMat2);
        mMesh->render();
    }
}

void 
Star3D::update() {
    alphaAct += alpha;
    mModelMat = glm::rotate(glm::mat4(1.0f), glm::radians(alphaAct), glm::vec3(0.0, 1.0, 0.0)) *
                glm::rotate(glm::mat4(1.0f), glm::radians(alphaAct), glm::vec3(0.0, 0.0, 1.0));
}