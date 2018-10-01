#ifndef LUZ_H
#define LUZ_H
#include "coordenada.h"

class Luz
{
public:
    Luz();
    Luz(float r, float g, float b, float x, float y, float z);
    float r,g,b;
    coordenada p;

};

#endif // LUZ_H
