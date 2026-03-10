#pragma once
#include "EntityWithTexture.h"
class Mesh;
class Box :
    public EntityWithTexture
{
public:
	Box(GLdouble l, Texture* tex1, Texture* tex2);
	void render(const glm::mat4& modelViewMat) const override;
	void update();
	~Box() {
		delete mMeshTapa;
		delete mMeshFondo;
	};
private:
	Texture* mTexture;
	Mesh* mMeshTapa, *mMeshFondo;
	GLdouble l;
	GLfloat angle = 0.0f, angleInterval = 2.0f;
	bool opening = true;

};