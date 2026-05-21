#ifndef _H_ColorMaterialEntity_H
#define _H_ColorMaterialEntity_H
#include "EntityWithMaterial.h"
class ColorMaterialEntity :
    public EntityWithMaterial
{
public:
    ColorMaterialEntity(const glm::vec4& color = glm::vec4(1, 1, 1, 1));
    void setColor(glm::vec4);
};
#endif