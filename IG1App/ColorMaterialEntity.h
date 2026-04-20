#ifndef _H_ColorMaterialEntity_H
#define _H_ColorMaterialEntity_H
#include "SingleColorEntity.h"
class ColorMaterialEntity :
    public SingleColorEntity
{
private:
    static bool mShowNormals;
public:
    ColorMaterialEntity();
    void render(const glm::mat4& modelViewMat) const override;
	static void toggleNormals() { mShowNormals = !mShowNormals; }
};
#endif