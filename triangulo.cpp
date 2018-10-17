#include "triangulo.h"

Triangulo::Triangulo()
{
    lp.push_back(o_ponto(0,0,0,0));
    lp.push_back(o_ponto(1,1,0,0));
    lp.push_back(o_ponto(2,1,1,0));

    lf.push_back(o_face(0,0,1,2));
}
