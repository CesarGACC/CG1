#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QObject>
#include <QWidget>
#include <QGLWidget>
#include <GL/glu.h>
#include <cstring>
#include <iostream>
#include <math.h>
#include "objeto.h"
#include "cubo.h"
#include "circulo.h"
#include "camera.h"
#include "luz.h"
#include "raycast.h"
class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    std::vector<Objeto> objetos;
    Camera camera;
    Luz luz;
    explicit GLWidget(QWidget *parent = nullptr);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void test();
    void desenharCubo();
    void desenhaEixo();
    void receberObjetos();
    void desenharObjetos();
    void RayCasting();


signals:

public slots:
};

#endif // GLWIDGET_H
