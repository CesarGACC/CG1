#include "o_ponto.h"
o_ponto::o_ponto(){}
o_ponto::o_ponto(int i, float x, float y, float z)
{
    id = i;
    p = coordenada(x,y,z);
}

