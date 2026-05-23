#include "Exprimidor.h"
#include <iostream>

Exprimidor::Exprimidor(GLdouble w, GLdouble h,
    GLuint nRings, GLuint nSamples, GLfloat angleMax)
{
    std::vector<glm::vec2> profile;
    float x, y;
    for (int i = nRings; i > 0; --i) {
        x = w * ((float)(i)/nRings);
        
        y = h * sin( 2.0 * std::numbers::pi * ((float)i / nRings));
        
        profile.emplace_back(x, y);
    }

    mMesh = IndexMesh::generateByRevolution(profile, nSamples, angleMax);
}