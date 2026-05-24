#include "Scene7.h"
#include "IG1App.h"

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
	GLfloat exWidth = 254, exHeight = 75;

	Exprimidor* expr = new Exprimidor(exWidth, exHeight, 50, 20);
	expr->setColor(glm::vec4(1, 1, 0, 1));
	gOpaqueObjects.push_back(expr);

	//NODO
	node = new CompoundEntity();
	gOpaqueObjects.push_back(node);

	//PARA METROS DEL SNOWMAN
	GLfloat snowmanRad = 10.0f;

	snowm = new Snowman(snowmanRad);
	glm::mat4 snowMat = snowm->modelMat() * glm::translate(glm::mat4(1), glm::vec3(exWidth * 0.75, -exHeight + snowmanRad, 0));
	snowm->setModelMat(snowMat);

	node->addEntity(snowm);

	//Parametros de La hiperbolA
	//GLfloat hiWidth = 80, hiHeight = 120;

	//Hiperbole* hip = new Hiperbole(hiWidth, hiHeight, 50, 20, 2.0*std::numbers::pi);
	//hip->setColor(glm::vec4(1, 1, 0, 1));
	//gOpaqueObjects.push_back(hip);
}

void
Scene7::move() {
	GLfloat factor = 2.0f;

	glm::mat4 droidMat = node->modelMat() * glm::rotate(glm::mat4(1.0), glm::radians(factor), glm::vec3(0, -1,0));
	node->setModelMat(droidMat);
}


bool
Scene7::handleKey(unsigned char key) {
	bool need_redisplay = false;
	switch (key) {
	case 'f':
		move();
	
		IG1App::s_ig1app.camera().followCamera((node->modelMat() * snowm->modelMat()), glm::vec3(1, 0, 1), 10.0f);
		need_redisplay = true;
		break;
	case 'h':
		snowm->getSpotLight()->setEnabled(!snowm->getSpotLight()->enabled());
		need_redisplay = true;
		break;
	default:
		need_redisplay = Scene::handleKey(key);
	}
	return need_redisplay;
}