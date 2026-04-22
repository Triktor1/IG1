#ifndef _H_Scene8_H_
#define _H_Scene8_H_
#include "Scene.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class Scene8 :
	public Scene
{
public:
	virtual ~Scene8() = default;

	void init() override;
};
#endif

