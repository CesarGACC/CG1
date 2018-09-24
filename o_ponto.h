#ifndef O_PONTO_H
#define O_PONTO_H
#include "coordenada.h"

class o_ponto
{
public:
    int id;
    coordenada p;
    o_ponto();
    o_ponto(int i, float x, float y, float z);
};

#endif // O_PONTO_H
