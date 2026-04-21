#include "Entity.h"
class CompoundEntity :
    public Abs_Entity
{
public:
    void addEntity(Abs_Entity* ae);
    CompoundEntity() = default;
    ~CompoundEntity();

    void render(const glm::mat4& modelViewMat) const override;

    void update() override;
    void load() override;
    void unload() override;
protected:
    std::vector<Abs_Entity*> gObjects;
};

