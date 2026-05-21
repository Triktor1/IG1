#include "Entity.h"
#include "Material.h"

class EntityWithMaterial :
    public Abs_Entity
{
protected:
    Material material;
    static bool mShowNormals;
public:
    EntityWithMaterial();
    ~EntityWithMaterial();
    void render(const glm::mat4& modelViewMat) const override;
    Material& getMaterial() { return material; }
	void setMaterial(const Material& m) { material = m; }
    }
};

