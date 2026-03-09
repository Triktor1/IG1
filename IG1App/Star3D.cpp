#include "Star3D.h"

Star3D::
Star3D(GLdouble re, GLuint np, GLdouble h) : SingleColorEntity(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f))
{
	mMesh = Mesh::generateStar3D(re, np, h);
}

void 
Star3D:: render(const glm::mat4& modelViewMat) const {
    if (mMesh != nullptr) {
        glm::mat4 aMat = modelViewMat * mModelMat;
        mShader->use();
        upload(aMat);
        mMesh->render();
    }
}