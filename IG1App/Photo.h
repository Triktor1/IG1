#ifndef _H_Photo_H_
#define _H_Photo_H_
#include "EntityWithTexture.h"
#include "Texture.h"

class Photo :
    public EntityWithTexture
{
private:
public:
    Photo(GLdouble, GLdouble, Texture*);
    void update() override;
};
#endif