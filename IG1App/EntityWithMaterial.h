#include "Entity.h"
#include "Material.h"
#include <iostream>
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

    static void toggleNormals() { mShowNormals = !mShowNormals; std::cout << "fuck" << std::endl;
    }
};

