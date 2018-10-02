#ifndef OBJETO_H
#define OBJETO_H
#include <math.h>
#include <stdlib.h>
#include <vector>
#include "cor.h"
#include "luz.h"
#include "o_ponto.h"
#include "o_face.h"
#include "coordenada.h"

#define PI 3.14159265

class Objeto
{
public:
    Objeto();

    std::vector<o_face> lf;
    std::vector<o_ponto> lp;

    Cor corAMB, corDIF, corESP;
    Cor corAparente;
    vector<o_ponto> translation(float x, float y, float z);
    vector<o_ponto> scale(float x, float y, float z);
    vector<o_ponto> rotation(float A, int x, int y, int z);
    float getX(int i,int j);
    float getY(int i,int j);
    float getZ(int i,int j);
    Cor calcularCor(coordenada O, coordenada V, coordenada pint, Luz l);
    int rayToObject(coordenada O, coordenada V);
    //int rayToFace(coordenada O, coordenada V, int F);

};

#endif // OBJETO_H
