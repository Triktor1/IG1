#ifndef DRONE_H
#define DRONE_H
#include "CompoundEntity.h"

class Cone;
class Disk;
class SphereWithTexture;
class Texture;
class SpotLight;

class Droid :
    public CompoundEntity
{
private:

    Cone* hat, *eye1, *eye2;
    Disk* hatDisk;
    CompoundEntity* head;
    SphereWithTexture* sphere;
    Texture* tx;
    SpotLight* droidLight = nullptr;

public:
    Droid(GLdouble radius);
    ~Droid() = default;

    void rotateSphere(GLfloat);
    SpotLight* getSpotLight() { return droidLight; }
};
#endif
