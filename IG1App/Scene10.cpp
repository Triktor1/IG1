#include "Scene10.h"
#include "IG1App.h"
#include <iostream>

void
Scene10::init() {
	Scene::init();

	//Planeaa amarillo
	//Sphere* yellowPlanet = new Sphere(50, 20, 20);
	//yellowPlanet->setColor(glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));
	//yellowPlanet->setModelMat(glm::translate(glm::mat4(1.0f), glm::vec3(150, 0, 0)));

	//gOpaqueObjects.push_back(yellowPlanet);

	//paltnea dorado
	//Sphere* goldPlanet = new Sphere(50, 20, 20);
	//goldPlanet->setColor(glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));
	//goldPlanet->setModelMat(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 150)));
	//goldPlanet->getMaterial().setGold();

	//gOpaqueObjects.push_back(goldPlanet);


	node = new CompoundEntity();
	gOpaqueObjects.push_back(node);
	
	Disk* raceTrack = new Disk(200, 100, 20, 20);
	raceTrack->setColor(glm::vec4(200 / 255.0, 200 / 255.0, 200 / 255.0, 1));
	gOpaqueObjects.push_back(raceTrack);

	droid = new Droid(20);
	droid->setModelMat(glm::translate(droid->modelMat(), glm::vec3(150, 20, 0)));
	node->addEntity(droid);
}

void Scene10::rotate(float degrees) {
	node->setModelMat(glm::rotate(node->modelMat(), glm::radians(degrees), glm::vec3(0, -1, 0)));
}

bool Scene10::handleKey(unsigned char key) {
	bool need_redisplay = false;
	switch (key) {
	case 'f':
		follow = !follow;
		break;
	case 'q':
		rotate(5.0f);
		if (follow) {
			IG1App::s_ig1app.camera().followCamera(node->modelMat() * droid->modelMat(), glm::vec3(0, 1, -0.01f), 300);
		}
		need_redisplay = true;
		break;
	default:
		need_redisplay = Scene::handleKey(key);
	}
	return need_redisplay;
}