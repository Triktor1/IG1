#include "Scene5.h"

using namespace glm;

void
Scene5::init()
{
	Scene::init();
	Torus* torus = new Torus(40, 40);
	gOpaqueObjects.push_back(torus);
}
