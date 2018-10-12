#include "o_face.h"

o_face::o_face()
{

}

o_face::o_face(int i,int a, int b, int c)
{
    id = i;
    p[0] = a;
    p[1] = b;
    p[2] = c;
    corAMB = Cor(0.1,0.1,0.1);
    corDIF = Cor(0.8,0.8,0.8);
    corESP = Cor(0.2,0.2,0.2);
}

void o_face::setMaterial(float r, float g, float b)
{
    //corAMB = Cor(0.1,0.1,0.1);
    //corDIF = Cor(0.8,0.8,0.8);
    //corESP = Cor(0.2,0.2,0.2);
}
