#ifndef _H_Scene_H_
#define _H_Scene_H_

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "Camera.h"
#include "Image.h"
#include "Entity.h"
#include "RegularPolygon.h"
#include "RGBTriangle.h"
#include "RGBRectangle.h"
#include "Cube.h"
#include "RGBCube.h"
#include "Ground.h"
#include "BoxOutline.h"
#include "Box.h"
#include "Star3D.h"
#include "GlassParapet.h"
#include "Photo.h"
#include "Grass.h"
#include "Torus.h"
#include "IndexedBox.h"
#include "Sphere.h"
#include "Disk.h"
#include "Cone.h"
#include "SphereWithTexture.h"
#include "Snowman.h"
#include "Droid.h"

#include <vector>

class Scene
{
public:
	Scene() = default;
	virtual ~Scene();

	Scene(const Scene& s) = delete;            // no copy constructor
	Scene& operator=(const Scene& s) = delete; // no copy assignment

	virtual void init();

	void render(Camera const& cam) const;

	// load or unload scene data into the GPU
	void load();
	void unload();
	void setBGColor(glm::vec4 const& color = glm::vec4(0.6, 0.7, 0.8, 1.0));

	virtual void update();

	virtual void rotate() {};
	virtual void orbit() {};
protected:
	void destroy();

	void setGL();
	void resetGL();

	std::vector<Abs_Entity*> gOpaqueObjects; // Entities (graphic objects) of the scene
	std::vector<Abs_Entity*> gTranslucentObjects; // Entities (graphic objects) of the scene
	std::vector<Texture*> gTextures; // Textures of the scene
};

#endif //_H_Scene_H_
