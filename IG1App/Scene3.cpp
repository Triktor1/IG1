#include "Scene3.h"

using namespace glm;

void
Scene3::init()
{
	//Variables del RGBCube
	GLdouble l = 200.0;

	Scene::init();
	RGBCube* cube = new RGBCube(l);
	cube->moveRGBCube(l / 2, l / 2, -l / 2);
	gObjects.push_back(cube);
}