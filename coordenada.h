#ifndef coordenada_H
#define coordenada_H


class coordenada
{
public:
    float x,y,z,w;
    coordenada();
    coordenada(float a, float b, float c);
    coordenada(float a, float b, float c, float d);
    void add(coordenada a);
    void add(float a);
    void sub(coordenada a);
    void sub(float a);
    void mult(float a);
    void div(float a);

    float magnitude();
    void normalizar();
    float distancia(coordenada a, coordenada b);

    void pvetorial(coordenada a, coordenada b);
    coordenada projecao(coordenada a);
    float angulo(coordenada a);

    void setX(float value);
    void setY(float value);
    void setZ(float value);
    void setW(float value);
};

#endif // coordenada_H
