#include "Scene3.h"

using namespace glm;

void
Scene3::init()
{
	Scene::init();
	gObjects.push_back(new RGBCube(200));
}