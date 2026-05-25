#ifndef RGBRECTANGLE_H_
#define RGBRECTANGLE_H_
#include "Entity.h"
class RGBRectangle :
    public EntityWithColors
{
public:
    RGBRectangle(GLdouble, GLdouble);
    void render(const glm::mat4& modelViewMat) const override;
};
#endif