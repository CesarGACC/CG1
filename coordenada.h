#ifndef coordenada_H
#define coordenada_H
#include <cstring>
#include <iostream>
using namespace std;
class coordenada
{
public:
    float x,y,z,w;
    float coord[4];
    coordenada();
    coordenada(float a, float b, float c);
    coordenada(float a, float b, float c, float d);

    void add(coordenada a);
    void add(coordenada a, coordenada b);
    void add(float a);
    coordenada operator + (coordenada a);

    void sub(coordenada a, coordenada b);
    void sub(coordenada a);
    void sub(float a);
    coordenada operator - (coordenada a);

    coordenada mult1x1(coordenada a, coordenada b);
    void mult(coordenada c,float a);
    void mult(float a);
    coordenada operator * (float a);

    void div(float a);

    void coordtoxyz();
    void xyztocoord();

    float magnitude();
     void normalizar();
     float distancia(coordenada a, coordenada b);

     void crossproduct(coordenada a, coordenada b);
     float dotproduct(coordenada a, coordenada b);
     coordenada projecao(coordenada a);
     float angulo(coordenada a);

     void setX(float value);
     void setY(float value);
     void setZ(float value);
     void setW(float value);

    float getX(){return x;}
    float getY(){return y;}
    float getZ(){return z;}
};

#endif // coordenada_H
