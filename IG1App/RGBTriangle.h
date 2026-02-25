#include "Entity.h"
class RGBTriangle :
    public EntityWithColors
{
private:
    GLdouble r = 100;
    GLfloat alpha = 5.0f;
public:
    RGBTriangle(GLdouble);

    void update() override;
    void moveRGBTriangle(GLdouble x, GLdouble y, GLdouble z);
};  