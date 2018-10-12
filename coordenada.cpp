#include "coordenada.h"
#include <math.h>

void coordenada::setX(float value)
{
    x = value;
    //xyztocoord();
}

void coordenada::setY(float value)
{
    y = value;
    //xyztocoord();
}

void coordenada::setZ(float value)
{
    z = value;
    //xyztocoord();
}

void coordenada::setW(float value)
{
    w = value;
    //xyztocoord();
}

void coordenada::coordtoxyz()
{
    setX(coord[0]);
    setY(coord[1]);
    setZ(coord[2]);
    setW(coord[3]);
}

void coordenada::xyztocoord()
{
    coord[0] = x;
    coord[1] = y;
    coord[2] = z;
    coord[3] = w;
}

coordenada::coordenada()
{
    setX(0);
    setY(0);
    setZ(0);
    setW(0);
    //xyztocoord();
}

coordenada::coordenada(float a, float b, float c)
{
    setX(a);
    setY(b);
    setZ(c);
    setW(0);
    //xyztocoord();
}

coordenada::coordenada(float a, float b, float c, float d)
{
    setX(a);
    setY(b);
    setZ(c);
    setW(d);
    //xyztocoord();
}

coordenada coordenada::operator+(coordenada a)
{
    coordenada v = coordenada();
    v.x = x + a.x;
    v.y = y + a.y;
    v.z = z + a.z;
    v.w = w + a.w;
    //v.xyztocoord();
    return v;
}
coordenada coordenada::operator-(coordenada a)
{
    coordenada v = coordenada();
    v.x = x - a.x;
    v.y = y - a.y;
    v.z = z - a.z;
    v.w = w - a.w;
    //v.xyztocoord();
    return v;
}

coordenada coordenada::operator * (float a)
{
    coordenada v = coordenada();
    v.x = x * a;
    v.y = y * a;
    v.z = z * a;
    //v.xyztocoord();
    return v;
}

coordenada coordenada::mult1x1(coordenada a, coordenada b)
{
    coordenada v = coordenada();
    v.x = a.x * b.x ;
    v.y = a.y * b.x ;
    v.z = a.z * b.x ;
    //v.xyztocoord();
    return v;
}

void coordenada::add(coordenada a, coordenada b)
{
    setX(b.x+a.x);
    setY(b.y+a.y);
    setZ(b.z+a.z);
    setW(b.w+a.w);
    //xyztocoord();
}

void coordenada::add(coordenada a)
{
    setX(x+a.x);
    setY(y+a.y);
    setZ(z+a.z);
    setW(w+a.w);
    //xyztocoord();
}

void coordenada::add(float a)
{
    setX(x+a);
    setY(y+a);
    setZ(z+a);
    setW(w+a);
    //xyztocoord();
}



void coordenada::sub(coordenada a, coordenada b)
{
    setX(a.x-b.x);
    setY(a.y-b.y);
    setZ(a.z-b.z);
    setW(a.w-b.w);
    //xyztocoord();
}

void coordenada::sub(coordenada a)
{
    setX(x-a.x);
    setY(y-a.y);
    setZ(z-a.z);
    setW(w-a.w);
    //xyztocoord();
}

void coordenada::sub(float a)
{
    setX(x-a);
    setY(y-a);
    setZ(z-a);
    setW(w-a);
    //xyztocoord();
}

void coordenada::mult(float a)
{
    setX(x*a);
    setY(y*a);
    setZ(z*a);
    setW(w*a);
    //xyztocoord();
}

void coordenada::mult(coordenada c,float a)
{
    setX(a*c.x);
    setY(a*c.y);
    setZ(a*c.z);
    setW(a*c.w);
    //xyztocoord();
}

void coordenada::div(float a)
{
    setX(x/a);
    setY(y/a);
    setZ(z/a);
    setW(w/a);
    //xyztocoord();
}

float coordenada::magnitude()
{
    return fabs(sqrt(x*x+y*y+z*z));
}

void coordenada::normalizar()
{
    float m = magnitude();
    if(m>0)
    {
        x = x/m;
        y = y/m;
        z = z/m;
        //xyztocoord();
    }

}

float coordenada::distancia(coordenada a, coordenada b)
{
    return sqrt((b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y) + (b.z-a.z)*(b.z-a.z));
}

float coordenada::dotproduct(coordenada a, coordenada b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

/*void coordenada::crossproduct(coordenada a, coordenada b) //Cross product
{
    x = a.y*b.z - a.z*b.y;
    y = a.z*b.x - a.x*b.z;
    z = a.x*b.y - a.y*b.x;
    //xyztocoord();
}*/

coordenada coordenada::crossproduct(coordenada a, coordenada b) //Cross product
{
    coordenada v = coordenada();
    v.x = a.y*b.z - a.z*b.y ;
    v.y = a.z*b.x - a.x*b.z ;
    v.z = a.x*b.y - a.y*b.x ;
    //v.xyztocoord();
    return v;
}

coordenada coordenada::projecao(coordenada a)
{
    float a1;
    a1 = magnitude()*angulo(a);
    coordenada a2;
    a2 = coordenada(x,y,z);
    a2.sub(a1);
    return a2;
}

float coordenada::angulo(coordenada a)
{
    //Cos do angulo
    return (x*a.x+y*a.y+z*a.z)/((magnitude())*(a.magnitude()));
}
