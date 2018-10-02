#include "luz.h"

Luz::Luz()
{

}

Luz::Luz(float r, float g, float b, float x, float y, float z)
{
    cor = Cor(r,g,b);
    p = coordenada(x,y,z);
}
