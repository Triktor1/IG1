#include "Entity.h"
class RGBCube :
    public EntityWithColors
{
private:
    GLfloat alpha = 2.0f, alphaAct = 0.0f;
    GLint eje = 0;
public:
    RGBCube(GLdouble l);
    void update();
	void moveRGBCube(GLdouble x, GLdouble y, GLdouble z);
};
