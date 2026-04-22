#include "Scene5.h"

using namespace glm;

void
Scene5::init()
{
	Scene::init();

	//Parámetros del Torus
	GLdouble torusR = 80, torusr = 40;

	Torus* torus = new Torus(torusR, torusr);
	torus->setColor(vec4(0, 1, 0, 1));
	gOpaqueObjects.push_back(torus);
}
