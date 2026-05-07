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
	DirLight* dirLight = new DirLight(0);
	dirLight->setDirection(glm::vec3(-1.0f, -1.0f, -1.0f));
	dirLight->setAmb(glm::vec3(0.25f));
	dirLight->setDiff(glm::vec3(0.6f));
	dirLight->setSpec(glm::vec3(0.0f, 0.2f, 0.0f));
	dirLight->setEnabled(true);

	gLights.push_back(dirLight);
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

	for (Abs_Entity* el : gTranslucentObjects)
		delete el;

	gTranslucentObjects.clear();

	for (Texture* tex : gTextures)
		delete tex;

	gTextures.clear();

	for (Light* light : gLights)
		delete light;

	gLights.clear();
}

void
Scene::load()
{
	for (Abs_Entity* obj : gOpaqueObjects)
		obj->load();
	for (Abs_Entity* obj : gTranslucentObjects)
		obj->load();

}

void
Scene::unload()
{
	for (Abs_Entity* obj : gOpaqueObjects)
		obj->unload();
	for (Abs_Entity* obj : gTranslucentObjects)
		obj->unload();

	for (Light* light : gLights)
		light->unload(*Shader::get("simple_light"));
}

void
Scene::setBGColor(glm::vec4 const& color) {
	glClearColor(color.r, color.g, color.b, color.a);
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

	uploadLights(cam);

	//Renderizamos antes los objetos opacos y luego los translúcidos
	for (Abs_Entity* el : gOpaqueObjects) {
		el->render(cam.viewMat());
	}
	for (Abs_Entity* el : gTranslucentObjects) {
		el->render(cam.viewMat());
	}
}

void Scene::update() {
	for (Abs_Entity* el : gOpaqueObjects) {
		el->update();
	}
}


void Scene::uploadLights(Camera const& cam) const {
	Shader* shader = Shader::get("light");
	shader->use();
	for (Light* el : gLights)
	{
		el->upload(*shader, cam.viewMat());
	}
}

bool Scene::handleKey(unsigned char key) {
	bool need_redisplay = false;
	switch (key) {
	case 'r':
		gLights[0]->setEnabled(!gLights[0]->enabled());
		need_redisplay = true;
		break;
	}
	return need_redisplay;
}
