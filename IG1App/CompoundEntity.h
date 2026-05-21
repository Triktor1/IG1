#ifndef COMPOUNDENTITY_H
#define COMPOUNDENTITY_H

#include "Entity.h"
#include "Texture.h"

class Light;
class CompoundEntity :
	public Abs_Entity
{
public:
	CompoundEntity() = default;
	~CompoundEntity();

	void render(const glm::mat4& modelViewMat) const override;

	void update() override;
	void load() override;
	void unload() override;

	void addEntity(Abs_Entity* ae);
	void addTexture(Texture* tex) { gTextures.push_back(tex); };
	void addLight(Light* light) { gLights.push_back(light); }

	virtual void uploadLights(glm::mat4& modelViewMat) const;
	virtual void unloadLights() const;

protected:
	std::vector<Abs_Entity*> gObjects;
	std::vector<Texture*> gTextures;
	std::vector<Light*> gLights;
};
#endif
