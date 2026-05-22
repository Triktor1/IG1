#ifndef SNOWMAN_H
#define SNOWMAN_H
#include "CompoundEntity.h"

class Sphere;
class Cone;
class Disk;

class Snowman : public CompoundEntity {
private:

    Sphere* downSphere, * upSphere;
    Cone* nose, * eye1, * eye2;

    CompoundEntity* hat;
    Disk* hatDown, * hatUp;
    Cone* hatCyl;

public:
    Snowman(GLdouble radius);
    ~Snowman() = default;

};
#endif