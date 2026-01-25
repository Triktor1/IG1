#include "Scene1.h"

using namespace glm;

void
Scene1::init()
{
	setGL(); // OpenGL settings

	// allocate memory and load resources
	// Lights
	// Textures

	// Graphics objects (entities) of the scene
	gObjects.push_back(new RGBAxes(400.0));
	gObjects.push_back(new RegularPolygon(6, 300.0, vec4(1, 0, 1, 1)));
	gObjects.push_back(new RegularPolygon(50, 300.0, vec4(1, 1, 0, 1)));
}

Scene1::~Scene1()
{
	destroy();
	resetGL();
}