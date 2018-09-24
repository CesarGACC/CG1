#ifndef O_FACE_H
#define O_FACE_H
#include "o_ponto.h"

class o_face
{
public:
    //o_face();
    void setFace(o_ponto a, o_ponto b, o_ponto c);
    o_ponto pontos[3];

};

#endif // O_FACE_H
