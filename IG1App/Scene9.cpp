#include "Scene9.h"

void
Scene9::init() {
	Scene::init();
	Snowman* snowman = new Snowman(100);
	gOpaqueObjects.push_back(snowman);
}