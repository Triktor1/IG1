#include "Scene8.h"

void 
Scene8::init() {
	Scene::init();

	//Parámetros del Dathomir
	GLdouble dathomirRadius = 250, dathomirParallels = 30, dathomirMeridians = 20;

	Sphere* dathomir = new Sphere(dathomirRadius, dathomirParallels, dathomirMeridians);
	dathomir->setColor(glm::vec4(171/255.0f, 33/255.0f, 72/255.0f, 1));
	gOpaqueObjects.push_back(dathomir);

	//Nodo fantasma
	node = new CompoundEntity();
	gOpaqueObjects.push_back(node);

	//Parámetros del Droid
	GLdouble droidRadius = 20.0f;
	
	//Droide
	droid = new Droid(droidRadius);

	//Ponemos droide encima del dathomir (1/2 radio del dathomir + 1/2 radio del droide (bola + cabeza))
	glm::mat4 droidMat = droid->modelMat() * glm::translate(glm::mat4(1), glm::vec3(0, dathomirRadius + droidRadius * 0.75,0));
	droid->setModelMat(droidMat);
	node->addEntity(droid);

	//Luz
	posLight = new PosLight(0);
	posLight->setPosition(glm::vec3(0, dathomirRadius+50, 0));
	posLight->setEnabled(true);
	gLights.push_back(posLight);

	spotLight = new SpotLight(glm::vec3(0, 0, dathomirRadius+50), 0);
	spotLight->setEnabled(true);
	gLights.push_back(spotLight);

}

void
Scene8::rotate() {
	node->setModelMat(glm::rotate(node->modelMat(), glm::radians(5.0f), { 0.0,1.0,0.0 }));
}

void
Scene8::orbit() {
	GLfloat factor = 2.0f;

	//Rotación de la esfera del droide por separado del resto de objetos
	droid->rotateSphere(factor * 10);
	glm::mat4 nodeMat = glm::rotate(node->modelMat(), glm::radians(factor), glm::vec3(1, 0, 0));
	node->setModelMat(nodeMat);
}

bool
Scene8::handleKey(unsigned char key) {
	bool need_redisplay = false;
	switch (key) {
	case 'f':
		orbit();
		need_redisplay = true;
		break;
	case 'g':
		rotate();
		need_redisplay = true;
		break;
	case 't':
		posLight->setEnabled(!posLight->enabled());
		break;
	case 'y':
		spotLight->setEnabled(!spotLight->enabled());
		break;
	default:
		need_redisplay = Scene::handleKey(key);
	}
	return need_redisplay;
}