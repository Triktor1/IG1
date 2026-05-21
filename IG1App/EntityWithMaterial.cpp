#include "EntityWithMaterial.h"

EntityWithMaterial::EntityWithMaterial() {
    mShader = Shader::get("light");
}

void
EntityWithMaterial::render(const glm::mat4& modelViewMat) const
{
    mShader->use();
    // Carga los atributos del material en la GPU
    material.upload(*mShader);
    upload(modelViewMat * mModelMat);
    mMesh->render();

    if (mShowNormals) {
        Shader* shader = Shader::get("normals");
        shader->use();
        shader->setUniform("modelViewMat", modelViewMat * mModelMat);
        mMesh->render();
        std::cout << "drawing normals\n";
    }
}
EntityWithMaterial::~EntityWithMaterial(){
}
