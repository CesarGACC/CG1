#include "o_face.h"

o_face::o_face()
{

}

o_face::o_face(int i,int a, int b, int c)
{
    id = i;
    p[0] = a;
    p[1] = b;
    p[2] = c;
    this->r = (rand()%255)/255.;
    this->g = (rand()%255)/255.;
    this->b = (rand()%255)/255.;
}

void o_face::setMaterial(float r, float g, float b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}
