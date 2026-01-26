#include "Scene2.h"

using namespace glm;

void
Scene2::init()
{
	setGL(); // OpenGL settings

	// allocate memory and load resources
	// Lights
	// Textures

	// Graphics objects (entities) of the scene
	gObjects.push_back(new RGBAxes(400.0));
	gObjects.push_back(new RGBTriangle(100.0));
	gObjects.push_back(new RGBRectangle(282, 282));
	gObjects.push_back(new RegularPolygon(50, 200, vec4(1, 0, 1, 1)));
}

Scene2::~Scene2()
{
	destroy();
	resetGL();
}