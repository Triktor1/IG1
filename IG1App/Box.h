#pragma once
#include "EntityWithTexture.h"
class Mesh;
class Box :
    public EntityWithTexture
{
public:
	Box(GLdouble l, Texture* tex1, Texture* tex2);
	void render(const glm::mat4& modelViewMat) const override;
	~Box() {
		delete mMeshTapa;
		delete mMeshFondo;
	};
private:
	Texture* mTexture;
	Mesh* mMeshTapa, *mMeshFondo;
	GLdouble l;
};