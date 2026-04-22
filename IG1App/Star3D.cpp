#include "Star3D.h"
#include "Texture.h"
Star3D::
Star3D(GLdouble re, GLuint np, GLdouble h, Texture* text) : EntityWithTexture(text)
{
	mMesh = Mesh::generateStar3DTexCor(re, np, h);
}

void 
Star3D:: render(const glm::mat4& modelViewMat) const {
    if (mMesh != nullptr) {
        glm::mat4 aMat = modelViewMat * mModelMat;
        mShader->use();
        mShader->setUniform("texture", mModulate);

        if (mTexture != nullptr) mTexture->bind();
        upload(aMat);
        mMesh->render();

        glm::mat4 inv = glm::scale(glm::dmat4(1.0), glm::dvec3(1.0, 1.0, -1.0));
        glm::mat4 aMat2 = modelViewMat * mModelMat * inv;
        upload(aMat2);
        mMesh->render();
        if (mTexture != nullptr) mTexture->unbind();
    }
}

void 
Star3D::update() {
    alphaAct += alpha;

    glm::mat4 rot = glm::rotate(glm::mat4(1.0f), glm::radians(alphaAct), glm::vec3(0.0, 1.0, 0.0)) *
                    glm::rotate(glm::mat4(1.0f), glm::radians(alphaAct), glm::vec3(0.0, 0.0, 1.0)); //hacer la rotacion
    glm::vec3 pos = glm::vec3(mModelMat[3]); //coger posicion
    //aplicar
    mModelMat = glm::translate(glm::mat4(1.0f), pos) * rot; 
}