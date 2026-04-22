#include "Scene8.h"

void 
Scene8::init() {
	Scene::init();

	//Parámetros del Dathomir
	GLdouble dathomirRadius = 250, dathomirParallels = 30, dathomirMeridians = 20;

	Sphere* dathomir = new Sphere(dathomirRadius, dathomirParallels, dathomirMeridians);
	dathomir->setColor(glm::vec4(171/255.0f, 33/255.0f, 72/255.0f, 1));
	gOpaqueObjects.push_back(dathomir);

	node = new CompoundEntity();
	gOpaqueObjects.push_back(node);

	GLdouble droidRadius = 20.0f;
	droid = new Droid(droidRadius);

	glm::mat4 droidMat = droid->modelMat() * glm::translate(glm::mat4(1), glm::vec3(0, dathomirRadius + droidRadius * 0.75,0));
	droid->setModelMat(droidMat);
	node->addEntity(droid);
}

void
Scene8::rotate() {
	node->setModelMat(glm::rotate(node->modelMat(), glm::radians(5.0f), { 0.0,1.0,0.0 }));
}

void
Scene8::orbit() {
	GLfloat factor = 2.0f;
	droid->rotateSphere(factor * 10);
	glm::mat4 nodeMat = glm::rotate(node->modelMat(), glm::radians(factor), glm::vec3(1, 0, 0));
	node->setModelMat(nodeMat);
}