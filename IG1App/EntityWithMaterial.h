#include "Entity.h"
#include "Material.h"

class EntityWithMaterial :
    public Abs_Entity
{
protected:
    Material* material;

public:
    EntityWithMaterial(Material* m);
    ~EntityWithMaterial();
    Material* getMaterial() { return material; }
};

