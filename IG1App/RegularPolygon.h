#ifndef REGULARPOLYGON_H_
#define REGULARPOLYGON_H_
#include "SingleColorEntity.h"
class RegularPolygon :
    public SingleColorEntity
{
public:
    RegularPolygon(GLuint num, GLdouble r, glm::vec4 color);
private:

};
#endif