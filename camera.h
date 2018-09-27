#ifndef CAMERA_H
#define CAMERA_H

#include "coordenada.h"

class Camera
{
public:
    Camera();
    Camera(int ,int ,int ,int ,int ,int ,int ,int ,int );
    Camera(coordenada newp, coordenada newlookat, coordenada newviewup);
    //Basicos
    coordenada p;
    coordenada lookat;
    coordenada viewup;

    //Coordenadas da camera
    coordenada pcI;
    coordenada pcJ;
    coordenada pcK;

    void calcularIJK();

};

#endif // CAMERA_H
