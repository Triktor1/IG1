#include "Scene5.h"

using namespace glm;

void
Scene5::init()
{
	Scene::init();
	Torus* torus = new Torus(20, 10);
	gOpaqueObjects.push_back(torus);
}
