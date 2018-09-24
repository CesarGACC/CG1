#include "glwidget.h"
#include "l_pontos.h"
#include "l_faces.h"
#include "cubo.h"


GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent)
{

}

void GLWidget::desenharCubo()
{
    int i;
    cubo c = cubo();/*
    glColor3f(1,0,0);
        glBegin(GL_POINTS);
        for(p=0;p<8 ;p++)
        {
            printf("Imprimindo (%f,%f,%f)\n",c.lp.l.at(p).p.x,c.lp.l.at(p).p.y,c.lp.l.at(p).p.z);
            glVertex3f(c.lp.l.at(p).p.x,c.lp.l.at(p).p.y,c.lp.l.at(p).p.z);
        }
    glEnd();
    glColor3f(1,1,1);*/

    glColor3f(1,0,0);
        glBegin(GL_TRIANGLES);
        for(i=0;i<12 ;i++)
        {
            glVertex3f(c.lf.l.at(i).p[0].p.x,c.lf.l.at(i).p[0].p.y,c.lf.l.at(i).p[0].p.z);
            glVertex3f(c.lf.l.at(i).p[1].p.x,c.lf.l.at(i).p[1].p.y,c.lf.l.at(i).p[1].p.z);
            glVertex3f(c.lf.l.at(i).p[2].p.x,c.lf.l.at(i).p[2].p.y,c.lf.l.at(i).p[2].p.z);
        }
    glEnd();
    glColor3f(1,1,1);
}

void GLWidget::initializeGL()
{
    glClearColor(0.2,0.2,0.2,1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,0,70, 0,0,0, 0,1,0);

    desenharCubo();
    //desenhaEixo();
}
void GLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,(float)w/h, 0.01, 100);
    updateGL();
}

void GLWidget::desenhaEixo()
{
    glColor3f(0,1,0);
        glBegin(GL_LINES);
        glVertex3f(0,0,0);
        glVertex3f(0,1,0);
    glEnd();

    glColor3f(1,0,0);
        glBegin(GL_LINES);
        glVertex3f(0,0,0);
        glVertex3f(1,0,0);
    glEnd();

    glColor3f(1,1,1);
}
