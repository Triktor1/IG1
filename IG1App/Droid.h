#include "CompoundEntity.h"

class Droid :
    public CompoundEntity
{
public:
    Droid(GLdouble radius);

private:
    Cone* hat, *eye1, *eye2;
    Disk* hatDisk;
    SphereWithTexture* sphere;
};

