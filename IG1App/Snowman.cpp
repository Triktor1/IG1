#include "glm/gtc/matrix_transform.hpp"
#include "Snowman.h"
#include "Sphere.h"
#include "Cone.h"
#include "Disk.h"

Snowman::Snowman(GLfloat radius) : radius(radius) {
	//Bola de abajo
	mDownSphere = new Sphere(radius, 30, 20);
	addEntity(mDownSphere);

	//Bola de arriba
	mUpSphere = new Sphere(radius * 0.75, 30, 20);
	glm::mat4 mUpSphereMat = glm::translate(glm::mat4(1), glm::vec3(0, radius * 1.25, 0));
	mUpSphere->setModelMat(mUpSphereMat);
	addEntity(mUpSphere);

	//Ojo izquierdo
	mLeftEye = new Cone(20, 0, 15, 10, 10);
	glm::mat4 mLeftEyeMat = glm::translate(glm::mat4(1), glm::vec3(30, radius * 1.25, radius * 0.75)) * glm::rotate(glm::mat4(1), glm::radians(90.0f), glm::vec3(1, 0, 0));
	mLeftEye->setModelMat(mLeftEyeMat);
	mLeftEye->setColor(glm::vec4(0, 20 / 255.0, 200 / 255.0, 1));
	addEntity(mLeftEye);

	//Ojo derecho
	mRightEye = new Cone(20, 0, 15, 10, 10);
	glm::mat4 mRightEyeMat = glm::translate(glm::mat4(1), glm::vec3(-30, radius * 1.25, radius * 0.75)) * glm::rotate(glm::mat4(1), glm::radians(90.0f), glm::vec3(1, 0, 0));
	mRightEye->setModelMat(mRightEyeMat);
	mRightEye->setColor(glm::vec4(0, 20 / 255.0, 200 / 255.0, 1));
	addEntity(mRightEye);

	mNose = new Cone(1, 1, 0, 10, 10);
	
	mDiskDown = new Disk(50, 20, 10, 10);
	
	mDiskUp = new Disk(50, 20, 10, 10);
	
	mHatCilinder = new Cone(10, 20, 20, 10, 10);
	
	mHat = new CompoundEntity();
	mHat->addEntity(mDiskUp);
	mHat->addEntity(mDiskDown);
	mHat->addEntity(mHatCilinder);
	addEntity(mNose);
	addEntity(mHat);
}