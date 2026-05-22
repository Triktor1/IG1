#include "Droid.h"

#include "SphereWithTexture.h"
#include "Cone.h"
#include "Disk.h"
#include "Light.h"

Droid::Droid(GLdouble radius) {
	// CUERPO DEL DROIDE
	tx = new Texture();
	tx->load("../assets/images/Smile.png");
	mBody = new SphereWithTexture(radius, 100, 100, tx);
	addEntity(mBody);

	//CABEZA
	mHat = new CompoundEntity();
	addEntity(mHat);
	mHat->addTexture(tx);
	//Sombrero
	mHatCone = new Cone(radius/2, radius/2, radius, radius, 25);
	glm::mat4 hatConeMat = glm::translate(glm::mat4(1), glm::vec3(0, radius, 0));
	mHatCone->setModelMat(hatConeMat);
	mHatCone->setColor(glm::vec4(1.5, 1.5, 0, 1));
	mHat->addEntity(mHatCone);

	mHatTop = new Disk(radius/2, 0, radius / 2, radius / 2);
	glm::mat4 hatTopMat = glm::translate(glm::mat4(1), glm::vec3(0, radius * 1.5f, 0));
	mHatTop->setModelMat(hatTopMat);
	mHatTop->setColor(glm::vec4(1.5, 1.5, 0, 1));
	mHat->addEntity(mHatTop);

	//EYES
	mEye1 = new Cone(radius, radius*0.15f, radius * 0.15f, 25, 25);
	glm::mat4 eye1Mat = glm::translate(glm::mat4(1), glm::vec3(radius * 0.2f, radius * 1.25f, radius * 0.65f)) *
		glm::rotate(glm::mat4(1.0), glm::radians(90.0f), glm::vec3(1, 0, 0));
	mEye1->setColor(glm::vec4(0, 204 / 255.0, 0, 1));
	mEye1->setModelMat(eye1Mat);
	addEntity(mEye1);


	mEye2 = new Cone(radius, radius * 0.15f, radius * 0.15f, 25, 25);
	glm::mat4 eye2Mat = glm::translate(glm::mat4(1), glm::vec3(-radius * 0.2f, radius * 1.25f, radius * 0.65f)) *
		glm::rotate(glm::mat4(1.0), glm::radians(90.0f), glm::vec3(1, 0, 0));
	mEye2->setColor(glm::vec4(0, 204/255.0, 0, 1));
	mEye2->setModelMat(eye2Mat);
	addEntity(mEye2);

	droidLight = new SpotLight(glm::vec3(0,0,0), 1);
	droidLight->setDirection(glm::vec3(0, -1, 0));
	droidLight->setAmb(glm::vec3(0.05f));
	droidLight->setSpec(glm::vec3(0.0f, 0.2f, 0.0f));
	droidLight->setCutoff(35.0f, 35.0f);
	droidLight->setEnabled(true);

	mHat->addLight(droidLight);
}


void Droid::rotateSphere(GLfloat factor) {
	glm::mat4 sphereRotMat = mBody->modelMat() * glm::rotate(glm::mat4(1.0), glm::radians(factor), glm::vec3(1, 0, 0));
	mBody->setModelMat(sphereRotMat);
}
