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

	Texture* texBox1 = new Texture();
	Texture* texBox2 = new Texture();
	texBox1->load("../assets/images/papelE.png", 255);
	texBox2->load("../assets/images/container.jpg", 255);
	gTextures.push_back(texBox1);
	gTextures.push_back(texBox2);
	gObjects.push_back(new Box(200, texBox1, texBox2));

	gObjects.push_back(new Star3D(140, 8, 180));
}
