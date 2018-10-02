#ifndef LUZ_H
#define LUZ_H
#include "coordenada.h"
#include "Cor.h"
class Luz
{
public:
    Luz();
    Luz(float r, float g, float b, float x, float y, float z);
    Cor cor;
    coordenada p;

};

#endif // LUZ_H
