#ifndef _H_Scene7_H_
#define _H_Scene7_H_
#include "Scene.h"
class Scene7 :
	public Scene
{
public:
	virtual ~Scene7() = default;

	void init() override;

	bool handleKey(unsigned char key) override;
	void move();

private:
	Snowman* snowm;
	CompoundEntity* node = nullptr;
};
#endif