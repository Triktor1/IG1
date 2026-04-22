#ifndef SNOWMAN_H
#define SNOWMAN_H
#include "CompoundEntity.h"
class Sphere;
class Cone;
class Disk;

class Snowman :
    public CompoundEntity
{
private:
    Sphere* mDownSphere, *mUpSphere;
    Cone* mLeftEye, *mRightEye, *mNose, *mHatCilinder;
    Disk* mDiskUp, *mDiskDown;
    CompoundEntity* mHat;
public:
    Snowman(GLfloat radius);
};
#endif