#include "Scene7.h"

void
Scene7::init() {
	Scene::init();

	//Parámetros del Droid
	GLfloat droidRadius = 150;

	//Droide
	Droid* con = new Droid(droidRadius);
	con->getSpotLight()->setEnabled(false);
	gOpaqueObjects.push_back(con);
}