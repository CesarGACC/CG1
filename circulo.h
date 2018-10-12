#ifndef CIRCULO_H
#define CIRCULO_H
#include "objeto.h"
class circulo : public Objeto
{
public:
    coordenada centro;
    float raio;
    Cor cor;
    circulo();
    circulo(float raio, coordenada centro);
};

#endif // CIRCULO_H
