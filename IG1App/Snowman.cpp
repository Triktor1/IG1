#include "Snowman.h"

#include "Sphere.h"
#include "Cone.h"
#include "Disk.h"
#include "Light.h"

Snowman::Snowman(GLdouble radius) {
	//HAT
	hat = new CompoundEntity();
	addEntity(hat);

	//CUERPO
	downSphere = new Sphere(radius, 20, 20);
	addEntity(downSphere);

	upSphere = new Sphere(radius * 0.75f, 20, 20);
	glm::mat4 upSphereMat = glm::translate(glm::mat4(1), glm::vec3(0, radius * 1.75f, 0));
	upSphere->setModelMat(upSphereMat);
	addEntity(upSphere);

	//OJOS

	eye1 = new Cone(radius * 0.25f, 0, radius*0.15f, 10,10);
	glm::mat4 eye1Mat = glm::translate(glm::mat4(1), glm::vec3(radius * 0.2f, radius * 2.0f, radius*0.65f)) * 
		glm::rotate(glm::mat4(1.0), glm::radians(90.0f), glm::vec3(1, 0, 0));
	eye1->setColor(glm::vec4(0, 0.5, 0.5, 1));
	eye1->setModelMat(eye1Mat);
	addEntity(eye1);

	eye2 = new Cone(radius * 0.25f, 0, radius * 0.15f, 10, 10);
	glm::mat4 eye2Mat = glm::translate(glm::mat4(1), glm::vec3(-radius * 0.2f, radius * 2.0f, radius * 0.65f)) *
		glm::rotate(glm::mat4(1.0), glm::radians(90.0f), glm::vec3(1, 0, 0));
	eye2->setColor(glm::vec4(0, 0.5, 0.5, 1));
	eye2->setModelMat(eye2Mat);
	addEntity(eye2);

	nose = new Cone(radius * 0.35f, 0, radius * 0.08f, 10, 10);
	glm::mat4 noseMat = glm::translate(glm::mat4(1), glm::vec3(0, radius * 1.7f, radius * 0.65f)) *
		glm::rotate(glm::mat4(1.0), glm::radians(90.0f), glm::vec3(1, 0, 0));
	nose->setModelMat(noseMat);
	nose->setColor(glm::vec4(0.8, 0.5, 0, 1));
	addEntity(nose);

	// SOMBRERO
	hatDown = new Disk(radius, 0, 10, 30);
	glm::mat4 downDiskMat = glm::translate(glm::mat4(1), glm::vec3(0, radius * 2.5f, 0));
	hatDown->setModelMat(downDiskMat);
	hatDown->setColor(glm::vec4(0, 2, 2, 1));
	hat->addEntity(hatDown);

	hatCyl = new Cone(radius * 0.4f, radius * 0.75f, radius * 0.75f, 10, 10);
	glm::mat4 hatCylMat = glm::translate(glm::mat4(1), glm::vec3(0, radius * 2.5f, 0));
	hatCyl->setModelMat(hatCylMat);
	hatCyl->setColor(glm::vec4(0, 0, 1, 1));
	hat->addEntity(hatCyl);
	
	hatUp = new Disk(radius*0.75f, 0, 10, 30);
	glm::mat4 upDiskMat = glm::translate(glm::mat4(1), glm::vec3(0, radius * 2.85f, 0));
	hatUp->setModelMat(upDiskMat);
	hatUp->setColor(glm::vec4(2, 0, 0, 1));
	hat->addEntity(hatUp);

	snowLight = new SpotLight(glm::vec3(0, 0, 0), 1);
	snowLight->setDirection(glm::vec3(0, 0, 1));
	snowLight->setAmb(glm::vec3(0.05f));
	snowLight->setSpec(glm::vec3(0.0f, 0.2f, 0.0f));
	snowLight->setCutoff(35.0f, 35.0f);
	snowLight->setEnabled(true);

	hat->addLight(snowLight);
}