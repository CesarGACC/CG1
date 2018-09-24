#include "o_face.h"

o_face::o_face()
{

}

o_face::o_face(int i,o_ponto a, o_ponto b, o_ponto c)
{
    id = i;
    pontos[0] = a;
    pontos[1] = b;
    pontos[2] = c;
}
