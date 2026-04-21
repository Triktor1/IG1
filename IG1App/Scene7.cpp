#include "Scene7.h"

void
Scene7::init() {
	Scene::init();

	/*
	Sphere* sph = new Sphere(200, 20, 7);
	sph->setColor(glm::vec4(0, 1, 0, 1));
	gOpaqueObjects.push_back(sph);
	*/

	
	Disk* dsk = new Disk(100, 250, 8, 25);
	dsk->setColor(glm::vec4(0, 1, 0, 1));
	gOpaqueObjects.push_back(dsk);

	Cone* con = new Cone(50, 40, 8, 25, 25);
	con->setColor(glm::vec4(0, 1, 0, 1));
	gOpaqueObjects.push_back(con);
	
}