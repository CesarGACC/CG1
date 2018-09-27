#include "glwidget.h"


GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent)
{

}

void GLWidget::receberObjetos()
{
    Transform T;
    objetos.push_back(cubo());
    printf("Translacao (%f,%f,%f)\n",objetos[0].lp.l[0].p.getX(),objetos[0].lp.l[0].p.getY(),objetos[0].lp.l[0].p.getZ());
    //objetos[0].lp = objetos[0].translation(-0.5,-0.5,-0.5);
    objetos[0].lp = objetos[0].scale(10,10,10);
    objetos[0].lp = objetos[0].translation(0,0,10);
    //objetos[0].lp = objetos[0].rotation(0,0,0,1);
    //objetos[0].lp = objetos[0].rotation(45,1,0,0);


    printf("Translacao (%f,%f,%f)\n",objetos[0].lp.l[0].p.getX(),objetos[0].lp.l[0].p.getY(),objetos[0].lp.l[0].p.getZ());
}

void GLWidget::test(int w, int h)
{
    float i,j;
    float a,b,c;

    for(i=-w/2;i<w/2;i=i+0.125)
    {
        for(j=-h/2;j<h/2;j=j+0.125)
        {
            a = (float)(rand()%1000)/1000;
            b = (float)(rand()%1000)/1000;
            c = (float)(rand()%1000)/1000;
            glColor3f(a,b,c);
            //printf("cores %f %f %f\n",a,b,c);
            glBegin(GL_POINTS);
            glVertex3f(i,j,0);
            glEnd();
        }
    }
    printf("cores %f %f %f\n",a,b,c);
}

void GLWidget::desenharObjetos()
{
    int i,j;

    //glColor3f(1,0,0);
        //glBegin(GL_TRIANGLES);
        for(i=0;i<objetos.size() ;i++)
        {
            for(j=0;j<objetos[i].lf.l.size();j++)
            {
                glColor3f(j/12,j/12,j/12);
                    glBegin(GL_TRIANGLES);
                    glVertex3f(objetos[i].getX(j,0),objetos[i].getY(j,0),objetos[i].getZ(j,0));
                    glVertex3f(objetos[i].getX(j,1),objetos[i].getY(j,1),objetos[i].getZ(j,1));
                    glVertex3f(objetos[i].getX(j,2),objetos[i].getY(j,2),objetos[i].getZ(j,2));
                glEnd();
              /*
                printf("(%f,%f,%f)\n",objetos[i].lf.l.at(j).p[0]->p.getX(),objetos[i].lf.l.at(j).p[0]->p.getY(),objetos[i].lf.l.at(j).p[0]->p.getZ());
                printf("(%f,%f,%f)\n",objetos[i].lf.l.at(j).p[1]->p.getX(),objetos[i].lf.l.at(j).p[1]->p.getY(),objetos[i].lf.l.at(j).p[0]->p.getZ());
                printf("(%f,%f,%f)\n",objetos[i].lf.l.at(j).p[2]->p.getX(),objetos[i].lf.l.at(j).p[2]->p.getY(),objetos[i].lf.l.at(j).p[0]->p.getZ());
            */}
        }
    //glEnd();
    glColor3f(1,1,1);
}

void GLWidget::desenharCubo()
{
    int i;
    cubo c = cubo();/*
    glColor3f(1,0,0);
        glBegin(GL_POINTS);
        for(p=0;p<8 ;p++)
        {
            printf("Imprimindo (%f,%f,%f)\n",c.lp.l.at(p).p.getX(),c.lp.l.at(p).p.getY(),c.lp.l.at(p).p.getZ());
            glVertex3f(c.lp.l.at(p).p.getX(),c.lp.l.at(p).p.getY(),c.lp.l.at(p).p.getZ());
        }
    glEnd();
    glColor3f(1,1,1);*/

    glColor3f(1,0,0);
        glBegin(GL_TRIANGLES);
        for(i=0;i<12 ;i++)
        {/*
            glVertex3f(c.lf.l.at(i).p[0]->p.getX(),c.lf.l.at(i).p[0]->p.getY(),c.lf.l.at(i).p[0]->p.getZ());
            glVertex3f(c.lf.l.at(i).p[1]->p.getX(),c.lf.l.at(i).p[1]->p.getY(),c.lf.l.at(i).p[1]->p.getZ());
            glVertex3f(c.lf.l.at(i).p[2]->p.getX(),c.lf.l.at(i).p[2]->p.getY(),c.lf.l.at(i).p[2]->p.getZ());
        */}
    glEnd();
    glColor3f(1,1,1);
}

void GLWidget::initializeGL()
{
    glClearColor(0.0,0.0,0.0,1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    camera = Camera(0,0,0 ,0,0,70, 0,1,0);
    camera.calcularIJK();

    receberObjetos();
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,0,70, 0,0,0, 0,1,0);

    //glFrustum(-5,5,-5,5,-2,1000);

    test(100,100);
    //desenharObjetos();

    desenhaEixo();
}

void GLWidget::resizeGL(int w, int h)
{
    if(h == 0)
        h = 1;
    float ratio = 1.0* w / h;
    glViewport(0,0,w,h);
    gluPerspective(45,ratio,1,1000);
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

    glColor3f(0,0,1);
        glBegin(GL_LINES);
        glVertex3f(0,0,0);
        glVertex3f(0,0,1);
    glEnd();

    glColor3f(1,1,1);
}

