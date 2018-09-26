#ifndef TRANSFORM_H
#define TRANSFORM_H
#include <cstring>
#include <iostream>
#include <math.h>
#include "l_pontos.h"
#include "objeto.h"
#define PI 3.14159265

class Transform
{
public:
    Transform();
    void translation(Objeto o, float x, float y, float z);
    void scale(Objeto o, float x, float y, float z);
    void rotation(Objeto o, float A, int x, int y, int z);
};

#endif // TRANSFORM_H
