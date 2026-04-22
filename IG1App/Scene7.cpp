#include "Scene7.h"

void
Scene7::init() {
	Scene::init();

	Droid* con = new Droid(150);
	gOpaqueObjects.push_back(con);
}