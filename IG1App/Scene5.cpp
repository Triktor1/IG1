#include "Scene5.h"

using namespace glm;

void
Scene5::init()
{
	Scene::init();
	Torus* torus = new Torus(40, 20);
	torus->setColor(vec4(0, 255, 0, 255));
	gOpaqueObjects.push_back(torus);
}
