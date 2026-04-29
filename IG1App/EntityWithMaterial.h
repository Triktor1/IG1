#include "Entity.h"
#include "Material.h"

class EntityWithMaterial :
    public Abs_Entity
{
protected:
    Material* material;

public:
    EntityWithMaterial();
    ~EntityWithMaterial();
    void render(const glm::mat4& modelViewMat) const override;
    Material* getMaterial() { return material; }
};

