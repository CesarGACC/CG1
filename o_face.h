#ifndef O_FACE_H
#define O_FACE_H
#include "o_ponto.h"

class o_face
{
public:
    int id;
    o_face();
    o_face(int i,int a, int b, int c);
    int p[3];

};

#endif // O_FACE_H
