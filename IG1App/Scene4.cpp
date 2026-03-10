#include "Scene4.h"

using namespace glm;

void
Scene4::init()
{
	//Variables del RGBCube
	GLdouble l = 200.0;

	Scene::init();

	// GROUND
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

	// BOX
	Texture* texBox1 = new Texture();
	Texture* texBox2 = new Texture();
	texBox1->load("../assets/images/papelE.png", 255);
	texBox2->load("../assets/images/container.jpg", 255);
	gTextures.push_back(texBox1);
	gTextures.push_back(texBox2);
	Box* box = new Box(50, texBox1, texBox2);
	gObjects.push_back(box);
	box->setModelMat(glm::translate(box->modelMat(), glm::vec3(140.0, 25.0, 0.0)));

	// STAR
	Texture* texS = new Texture();
	texS->load("../assets/images/rueda.png", 255);
	gTextures.push_back(texS);
	Star3D* star = new Star3D(17, 8, 17, texS);
	gObjects.push_back(star);
	star->setModelMat(glm::translate(star->modelMat(), glm::vec3(140.0, 25.1, 0.0)));

	// PHOTO
	Texture* empty = new Texture();
	gTextures.push_back(empty);
	Photo* photo = new Photo(100, 100, empty);
	gObjects.push_back(photo);
	
	gObjects.back()->setModelMat(groundRot);
	photo->setModelMat(glm::translate(photo->modelMat(), glm::vec3(0, 0, 0.1)));

	// GLASSPARAPET
	Texture* texGlass = new Texture();
	texGlass->load("../assets/images/windowC.png", 255);
	gTextures.push_back(texGlass);
	GlassParapet* glass = new GlassParapet(400, texGlass);
	gObjects.push_back(glass);
	glass->setModelMat(glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 0.3f, 1.0f)));
}
