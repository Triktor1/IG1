#ifndef DRONE_H
#define DRONE_H
#include "CompoundEntity.h"

class Cone;
class Disk;
class SphereWithTexture;
class Texture;

class Droid :
    public CompoundEntity
{
private:
    Cone* hat, *eye1, *eye2;
    Disk* hatDisk;
    SphereWithTexture* sphere;
    Texture* tx;
public:
    Droid(GLdouble radius);
    ~Droid();

    void rotateSphere(GLfloat);
};
#endif
