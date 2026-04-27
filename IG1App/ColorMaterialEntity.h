#ifndef _H_ColorMaterialEntity_H
#define _H_ColorMaterialEntity_H
#include "EntityWithMaterial.h"
class ColorMaterialEntity :
    public EntityWithMaterial
{
private:
    static bool mShowNormals;
public:
    ColorMaterialEntity(const glm::vec4& color = glm::vec4(1, 1, 1, 1));
    void render(const glm::mat4& modelViewMat) const override;
	static void toggleNormals() { mShowNormals = !mShowNormals; }
    void setColor(glm::vec4);
};
#endif