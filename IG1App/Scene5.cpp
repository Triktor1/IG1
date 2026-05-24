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
	tex2->load("../assets/images/baldosaP.png", 125);
	gTextures.push_back(tex1);
	gTextures.push_back(tex2);

	//Torus
	Torus2TextVer* torus = new Torus2TextVer(torus_R, torus_r, tex1, tex2);
	gTranslucentObjects.push_back(torus);


	GLdouble torus2_R = 190, torus2_r = 30;
	//Torus
	Torus2TextHor* torus2 = new Torus2TextHor(torus2_R, torus2_r, tex2, tex1);
	gTranslucentObjects.push_back(torus2);
}
