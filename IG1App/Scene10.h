#ifndef _H_Scene10_H_
#define _H_Scene10_H_
#include "Scene.h"
class Scene10 :
	public Scene
{
public:
	virtual ~Scene10() = default;

	void init() override;
	bool handleKey(unsigned char key) override;
	void rotate(float degrees);
private:
	Droid* droid;
	CompoundEntity* node;
	bool follow = false;
};
#endif