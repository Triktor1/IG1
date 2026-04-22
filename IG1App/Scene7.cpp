#include "Scene7.h"

void
Scene7::init() {
	Scene::init();

	//Parámetros del Droid
	GLfloat droidRadius = 150;

	Droid* con = new Droid(droidRadius);
	gOpaqueObjects.push_back(con);
}