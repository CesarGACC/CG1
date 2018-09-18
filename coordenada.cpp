#include "coordenada.h"
#include <math.h>
void coordenada::setX(float value)
{
    x = value;
}

void coordenada::setY(float value)
{
    y = value;
}

void coordenada::setZ(float value)
{
    z = value;
}

void coordenada::setW(float value)
{
    w = value;
}

coordenada::coordenada()
{
    setX(0);
    setY(0);
    setZ(0);
    setW(0);
}

coordenada::coordenada(float a, float b, float c)
{
    setX(a);
    setY(b);
    setZ(c);
    setW(0);
}

coordenada::coordenada(float a, float b, float c, float d)
{
    setX(a);
    setY(b);
    setZ(c);
    setW(d);
}
void coordenada::add(coordenada a)
{
    setX(x+a.x);
    setY(y+a.y);
    setZ(z+a.z);
    setW(w+a.w);
}

void coordenada::add(float a)
{
    setX(x+a);
    setY(y+a);
    setZ(z+a);
    setW(w+a);
}

void coordenada::sub(coordenada a)
{
    setX(x-a.x);
    setY(y-a.y);
    setZ(z-a.z);
    setW(w-a.w);
}

void coordenada::sub(float a)
{
    setX(x-a);
    setY(y-a);
    setZ(z-a);
    setW(w-a);
}

void coordenada::mult(float a)
{
    setX(x*a);
    setY(y*a);
    setZ(z*a);
    setW(w*a);
}

void coordenada::div(float a)
{
    setX(x/a);
    setY(y/a);
    setZ(z/a);
    setW(w/a);
}

float coordenada::magnitude()
{
    return sqrt(x*x+y*y+z*z);
}

void coordenada::normalizar()
{
    float m = magnitude();
    x = x/m;
    y = y/m;
    z = z/m;
}

float coordenada::distancia(coordenada a, coordenada b)
{
    return sqrt((b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y) + (b.z-a.z)*(b.z-a.z));
}

void coordenada::pvetorial(coordenada a, coordenada b)
{
    x = a.y*b.z - a.z*b.y;
    y = a.z*b.x - a.x*b.z;
    z = a.x*b.y - a.y*b.x;
}

coordenada coordenada::projecao(coordenada a)
{
    float a1;
    a1 = this->magnitude()*this->angulo(a);
    coordenada a2;
    a2 = coordenada(x,y,z);
    a2.sub(a1);
    return a2;
}

float coordenada::angulo(coordenada a)
{
    //Cos do angulo
    return (x*a.x+y*a.y+z*a.z)/((this->magnitude())*(a.magnitude()));
}
