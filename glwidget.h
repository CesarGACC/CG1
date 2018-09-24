#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QObject>
#include <QWidget>
#include <QGLWidget>
#include <GL/glu.h>
#include <cstring>
#include <iostream>
#include <math.h>
class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = nullptr);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void desenharCubo();
    void desenhaEixo();

signals:

public slots:
};

#endif // GLWIDGET_H
