#include "Droid.h"
#include "SphereWithTexture.h"
#include "Cone.h"
#include "Disk.h"
#include "Texture.h"
#include "Light.h"

Droid::Droid(GLdouble radius) {
	
}

void Droid:: rotateSphere(GLfloat factor) {
	glm::mat4 rotMat = glm::rotate(sphere->modelMat(), glm::radians(factor), glm::vec3(1, 0, 0));
	sphere->setModelMat(rotMat);
}