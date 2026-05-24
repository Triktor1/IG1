#include "Exprimidor.h"

Exprimidor::Exprimidor(GLdouble w, GLdouble h,
    GLuint nRings, GLuint nSamples, GLfloat angleMax)
{
    std::vector<glm::vec2> profile;
    float x, y;
    float difW = w / (nRings - 1);
    float difH = 2.0 * std::numbers::pi / (nRings - 1);
    for (int i = nRings - 1; i >= 0; --i) {
        x = i * difW;
        y = h * sin( difH*i);
        
        profile.emplace_back(x, y);
    }

    mMesh = IndexMesh::generateByRevolution(profile, nSamples, angleMax);
}