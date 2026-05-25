#include "Scene5.h"

using namespace glm;

void
Scene5::init()
{
	Scene::init();

	//Parámetros del Torus
	GLdouble torus_R = 80, torus_r = 40;

	//Torus
	/*Hiperboloide* hat = new Hiperboloide(100, 20, 20, 100);
	hat->setColor(glm::vec4(0, 1, 0, 1));
	gOpaqueObjects.push_back(hat);*/
	//Texture* tex1 = new Texture(), * tex2 = new Texture(), * tex3 = new Texture(), * tex4 = new Texture();
	//gTextures.push_back(tex1);
	//gTextures.push_back(tex2);
	//gTextures.push_back(tex3);
	//gTextures.push_back(tex4);
	//tex1->load("../assets/images/Zelda.bmp", 255);
	//tex2->load("../assets/images/container.jpg", 128);
	//tex3->load("../assets/images/papelE.png", 255);
	//tex4->load("../assets/images/baldosaF.png", 128);
	//TorusTwoTextureHor* torusHor = new TorusTwoTextureHor(tex3, tex4, torus_R, torus_r);
	//gTranslucentObjects.push_back(torusHor);
	//TorusTwoTextureVer* torusVer = new TorusTwoTextureVer(tex1, tex2, torus_R*4, torus_r);
	//gOpaqueObjects.push_back(torusVer);
	//Cone* cone = new Cone(100, torus_r, torus_R, 20, 4, std::numbers::pi * 2);
	//cone->setColor(vec4(0, 1, 0, 1));
	//gOpaqueObjects.push_back(cone);

	//Corolla* corolla = new Corolla(100, 100, 40, 40);
	//corolla->setColor(glm::vec4(1, 1, 0, 0));
	//gOpaqueObjects.push_back(corolla);

	CorollaWithGradient* corolla2 = new CorollaWithGradient(100, 100, 40, 40, glm::vec4(249 / 255.0f, 57 / 255.0f, 35 / 255.0f, 1), glm::vec4(0, 0, 1, 1));
	gOpaqueObjects.push_back(corolla2);
}
