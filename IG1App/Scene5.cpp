#include "Scene5.h"

using namespace glm;

void
Scene5::init()
{
	Scene::init();
	Torus* torus = new Torus(80, 40);
	torus->setColor(vec4(0, 0.5, 0, 1));
	gOpaqueObjects.push_back(torus);
}
