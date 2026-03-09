#include "Scene1.h"

using namespace glm;

void
Scene1::init()
{
	Scene::init();
	gObjects.push_back(new RegularPolygon(6, 300.0, vec4(1, 0, 1, 1)));
	gObjects.push_back(new RegularPolygon(50, 300.0, vec4(1, 1, 0, 1)));
}