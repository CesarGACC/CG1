#include "camera.h"

Camera::Camera()
{

}

Camera::Camera(int a,int b,int c,int d,int e,int f,int g,int h,int i)
{
    p = coordenada(a,b,c);
    lookat = coordenada(d,e,f);
    viewup = coordenada(g,h,i);
}

Camera::Camera(coordenada newp, coordenada newlookat, coordenada newviewup){}

void Camera::calcularIJK()
{
    pcK.sub(lookat,p);
    pcK.normalizar();

    pcI.crossproduct(viewup,pcK);
    pcI.normalizar();

    pcJ.crossproduct(pcK,pcI);
    pcJ.normalizar();

    printf("Pci = (%f,%f,%f)\n",pcI.x,pcI.y,pcI.z);
    printf("Pcj = (%f,%f,%f)\n",pcJ.x,pcJ.y,pcJ.z);
    printf("Pck = (%f,%f,%f)\n",pcK.x,pcK.y,pcK.z);

}
