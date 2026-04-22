#include "Scene8.h"

void 
Scene8::init() {
	Scene::init();

	//Parámetros del Dathomir
	GLdouble dathomirRadius = 250, dathomirParallels = 30, dathomirMeridians = 20;

	Sphere* dathomir = new Sphere(dathomirRadius, dathomirParallels, dathomirMeridians);
	dathomir->setColor(glm::vec4(171/255.0f, 33/255.0f, 72/255.0f, 1));
	gOpaqueObjects.push_back(dathomir);
}