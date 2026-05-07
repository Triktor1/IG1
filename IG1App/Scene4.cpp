#include "Scene4.h"

using namespace glm;

void
Scene4::init()
{
	Scene::init();
	//Variables del suelo

	// GROUND
	GLdouble groundL = 400.0;
	Texture* tex = new Texture();
	tex->load("../assets/images/baldosaC.png", 255);
	gTextures.push_back(tex);

	Ground* ground = new Ground(groundL, groundL, 4, 4, tex);
	gOpaqueObjects.push_back(ground);
	//Rotado 90º para que esté paralelo al plano XZ
	ground->setModelMat(glm::rotate(ground->modelMat(), glm::radians(90.0f), glm::vec3(1, 0, 0)));

	// BOX
	//Variables de la caja
	GLfloat boxPosX = 140.0f, boxPosY = 25.1f, boxPosZ = 0.0f;
	GLuint boxL = 50;
	Texture* texBox1 = new Texture();
	Texture* texBox2 = new Texture();
	texBox1->load("../assets/images/papelE.png", 255);
	texBox2->load("../assets/images/container.jpg", 255);
	gTextures.push_back(texBox1);
	gTextures.push_back(texBox2);

	Box* box = new Box(boxL, texBox1, texBox2);
	gOpaqueObjects.push_back(box);
	//Movimiento de la caja para ponerla en la posición correcta
	box->setModelMat(glm::translate(box->modelMat(), glm::vec3(boxPosX, boxPosY, boxPosZ)));

	// STAR
	//Variables de la estrella
	GLfloat starPosX = 140.0f, starPosY = 25.1f, starPosZ = 0.0f;
	GLuint starRe = 17, starNp = 8, starH = 17;
	Texture* texS = new Texture();
	texS->load("../assets/images/rueda.png", 255);
	gTextures.push_back(texS);

	Star3D* star = new Star3D(starRe, starNp, starH, texS);
	gOpaqueObjects.push_back(star);
	//Movimiento de la estrella para ponerla en la posición correcta
	star->setModelMat(glm::translate(star->modelMat(), glm::vec3(starPosX, starPosY, starPosZ)));

	// PHOTO
	//Variables de la foto
	GLuint photoL = 100;
	Texture* empty = new Texture();
	gTextures.push_back(empty);
	
	Photo* photo = new Photo(photoL, photoL, empty);
	gOpaqueObjects.push_back(photo);
	//Rotación para estar paralelo al suelo y subida para evitar el z-fighting con el suelo
	photo->setModelMat(glm::rotate(photo->modelMat(), glm::radians(90.0f), glm::vec3(1, 0, 0)) *
		glm::translate(photo->modelMat(), glm::vec3(0.0f, 0.0f, -0.1f)));

	// GLASSPARAPET
	//Variables del glass parapet
	GLuint glassL = 400;
	GLfloat glassScaleXZ = 1.0f, glassScaleY = 0.3f;

	Texture* texGlass = new Texture();
	texGlass->load("../assets/images/windowC.png", 155);
	gTextures.push_back(texGlass);
	GlassParapet* glass = new GlassParapet(glassL, texGlass);
	gTranslucentObjects.push_back(glass);
	//Escala para que abarque todo el suelo
	glass->setModelMat(glm::scale(glm::mat4(1.0f), glm::vec3(glassScaleXZ, glassScaleY, glassScaleXZ)));

	// GRASS
	GLuint grassWH = 65;
	GLfloat grassPosX = 95.0f, grassPosY = grassWH/2, grassPosZ = 80.0f;
	Texture* texGrass = new Texture();
	texGrass->load("../assets/images/grass.png", 255);
	gTextures.push_back(texGrass);

	Grass* grass = new Grass(grassWH, grassWH, texGrass);
	gOpaqueObjects.push_back(grass);
	//Movimiento de la estrella para ponerla en la posición correcta
	grass->setModelMat(glm::translate(grass->modelMat(), glm::vec3(grassPosX, grassPosY, grassPosZ)));
}
