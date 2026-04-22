#include "CompoundEntity.h"

class Cone;
class Disk;
class SphereWithTexture;
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

