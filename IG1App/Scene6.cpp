#include "Scene6.h"

void 
Scene6::init() {
	Scene::init();

	//Parámetros del Indexed Box
	GLdouble idxBoxLength = 200;

	IndexedBox* idxBox = new IndexedBox(idxBoxLength);
	idxBox->setColor(glm::vec4(0, 1, 0, 1));
	gOpaqueObjects.push_back(idxBox);
}