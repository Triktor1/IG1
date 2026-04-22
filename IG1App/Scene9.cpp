#include "Scene9.h"

void
Scene9::init() {
	Scene::init();
	Snowman* snowman = new Snowman(100);
	//Ejemplo para mover al CompoundEntities
	//glm::mat4 snowmanMat = snowman->modelMat() * glm::translate(glm::mat4(1), glm::vec3(100,0,0));
	//snowman->setModelMat(snowmanMat);
	gOpaqueObjects.push_back(snowman);
}