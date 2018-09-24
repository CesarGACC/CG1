#include "o_face.h"

o_face::o_face()
{

}

o_face::o_face(int i,o_ponto a, o_ponto b, o_ponto c)
{
    id = i;
    p[0] = a;
    p[1] = b;
    p[2] = c;
}
