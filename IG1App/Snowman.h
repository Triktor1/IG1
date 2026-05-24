#ifndef SNOWMAN_H
#define SNOWMAN_H
#include "CompoundEntity.h"

class Sphere;
class Cone;
class Disk;
class SpotLight;

class Snowman : public CompoundEntity {
private:

    Sphere* downSphere, * upSphere;
    Cone* nose, * eye1, * eye2;

    CompoundEntity* hat;
    Disk* hatDown, * hatUp;
    Cone* hatCyl;

    SpotLight* snowLight = nullptr;
public:
    Snowman(GLdouble radius);
    ~Snowman() = default;

    SpotLight* getSpotLight() { return snowLight; };
};
#endif