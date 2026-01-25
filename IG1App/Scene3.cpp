#include "Scene3.h"

using namespace glm;

void
Scene3::init()
{
	setGL(); // OpenGL settings

	// allocate memory and load resources
	// Lights
	// Textures

	// Graphics objects (entities) of the scene
	gObjects.push_back(new RGBRectangle(250,125));
}

Scene3::~Scene3()
{
	destroy();
	resetGL();
}