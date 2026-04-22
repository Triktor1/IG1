#include "Droid.h"
#include "SphereWithTexture.h"
#include "Cone.h"
#include "Disk.h"
#include "Texture.h"

Droid::Droid(GLdouble radius) {
	//SOMBRERO
	hat = new Cone(radius / 2, radius / 2, radius, 10, 30);
	glm::mat4 hatCilinderMat = glm::translate(glm::mat4(1), glm::vec3(0, radius, 0));
	hat->setModelMat(hatCilinderMat);
	hat->setColor(glm::vec4(1, 1, 0, 1));
	addEntity(hat);

	//DISCO
	hatDisk = new Disk(radius * 0.55f, 0, 10, 30);
	glm::mat4 diskCilinderMat = glm::translate(glm::mat4(1), glm::vec3(0, radius * 1.45f, 0));
	hatDisk->setModelMat(diskCilinderMat);
	hatDisk->setColor(glm::vec4(2, 2, 0, 1));
	addEntity(hatDisk);

	//ESFERA
	tx = new Texture();
	tx->load("../assets/images/container.jpg", 255);
	sphere = new SphereWithTexture(radius, 20, 20, tx);
	addEntity(sphere);

	//OJOS
	eye1 = new Cone(radius / 2, radius / 10, radius / 10, 10, 10);
	glm::mat4 eye1CilinderMat = glm::translate(glm::mat4(1.0), glm::vec3(radius / 10, radius * 1.25, radius / 1.5)) *
		glm::rotate(glm::mat4(1.0), glm::radians(90.0f), glm::vec3(1, 0, 0));
	eye1->setModelMat(eye1CilinderMat);
	eye1->setColor(glm::vec4(0, 0.8, 0, 1));
	addEntity(eye1);

	eye2 = new Cone(radius / 2, radius / 10, radius / 10, 10, 10);
	glm::mat4 eye2CilinderMat = glm::translate(glm::mat4(1.0), glm::vec3(-radius / 10, radius * 1.25, radius / 1.5)) *
		glm::rotate(glm::mat4(1.0), glm::radians(90.0f), glm::vec3(1, 0, 0));
	eye2->setModelMat(eye2CilinderMat);
	eye2->setColor(glm::vec4(0, 0.8, 0, 1));
	addEntity(eye2);
}

Droid::~Droid() {
	delete(tx);
}

void Droid:: rotateSphere(GLfloat factor) {
	glm::mat4 rotMat = glm::rotate(sphere->modelMat(), glm::radians(factor), glm::vec3(1, 0, 0));
	sphere->setModelMat(rotMat);
}