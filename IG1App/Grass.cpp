#include "Grass.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"

using namespace glm;

Grass::Grass(GLdouble w, GLdouble h, Texture* tex) : EntityWithTexture(tex)
{
    mMesh = Mesh::generateRectangleTexCor(w, h, 1, 1);
    mShader = Shader::get("texture:texture_alpha");
}

void Grass::render(const glm::mat4& modelViewMat) const
{
    if (mMesh != nullptr) {
        glm::mat4 aMat = modelViewMat * mModelMat;
        mShader->use();
        mShader->setUniform("texture", mModulate);
       
        if (mTexture != nullptr) mTexture->bind();
        upload(aMat);
        mMesh->render();

        glm::mat4 rot = rotate(mat4(1.0f), radians(60.0f), vec3(0, 1, 0));
        upload(modelViewMat * mModelMat * rot);
        mMesh->render();

        glm::mat4 rot2 = rotate(mat4(1.0f), radians(120.0f), vec3(0, 1, 0));
        upload(modelViewMat * mModelMat * rot2);
        mMesh->render();

        if (mTexture != nullptr) mTexture->unbind();
    }
}