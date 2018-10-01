#ifndef O_FACE_H
#define O_FACE_H
#include "o_ponto.h"
#include <math.h>
#include <stdlib.h>
class o_face
{
public:
    int id;
    float r,g,b;
    o_face();
    o_face(int i,int a, int b, int c);
    int p[3];
    void setMaterial(float r, float g, float b);
};

#endif // O_FACE_H
