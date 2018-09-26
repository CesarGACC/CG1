#include "transform.h"

Transform::Transform()
{

}

void Transform::translation(Objeto p, float x, float y, float z)
{
    int i=0;
    for(i=0;i<p.lp.l.size();i++)
    {

        p.lp.l[i].p.setX(p.lp.l[i].p.x+x);
        p.lp.l[i].p.setY(p.lp.l[i].p.y+y);
        p.lp.l[i].p.setZ(p.lp.l[i].p.z+z);
    }
}

void Transform::scale(Objeto p, float x, float y, float z)
{
    int i=0;
    for(i=0;i<p.lp.l.size();i++)
    {
        p.lp.l[i].p.setX(p.lp.l[i].p.x*x);
        p.lp.l[i].p.setY(p.lp.l[i].p.y*y);
        p.lp.l[i].p.setZ(p.lp.l[i].p.z*z);
    }
}

void Transform::rotation(Objeto p, float A,int x,int y,int z)
{
    float cosseno, seno;
    int i=0;
    cosseno = cos(A*PI/180);
    seno = sin(A*PI/180);

    for(i=0;i<p.lp.l.size();i++)
    {
        if((x==1) && (y==0) && (z == 0))//X rotation
        {
            p.lp.l[i].p.setY(p.lp.l[i].p.y*cosseno - p.lp.l[i].p.z*seno);
            p.lp.l[i].p.setZ(p.lp.l[i].p.y*seno    + p.lp.l[i].p.z*cosseno);
        }

        if((x==0) && (y==1) && (z == 0))//Y rotation
        {
            p.lp.l[i].p.setX(p.lp.l[i].p.x*cosseno + p.lp.l[i].p.z*seno);
            p.lp.l[i].p.setZ(-p.lp.l[i].p.x*seno   + p.lp.l[i].p.z*cosseno);
        }

        if((x==0) && (y==0) && (z == 1))//Z rotation
        {
            p.lp.l[i].p.setX(p.lp.l[i].p.x*cosseno - p.lp.l[i].p.y*seno);
            p.lp.l[i].p.setZ(p.lp.l[i].p.x*seno    + p.lp.l[i].p.y*cosseno);
        }
    }
}
