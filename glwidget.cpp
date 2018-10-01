#include "glwidget.h"

static unsigned int   W_Npixels = 1000, H_Npixels = 1000;
static float          W = 50., H = 50.;

GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent)
{

}

void GLWidget::receberObjetos()
{
    objetos.push_back(cubo());
    objetos.push_back(cubo());
    objetos[0].lp = objetos[0].translation(-0.5,-0.5,-0.5);
    objetos[0].lp = objetos[0].scale(10,10,10);
    objetos[0].lp = objetos[0].translation(-10,0,10);

    objetos[1].lp = objetos[1].translation(-0.5,-0.5,-0.5);
    objetos[1].lp = objetos[1].rotation(45,0,0,1);
    objetos[1].lp = objetos[1].scale(5,5,5);
    objetos[1].lp = objetos[1].translation(5,-5,5);
    //objetos[0].lp = objetos[0].rotation(45,0,0,1);
    //objetos[0].lp = objetos[0].rotation(45,1,0,0);

}


void GLWidget::test()
{
    int i,j;
    float a,b,c;
    float x, y, Dx, Dy;
    coordenada v = coordenada(0,0,0,1);
    Dx = W/W_Npixels;
    Dy = H/H_Npixels;

    glBegin(GL_POINTS);
    for (int l = 0; l < H_Npixels; l++)
    {
        y = H/2 - Dy/2 - l*Dy;
        for (int c = 0; c < W_Npixels; c++)
        {
            x = -W/2 + Dx/2 + c*Dx;
            v.setX(x);
            v.setY(y);
            v.setZ(0);
            v.add(camera.p);
            v.normalizar();

            //glColor3f((rand()%255)/255., (rand()%255)/255., (rand()%255)/255.);
            //glVertex3f(x, y, 0);
            for(i=0;i<objetos.size() ;i++)
            {
                 if((objetos[i].rayToFace(camera.p,v))==1)
                 {
                     glColor3f((rand()%255)/255., (rand()%255)/255., (rand()%255)/255.);
                     glVertex3f(x, y, 0);
                 }
            }
            glColor3f(0.1, 0.1, 0.1);
            glVertex3f(x, y, 0);
        }
    }
    glEnd();
    glFlush();
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
                objetos[i].rayToFace(camera.p,camera.lookat);
                glColor3f((float)(rand()%1000)/1000,(float)(rand()%1000)/1000,(float)(rand()%1000)/1000);
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
    camera = Camera(0,0,-2, 0,0,70, 0,1,0);
    camera.calcularIJK();

    receberObjetos();

}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(camera.lookat.x,camera.lookat.y,camera.lookat.z,
              camera.p.x,camera.p.y,camera.p.z,
              camera.viewup.x,camera.viewup.y,camera.viewup.z);

    //glFrustum(-5,5,-5,5,-2,1000);

    //test(100,100);
    //desenharObjetos();
    test();
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
        glVertex3f(0,70,0);
    glEnd();

    glColor3f(1,0,0);
        glBegin(GL_LINES);
        glVertex3f(0,0,0);
        glVertex3f(70,0,0);
    glEnd();

    glColor3f(0,0,1);
        glBegin(GL_LINES);
        glVertex3f(0,0,0);
        glVertex3f(0,0,70);
    glEnd();

    glColor3f(1,1,1);
}

