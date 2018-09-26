#ifndef OBJETO_H
#define OBJETO_H
#include <math.h>
#include "l_pontos.h"
#include "l_faces.h"
#define PI 3.14159265

class Objeto
{
public:
    Objeto();
    l_pontos lp;
    l_faces lf;
    void translation(float x, float y, float z);
    void scale(float x, float y, float z);
    void rotation(float A, int x, int y, int z);
};

#endif // OBJETO_H
