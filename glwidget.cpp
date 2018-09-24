#include "glwidget.h"
#include "l_pontos.h"
#include "l_faces.h"

void gerarCubo(l_pontos lp, l_faces lf)
{
    lp.l.push_back(o_ponto(0,0,0,0));
    lp.l.push_back(o_ponto(1,1,0,0));
    lp.l.push_back(o_ponto(2,1,1,0));
    lp.l.push_back(o_ponto(3,0,1,0));
    lp.l.push_back(o_ponto(4,0,1,1));
    lp.l.push_back(o_ponto(5,1,0,1));
    lp.l.push_back(o_ponto(6,1,1,1));
    lp.l.push_back(o_ponto(7,0,1,1));

    lf.l.push_back(o_face(0,lp.l.at(0),lp.l.at(1),lp.l.at(2)));
    lf.l.push_back(o_face(0,lp.l.at(0),lp.l.at(1),lp.l.at(3)));

    lf.l.push_back(o_face(0,lp.l.at(3),lp.l.at(2),lp.l.at(6)));
    lf.l.push_back(o_face(0,lp.l.at(3),lp.l.at(6),lp.l.at(7)));

    lf.l.push_back(o_face(0,lp.l.at(4),lp.l.at(7),lp.l.at(5)));
    lf.l.push_back(o_face(0,lp.l.at(6),lp.l.at(5),lp.l.at(7)));

    lf.l.push_back(o_face(0,lp.l.at(1),lp.l.at(4),lp.l.at(5)));
    lf.l.push_back(o_face(0,lp.l.at(0),lp.l.at(4),lp.l.at(1)));

    lf.l.push_back(o_face(0,lp.l.at(3),lp.l.at(7),lp.l.at(4)));
    lf.l.push_back(o_face(0,lp.l.at(3),lp.l.at(4),lp.l.at(0)));

    lf.l.push_back(o_face(0,lp.l.at(5),lp.l.at(6),lp.l.at(2)));
    lf.l.push_back(o_face(0,lp.l.at(5),lp.l.at(2),lp.l.at(1)));

}

GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent)
{

}

void GLWidget::desenharCubo()
{
    l_pontos lp; l_faces lf;

        lp.l.push_back(o_ponto(0,0,0,0));
        lp.l.push_back(o_ponto(1,1,0,0));
        lp.l.push_back(o_ponto(2,1,1,0));
        lp.l.push_back(o_ponto(3,0,1,0));
        lp.l.push_back(o_ponto(4,0,1,1));
        lp.l.push_back(o_ponto(5,1,0,1));
        lp.l.push_back(o_ponto(6,1,1,1));
        lp.l.push_back(o_ponto(7,0,1,1));

        lf.l.push_back(o_face(0,lp.l.at(0),lp.l.at(1),lp.l.at(2)));
        lf.l.push_back(o_face(0,lp.l.at(0),lp.l.at(1),lp.l.at(3)));

        lf.l.push_back(o_face(0,lp.l.at(3),lp.l.at(2),lp.l.at(6)));
        lf.l.push_back(o_face(0,lp.l.at(3),lp.l.at(6),lp.l.at(7)));

        lf.l.push_back(o_face(0,lp.l.at(4),lp.l.at(7),lp.l.at(5)));
        lf.l.push_back(o_face(0,lp.l.at(6),lp.l.at(5),lp.l.at(7)));

        lf.l.push_back(o_face(0,lp.l.at(1),lp.l.at(4),lp.l.at(5)));
        lf.l.push_back(o_face(0,lp.l.at(0),lp.l.at(4),lp.l.at(1)));

        lf.l.push_back(o_face(0,lp.l.at(3),lp.l.at(7),lp.l.at(4)));
        lf.l.push_back(o_face(0,lp.l.at(3),lp.l.at(4),lp.l.at(0)));

        lf.l.push_back(o_face(0,lp.l.at(5),lp.l.at(6),lp.l.at(2)));
        lf.l.push_back(o_face(0,lp.l.at(5),lp.l.at(2),lp.l.at(1)));

    int p = 0;
    //gerarCubo(cubopontos,cubofaces);

    glColor3f(1,0,0);
        glBegin(GL_POINTS);
        for(p=0;p<8 ;p++)
        {
            printf("Imprimindo (%f,%f,%f)\n",lp.l.at(p).p.x,lp.l.at(p).p.y,lp.l.at(p).p.z);
            glVertex3f(lp.l.at(p).p.x,lp.l.at(p).p.y,lp.l.at(p).p.z);
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
