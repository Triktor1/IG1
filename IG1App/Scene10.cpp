#include "Scene10.h"

void
Scene10::init() {
	Scene::init();

    //Planeaa amarillo
    Sphere* yellowPlanet = new Sphere(50, 20, 20);
    yellowPlanet->setColor(glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));
    yellowPlanet->setModelMat(glm::translate(glm::mat4(1.0f), glm::vec3(150, 0, 0)));

    gOpaqueObjects.push_back(yellowPlanet);

    //paltnea dorado
    Sphere* goldPlanet = new Sphere(50, 20, 20);
    goldPlanet->setModelMat(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 150)));
    goldPlanet->getMaterial()->setGold();

    gOpaqueObjects.push_back(goldPlanet);
}