#ifndef RAYCAST_H
#define RAYCAST_H
#include "objeto.h"
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <float.h>
#include "cor.h"
#include "luz.h"
#include "o_ponto.h"
#include "o_face.h"
#include "coordenada.h"
class RayCast
{
public:
    RayCast();
    Cor rayToObjects(coordenada origem, coordenada direcao, std::vector<Objeto> objetos);
    Cor calcularCor(coordenada V, coordenada pint, coordenada normal, Luz luz, o_face f);

    Cor rayToMaths(coordenada origem, coordenada direcao, std::vector<Objeto> objetos);
};

#endif // RAYCAST_H
