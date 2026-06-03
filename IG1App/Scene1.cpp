#include "Scene1.h"
#include "Corolla.h"

using namespace glm;

void
Scene1::init()
{
	Scene::init();

	float corW = 100.0, corH = 100.0;
	Corolla* cor = new Corolla(corW, corH, 100, 100);

	gOpaqueObjects.push_back(cor);

}