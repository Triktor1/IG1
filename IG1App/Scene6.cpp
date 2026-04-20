#include "Scene6.h"

void 
Scene6::init() {
	Scene::init();
	IndexedBox* idxBox = new IndexedBox(200);
	idxBox->setColor(glm::vec4(0, 1, 0, 1));
	gOpaqueObjects.push_back(idxBox);
}