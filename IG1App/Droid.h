#ifndef DRONE_H
#define DRONE_H
#include "CompoundEntity.h"

class SphereWithTexture;
class Cone;
class Disk;
class Texture;
class SpotLight;

class Droid : public CompoundEntity {
private:
    Texture* tx;
    SphereWithTexture* mBody;

    CompoundEntity* mHat;
    Cone* mEye1, * mEye2;
    Cone* mHatCone;
    Disk* mHatTop;
    
    SpotLight* droidLight = nullptr;
public:
    Droid(GLdouble radius);
    ~Droid() = default;

    void rotateSphere(GLfloat);
    SpotLight* getSpotLight() { return droidLight; }
};
#endif