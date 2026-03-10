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

        glm::mat4 inv = glm::scale(glm::dmat4(1.0), glm::dvec3(1.0, 1.0, -1.0));
        glm::mat4 aMat2 = modelViewMat * mModelMat * inv;
        upload(aMat2);
        mMesh->render();
    }
}