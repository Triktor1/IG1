#include "Scene7.h"

void
Scene7::init() {
	Scene::init();

	//Parámetros del Droid
	/*GLfloat droidRadius = 150;*/

	//Droide
	//Droid* con = new Droid(droidRadius);
	//con->getSpotLight()->setEnabled(false);
	//gOpaqueObjects.push_back(con);

	//Parametros del exprimidor
	GLfloat exWidth = 150, exHeight = 75;

	Exprimidor* expr = new Exprimidor(exWidth, exHeight, 50, 20);
	expr->setColor(glm::vec4(1.5, 1.5, 0, 1));
	gOpaqueObjects.push_back(expr);
}