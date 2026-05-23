#include "Droid.h"
#include "SphereWithTexture.h"
#include "Cone.h"
#include "Disk.h"
#include "Texture.h"
#include "Light.h"

Droid::Droid(GLdouble radius) {
	//ESFERA
	tx = new Texture();
	tx->load("../assets/images/container.jpg");
	addTexture(tx);
	sphere = new SphereWithTexture(radius, 20, 20, tx);
	addEntity(sphere);

	//CABEZA
	hat = new Cone(radius * 0.5f, radius * 0.5f, radius, 20, 20);
	hat->setColor(glm::vec4(1, 1, 0, 1));
	glm::mat4 headModelMat = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, radius * 1, 0.0f));
	hat->setModelMat(headModelMat);
	addEntity(hat);

	//DISCO CABEZA
	hatDisk = new Disk(radius * 0.55, 0, 20, 20);
	hatDisk->setColor(glm::vec4(1, 1, 0, 1));
	glm::mat4 headDiskModelMat = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, radius * 1.48f, 0.0f)) * 
		glm::rotate(glm::mat4(1.0f), glm::radians(180.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	hatDisk->setModelMat(headDiskModelMat);
	addEntity(hatDisk);

	//OJOS
	eye1 = new Cone(radius*0.4, radius*0.1, radius*0.1, 20, 20);
	eye1->setColor(glm::vec4(0, 204 / 255.0f, 0, 1));
	glm::mat4 eye1ModelMat = glm::translate(glm::mat4(1), glm::vec3(radius*0.25, radius*1.25, radius)) * 
		glm::rotate(glm::mat4(1.0f), glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	eye1->setModelMat(eye1ModelMat);
	addEntity(eye1);

	eye2 = new Cone(radius*0.4, radius*0.1, radius*0.1, 20, 20);
	eye2->setColor(glm::vec4(0, 204 / 255.0f, 0, 1));
	glm::mat4 eye2ModelMat = glm::translate(glm::mat4(1), glm::vec3(-radius * 0.25, radius * 1.25, radius)) *
		glm::rotate(glm::mat4(1.0f), glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	eye2->setModelMat(eye2ModelMat);
	addEntity(eye2);

	droidLight = new SpotLight(glm::vec3(0, 0, 0), 1);
	droidLight->setDirection(glm::vec3(0, -1, 0));
	droidLight->setAmb(glm::vec3(0.5f));
	droidLight->setSpec(glm::vec3(0.0f, 0.2f, 0.0f));
	droidLight->setCutoff(35.0f, 35.0f);
	addLight(droidLight);

}

void Droid::rotateSphere(GLfloat factor) {
	glm::mat4 rotMat = glm::rotate(sphere->modelMat(), glm::radians(factor), glm::vec3(1, 0, 0));
	sphere->setModelMat(rotMat);
}