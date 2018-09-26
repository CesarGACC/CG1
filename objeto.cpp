#include "objeto.h"

Objeto::Objeto()
{

}

void Objeto::translation(float x, float y, float z)
{
    int i=0;
    for(i=0;i<lp.l.size();i++)
    {

        lp.l[i].p.setX(lp.l[i].p.getX()+x);
        lp.l[i].p.setY(lp.l[i].p.getY()+y);
        lp.l[i].p.setZ(lp.l[i].p.getZ()+z);
    }
}

void Objeto::scale(float x, float y, float z)
{
    int i=0;
    for(i=0;i<lp.l.size();i++)
    {
        lp.l[i].p.setX(lp.l[i].p.getX()*x);
        lp.l[i].p.setY(lp.l[i].p.getY()*y);
        lp.l[i].p.setZ(lp.l[i].p.getZ()*z);
    }
}

void Objeto::rotation(float A,int x,int y,int z)
{
    float cosseno, seno;
    int i=0;
    cosseno = cos(A*PI/180);
    seno = sin(A*PI/180);

    for(i=0;i<lp.l.size();i++)
    {
        if((x==1) && (y==0) && (z == 0))//X rotation
        {
            lp.l[i].p.setY(lp.l[i].p.getY()*cosseno - lp.l[i].p.getZ()*seno);
            lp.l[i].p.setZ(lp.l[i].p.getY()*seno    + lp.l[i].p.getZ()*cosseno);
        }

        if((x==0) && (y==1) && (z == 0))//Y rotation
        {
            lp.l[i].p.setX(lp.l[i].p.getX()*cosseno + lp.l[i].p.getZ()*seno);
            lp.l[i].p.setZ(-lp.l[i].p.getX()*seno   + lp.l[i].p.getZ()*cosseno);
        }

        if((x==0) && (y==0) && (z == 1))//Z rotation
        {

            lp.l[i].p.setX(lp.l[i].p.getX()*cosseno - lp.l[i].p.getY()*seno);
            lp.l[i].p.setY(lp.l[i].p.getX()*seno    + lp.l[i].p.getY()*cosseno);
        }
    }
}

