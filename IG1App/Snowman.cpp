#include "glm/gtc/matrix_transform.hpp"
#include "Snowman.h"
#include "Sphere.h"
#include "Cone.h"
#include "Disk.h"

Snowman::Snowman(GLfloat radius) {
	//Esfera abajo
	mDownSphere = new Sphere(radius, 20, 20);
	mDownSphere->setColor(glm::vec4(243 / 255.0, 243 / 255.0, 243 / 255.0, 1));
	addEntity(mDownSphere);
	//Esfera arriba
	mUpSphere = new Sphere(radius * 0.75, 20, 20);
	mUpSphere->setColor(glm::vec4(243 / 255.0, 243 / 255.0, 243 / 255.0, 1));
	glm::mat4 upSphereModelMat = glm::translate(glm::mat4(1), glm::vec3(0, radius * 1.75, 0));
	mUpSphere->setModelMat(upSphereModelMat);
	addEntity(mUpSphere);

	//Nariz
	mNose = new Cone(radius * 0.3, 0, radius * 0.1, 20, 20);
	mNose->setColor(glm::vec4(1, 0.5, 0, 1));
	glm::mat4 noseModelMat = glm::translate(glm::mat4(1), glm::vec3(0, radius * 1.75, radius * 0.75)) *
		glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	mNose->setModelMat(noseModelMat);
	addEntity(mNose);

	//Ojo izquierdo
	mLeftEye = new Cone(radius * 0.25, 0, radius * 0.15, 20, 20);
	mLeftEye->setColor(glm::vec4(0, 0.5, 0.5, 1));
	glm::mat4 leftEyeModelMat = glm::translate(glm::mat4(1), glm::vec3(radius*0.2, radius * 2, radius*0.75)) *
		glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	mLeftEye->setModelMat(leftEyeModelMat);
	addEntity(mLeftEye);
	//Ojo derecho
	mRightEye = new Cone(radius * 0.25, 0, radius * 0.15, 20, 20);
	mRightEye->setColor(glm::vec4(0, 0.5, 0.5, 1));
	glm::mat4 rightEyeModelMat = glm::translate(glm::mat4(1), glm::vec3(-radius * 0.2, radius * 2, radius * 0.75)) *
		glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	mRightEye->setModelMat(rightEyeModelMat);
	addEntity(mRightEye);

	//Sombrero
	mHat = new CompoundEntity();
	addEntity(mHat);
	
	mDiskDown = new Disk(radius, 0, 20, 20);
	mDiskDown->setColor(glm::vec4(0, 1, 1, 1));
	glm::mat4 diskDownModelMat = glm::translate(glm::mat4(1), glm::vec3(0, radius*2.5, 0));
	mDiskDown->setModelMat(diskDownModelMat);
	mHat->addEntity(mDiskDown);
	
	mHatCilinder = new Cone(radius * 0.4, radius * 0.8, radius * 0.8, 20, 20);
	mHatCilinder->setColor(glm::vec4(0, 0, 1, 1));
	glm::mat4 hatCilinderModelMat = glm::translate(glm::mat4(1), glm::vec3(0, radius*2.51, 0));
	mHatCilinder->setModelMat(hatCilinderModelMat);
	mHat->addEntity(mHatCilinder);
	
	mDiskUp = new Disk(radius*0.8, 0, 20, 20);
	mDiskUp->setColor(glm::vec4(1, 0, 0, 1));
	glm::mat4 diskUpModelMat = glm::translate(glm::mat4(1), glm::vec3(0, radius * 2.9, 0));
	mDiskUp->setModelMat(diskUpModelMat);
	mHat->addEntity(mDiskUp);
}