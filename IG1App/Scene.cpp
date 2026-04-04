#include "Scene.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace glm;

void
Scene::init()
{
	setGL(); // OpenGL settings

	// allocate memory and load resources
	// Lights
	// Textures

	// Graphics objects (entities) of the scene
	gOpaqueObjects.push_back(new RGBAxes(400.0));

}

Scene::~Scene()
{
	destroy();
	resetGL();
}

void
Scene::destroy()
{ // release memory and resources

	for (Abs_Entity* el : gOpaqueObjects)
		delete el;

	gOpaqueObjects.clear();

	for (Texture* tex : gTextures)
		delete tex;

	gTextures.clear();
}

void
Scene::load()
{
	for (Abs_Entity* obj : gOpaqueObjects)
		obj->load();
}

void
Scene::unload()
{
	for (Abs_Entity* obj : gOpaqueObjects)
		obj->unload();
}

void
Scene::setGL()
{
	// OpenGL basic setting
	glClearColor(0.6, 0.7, 0.8, 1.0); // background color (alpha=1 -> opaque)
	glEnable(GL_DEPTH_TEST);          // enable Depth test
}
void
Scene::resetGL()
{
	glClearColor(.0, .0, .0, .0); // background color (alpha=1 -> opaque)
	glDisable(GL_DEPTH_TEST);     // disable Depth test
}

void
Scene::render(Camera const& cam) const
{
	cam.upload();

	for (Abs_Entity* el : gOpaqueObjects) {
		el->render(cam.viewMat());
	}
}

void Scene::update() {
	for (Abs_Entity* el : gOpaqueObjects) {
		el->update();
	}
}
