#include "glm/gtc/matrix_transform.hpp"
#include "Snowman.h"
#include "Sphere.h"
#include "Cone.h"
#include "Disk.h"

Snowman::Snowman(GLfloat radius) : radius(radius) {
	//Bola de abajo
	mDownSphere = new Sphere(radius, 30, 20);
	mDownSphere->setColor(glm::vec4(243 / 255.0, 243 / 255.0, 243 / 255.0, 1));
	addEntity(mDownSphere);

	//Bola de arriba
	mUpSphere = new Sphere(radius * 0.75, 30, 20);
	glm::mat4 mUpSphereMat = glm::translate(glm::mat4(1), glm::vec3(0, radius * 1.75, 0));
	mUpSphere->setModelMat(mUpSphereMat);
	mUpSphere->setColor(glm::vec4(243 / 255.0, 243 / 255.0, 243 / 255.0, 1));
	addEntity(mUpSphere);

	//Ojo izquierdo
	mLeftEye = new Cone(radius * 0.2, 0, radius * 0.15, 10, 10);
	glm::mat4 mLeftEyeMat = glm::translate(glm::mat4(1), glm::vec3(20, radius * 2, radius * 0.75)) * glm::rotate(glm::mat4(1), glm::radians(90.0f), glm::vec3(1, 0, 0));
	mLeftEye->setModelMat(mLeftEyeMat);
	mLeftEye->setColor(glm::vec4(0, 128 / 255.0, 128 / 255.0, 1));
	addEntity(mLeftEye);

	//Ojo derecho
	mRightEye = new Cone(radius * 0.2, 0, radius * 0.15, 10, 10);
	glm::mat4 mRightEyeMat = glm::translate(glm::mat4(1), glm::vec3(-20, radius * 2, radius * 0.75)) * glm::rotate(glm::mat4(1), glm::radians(90.0f), glm::vec3(1, 0, 0));
	mRightEye->setModelMat(mRightEyeMat);
	mRightEye->setColor(glm::vec4(0, 128 / 255.0, 128 / 255.0, 1));
	addEntity(mRightEye);

	mNose = new Cone(radius * 0.4, 0, radius * 0.1, 10, 10);
	glm::mat4 mNoseMat = glm::translate(glm::mat4(1), glm::vec3(0, radius * 1.75, radius * 0.75)) * glm::rotate(glm::mat4(1), glm::radians(90.0f), glm::vec3(1, 0, 0));
	mNose->setModelMat(mNoseMat);
	mNose->setColor(glm::vec4(1, 165 / 255.0, 0, 1));
	addEntity(mNose);

	mHat = new CompoundEntity();
	addEntity(mHat);

	mDiskUp = new Disk(radius, 0, radius * 0.1, radius * 0.3);
	glm::mat4 mDiskUpMat = glm::translate(glm::mat4(1), glm::vec3(0, radius * 2.3, 0));
	mDiskUp->setModelMat(mDiskUpMat);
	mDiskUp->setColor(glm::vec4(0, 2, 2, 1));
	mHat->addEntity(mDiskUp);

	mHatCilinder = new Cone(radius * 0.55, radius * 0.75, radius * 0.75, 10, 30);
	glm::mat4 mHatCilinderMat = glm::translate(glm::mat4(1), glm::vec3(0, radius * 2.3, 0));
	mHatCilinder->setModelMat(mHatCilinderMat);
	mHatCilinder->setColor(glm::vec4(0, 0, 2, 1));
	mHat->addEntity(mHatCilinder);

	mDiskDown = new Disk(radius*0.75, 0, 10, 30);
	glm::mat4 mDiskDownMat = glm::translate(glm::mat4(1), glm::vec3(0, radius * 2.8, 0));
	mDiskDown->setModelMat(mDiskDownMat);
	mDiskDown->setColor(glm::vec4(2, 0, 0, 1));
	mHat->addEntity(mDiskDown);
}