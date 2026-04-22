#include "Scene7.h"

void
Scene7::init() {
	Scene::init();
	//
	//Sphere* sph = new Sphere(200, 20, 7);
	//sph->setColor(glm::vec4(0, 1, 0, 1));
	//gOpaqueObjects.push_back(sph);
	//
	//Disk* dsk = new Disk(100, 250, 8, 25);
	//dsk->setColor(glm::vec4(0, 1, 0, 1));
	//gOpaqueObjects.push_back(dsk);

	//Cone* con = new Cone(50, 20, 80, 25, 25);
	//con->setColor(glm::vec4(0, 1, 0, 1));
	//gOpaqueObjects.push_back(con);


	//ESFERA CON TEXTURA
	//Texture* texBox2 = new Texture();
	//texBox2->load("../assets/images/container.jpg", 255);
	//gTextures.push_back(texBox2);

	//SphereWithTexture* sphTx = new SphereWithTexture(200, 20, 12, texBox2);
	//gOpaqueObjects.push_back(sphTx);

	Droid* con = new Droid(50);
	gOpaqueObjects.push_back(con);
}