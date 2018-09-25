#ifndef CIRCULO_H
#define CIRCULO_H
#include "objeto.h"
class circulo : public Objeto
{
public:
    coordenada centro;
    float raio;
    circulo();
};

#endif // CIRCULO_H
