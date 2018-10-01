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
    l_pontos translation(float x, float y, float z);
    l_pontos scale(float x, float y, float z);
    l_pontos rotation(float A, int x, int y, int z);
    float getX(int i,int j);
    float getY(int i,int j);
    float getZ(int i,int j);
    int rayToFace(coordenada O, coordenada V);
};

#endif // OBJETO_H
