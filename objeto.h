#ifndef OBJETO_H
#define OBJETO_H
#include <math.h>
#include <stdlib.h>
#include "l_pontos.h"
#include "l_faces.h"
#define PI 3.14159265

class Objeto
{
public:
    Objeto();
    //l_pontos lp;
    //l_faces lf;

    std::vector<o_face> lf;
    std::vector<o_ponto> lp;
    float r,g,b;
    vector<o_ponto> translation(float x, float y, float z);
    vector<o_ponto> scale(float x, float y, float z);
    vector<o_ponto> rotation(float A, int x, int y, int z);
    float getX(int i,int j);
    float getY(int i,int j);
    float getZ(int i,int j);
    int rayToObject(coordenada O, coordenada V);
    void setMaterial(float r, float g, float b);
};

#endif // OBJETO_H
