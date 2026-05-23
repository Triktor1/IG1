#include "Scene5.h"

using namespace glm;

void
Scene5::init()
{
	Scene::init();

	//Parámetros del Torus
	GLdouble torus_R = 80, torus_r = 40;
	Texture* tex1 = new Texture();
	tex1->load("../assets/images/baldosaC.png", 255);
	Texture* tex2 = new Texture();
	tex2->load("../assets/images/baldosaP.png", 255);
	gTextures.push_back(tex1);
	gTextures.push_back(tex2);

	//Torus
	Torus2TextHor* torus = new Torus2TextHor(torus_R, torus_r, tex1, tex2);
	gOpaqueObjects.push_back(torus);
}
