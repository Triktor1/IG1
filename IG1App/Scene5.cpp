#include "Scene5.h"

using namespace glm;

void
Scene5::init()
{
	Scene::init();

	//Parámetros del Torus
	GLdouble torus_R = 80, torus_r = 40;

	//Torus
	Torus* torus = new Torus(torus_R, torus_r, 40, 40, std::numbers::pi, std::numbers::pi);
	torus->setColor(vec4(0, 1, 0, 1));
	gOpaqueObjects.push_back(torus);
	//Cone* cone = new Cone(100, torus_r, torus_R, 20, 4, std::numbers::pi * 2);
	//cone->setColor(vec4(0, 1, 0, 1));
	//gOpaqueObjects.push_back(cone);
}
