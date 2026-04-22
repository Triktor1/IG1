#include "Scene5.h"

using namespace glm;

void
Scene5::init()
{
	Scene::init();

	//Parámetros del Torus
	GLdouble torus_R = 80, torus_r = 40;

	Torus* torus = new Torus(torus_R, torus_r);
	torus->setColor(vec4(0, 1, 0, 1));
	gOpaqueObjects.push_back(torus);
}
