#include "Scene9.h"

void
Scene9::init() {
	Scene::init();

	//Parámetros del Snowman
	GLdouble snowmanRadius = 100;

	Snowman* snowman = new Snowman(snowmanRadius);
	//Ejemplo para mover al CompoundEntities
	//glm::mat4 snowmanMat = snowman->modelMat() * glm::translate(glm::mat4(1), glm::vec3(100,0,0));
	//snowman->setModelMat(snowmanMat);
	gOpaqueObjects.push_back(snowman);
}