#include "Scene2.h"


#include "CorollaWithGradient.h"

using namespace glm;

void
Scene2::init()
{
	Scene::init();

	float corW = 100.0, corH = 100.0;
	CorollaWithGradient* cor = new CorollaWithGradient(corW, corH, 100, 100);

	gOpaqueObjects.push_back(cor);
}