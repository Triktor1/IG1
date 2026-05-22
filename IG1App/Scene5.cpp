#include "Scene5.h"

using namespace glm;

void
Scene5::init()
{
	Scene::init();

	//Parámetros del Torus
	GLdouble torus_R = 80, torus_r = 40;

	//Torus
	Texture* tex1 = new Texture(), * tex2 = new Texture();
	gTextures.push_back(tex1);
	gTextures.push_back(tex2);
	tex1->load("../assets/images/Zelda.bmp");
	tex2->load("../assets/images/spamton.png");
	TorusTwoTextureHor* torusHor = new TorusTwoTextureHor(tex1, tex2, torus_R, torus_r);
	gOpaqueObjects.push_back(torusHor);
	TorusTwoTextureVer* torusVer = new TorusTwoTextureVer(tex1, tex2, torus_R*2, torus_r);
	gOpaqueObjects.push_back(torusVer);
	//Cone* cone = new Cone(100, torus_r, torus_R, 20, 4, std::numbers::pi * 2);
	//cone->setColor(vec4(0, 1, 0, 1));
	//gOpaqueObjects.push_back(cone);
}
