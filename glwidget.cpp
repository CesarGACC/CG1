#include "glwidget.h"

static unsigned int   W_Npixels = 1000, H_Npixels = 1000;
static float          W = 50., H = 50.;

GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent)
{

}

void GLWidget::receberObjetos()
{
    /*objetos.push_back(Triangulo());
    objetos.push_back(Triangulo());
    objetos[0].lp = objetos[0].scale(10,10,0);
    objetos[0].lp = objetos[0].translation(5,0,10);

    objetos[1].lp = objetos[1].scale(10,10,0);
    objetos[1].lp = objetos[1].translation(-5,0,10);*/

    objetos.push_back(Pot());
    objetos[0].lp = objetos[0].scale(10,10,10);

    /*objetos.push_back(Cubo());
    //objetos.push_back(Cubo());
    objetos[0].lp = objetos[0].translation(-0.5,-0.5,0.5);
    objetos[0].lp = objetos[0].scale(5,5,5);
    objetos[0].lp = objetos[0].translation(0,0,-10);

    objetos[1].lp = objetos[1].translation(-0.5,-0.5,-0.5);
    objetos[1].lp = objetos[1].scale(5,5,5);
    objetos[1].lp = objetos[1].translation(0,7.5,5);*/


}

void calcularLuz()
{

}

void GLWidget::RayCasting()
{
    RayCast ray = RayCast();
    Cor cor = Cor();
    float x, y, Dx, Dy;

    Dx = W/W_Npixels;
    Dy = H/H_Npixels;

    glBegin(GL_POINTS);
    for (int l = 0; l < H_Npixels; l++)
    {
        y = H/2 - Dy/2 - l*Dy;
        for (int c = 0; c < W_Npixels; c++)
        {
            x = -W/2 + Dx/2 + c*Dx;
            coordenada p = camera.p - camera.pcK + camera.pcI*x + camera.pcJ*y;
            coordenada vdir;
            vdir = camera.p - p;
            vdir.normalizar();
            cor = ray.rayToObjects(camera.p, vdir, objetos);
            //cor = ray.rayToMaths(camera.p, vdir, objetos);
            glColor3f(cor.r, cor.g, cor.b);
            glVertex3f(x, y, 0);
        }
    }
    glEnd();
    glFlush();
}

void GLWidget::test()
{
    glColor3f(1,1,1);
    //glBegin(GL_POINTS);
    for(int i=0;i<objetos.size();i++)
    {

        for(int j=0;j<(int)objetos[i].lf.size();j++)
        {

           //glVertex3f(objetos[0].lp[j].p.getX(),objetos[0].lp[j].p.getY(),objetos[0].lp[j].p.getZ());
            glBegin(GL_LINES);
                glVertex3f(objetos[i].getX(j,0),objetos[i].getY(j,0),objetos[i].getZ(j,0));
                glVertex3f(objetos[i].getX(j,1),objetos[i].getY(j,1),objetos[i].getZ(j,1));
            glEnd();

            glBegin(GL_LINES);
                glVertex3f(objetos[i].getX(j,1),objetos[i].getY(j,1),objetos[i].getZ(j,1));
                glVertex3f(objetos[i].getX(j,2),objetos[i].getY(j,2),objetos[i].getZ(j,2));
            glEnd();

            glBegin(GL_LINES);
                glVertex3f(objetos[i].getX(j,2),objetos[i].getY(j,2),objetos[i].getZ(j,2));
                glVertex3f(objetos[i].getX(j,0),objetos[i].getY(j,0),objetos[i].getZ(j,0));
            glEnd();


        }

    }
    //glEnd();

}

void GLWidget::desenharObjetos()
{
    int i,j;

    //glColor3f(1,0,0);
        //glBegin(GL_TRIANGLES);
        for(i=0;i<(int)objetos.size() ;i++)
        {
            for(j=0;j<(int)objetos[i].lf.size();j++)
            {
                //objetos[i].rayToObject(camera.p,camera.lookat);
                //glColor3f((float)(rand()%1000)/1000,(float)(rand()%1000)/1000,(float)(rand()%1000)/1000);
                glColor3f(1,1,1);
                    glBegin(GL_TRIANGLES);
                    glVertex3f(objetos[i].getX(j,0),objetos[i].getY(j,0),objetos[i].getZ(j,0));
                    glVertex3f(objetos[i].getX(j,1),objetos[i].getY(j,1),objetos[i].getZ(j,1));
                    glVertex3f(objetos[i].getX(j,2),objetos[i].getY(j,2),objetos[i].getZ(j,2));
                glEnd();
            }
        }
    //glEnd();
    glColor3f(1,1,1);
}

void GLWidget::desenharCubo()
{
    int i;
    glColor3f(1,0,0);
        glBegin(GL_POINTS);
        for(int j=0;j<(int)objetos[0].lf.size();j++)
        {
            for(int p=0;p<3 ;p++)
            {
                if(objetos[0].lf[j].id < 2)
                {
                    glColor3f(1,1,1);
                    glVertex3f(objetos[0].getX(j,p),objetos[0].getY(j,p),objetos[0].getZ(j,p));
                }else
                {
                    glColor3f(1,0,0);
                    glVertex3f(objetos[0].getX(j,p),objetos[0].getY(j,p),objetos[0].getZ(j,p));
                }
            }
        }
    glEnd();
}

void GLWidget::initializeGL()
{
    glClearColor(0.0,0.0,0.0,1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
        GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
        GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
        GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
        GLfloat light_position[] = {0,10,0, 0.0 };
        glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_LIGHT0);

    glEnable(GL_COLOR_MATERIAL);


    /*luz = Luz(1.0,1.0,1.0, 0,10,-2);
    camera = Camera(0,0,-2, 0,0,1, 0,1,0);
    camera.calcularIJK();
*/
    receberObjetos();

}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,0,70, 0,0,-2, 0,1,0);

    /*glPushMatrix();
        GLUquadric *quad = gluNewQuadric();
        glTranslatef(0,12.5,0);
        gluSphere(gluNewQuadric(),5,1000,1000);
    glPopMatrix();
    glPushMatrix();
        gluSphere(gluNewQuadric(),10,1000,1000);
    glPopMatrix();*/
    //glFrustum(-5,5,-5,5,-2,1000);

    //desenharCubo();
    //desenharObjetos();
    test();
    //RayCasting();

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
