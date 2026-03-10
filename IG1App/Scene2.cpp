#include "Scene2.h"

using namespace glm;

void
Scene2::init()
{
	//Variables del RegularPolygon
	GLdouble num = 50, r = 200.0;
	glm::vec4 color = vec4(1, 0, 1, 1);

	//Variables del RGBTriangle
	GLdouble trX = r, trY = 0, trZ = 0.0, trR = 100.0;

	//Variables del RGBRectangle
	GLdouble length = sqrt(2*r*r);

	Scene::init();

	RGBTriangle* triangle = new RGBTriangle(trR);
	triangle->moveRGBTriangle(trX, trY, trZ);
	gObjects.push_back(triangle);

	gObjects.push_back(new RGBRectangle(length, length));
	gObjects.push_back(new RegularPolygon(num, r, color));

	Texture* texGlass = new Texture();
	texGlass->load("../assets/images/windowC.png", 255);
	gTextures.push_back(texGlass);
	gObjects.push_back(new GlassParapet(200, texGlass));
}