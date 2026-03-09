#include "EntityWithTexture.h"
#include "Texture.h"

class BoxOutline :
	public EntityWithTexture
{
public:
	BoxOutline(GLdouble l, Texture* tex1, Texture* tex2);
	void render(const glm::mat4& modelViewMat) const override;
private:
	Texture* mTexture;
};

