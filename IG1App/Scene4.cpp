#include "Scene4.h"

using namespace glm;

void
Scene4::init()
{
	//Variables del RGBCube
	GLdouble l = 200.0;

	Scene::init();

	Texture* tex = new Texture();
	tex->load("../assets/images/baldosaC.png", 255);
	gTextures.push_back(tex);
	gObjects.push_back(new Ground(l * 2, l * 2, 4, 4, tex));

	glm::mat4 groundRot = {
		{1, 0, 0, 0},
		{0, 0, -1, 0}, //0, cos(90), -sin(90), 0
		{0, 1, 0, 0}, //0, sin(90), cos(90), 0
		{0, 0, 0, 1}
	};
	gObjects.back()->setModelMat(groundRot);

	//gObjects.push_back(new BoxOutline(200));
}
