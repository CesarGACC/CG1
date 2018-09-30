#include "objeto.h"

Objeto::Objeto()
{

}

l_pontos Objeto::translation(float x, float y, float z)
{
    int i=0;
    for(i=0;i<lp.l.size();i++)
    {

        lp.l[i].p.x=(lp.l[i].p.getX()+x);
        lp.l[i].p.y=(lp.l[i].p.getY()+y);
        lp.l[i].p.z=(lp.l[i].p.getZ()+z);
    }
    return lp;
}

l_pontos Objeto::scale(float x, float y, float z)
{
    int i=0;
    for(i=0;i<lp.l.size();i++)
    {
        lp.l[i].p.setX(lp.l[i].p.getX()*x);
        lp.l[i].p.setY(lp.l[i].p.getY()*y);
        lp.l[i].p.setZ(lp.l[i].p.getZ()*z);
    }
    return lp;
}

l_pontos Objeto::rotation(float A,int x,int y,int z)
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

    return lp;
}

float Objeto::getX(int i, int j)
{
    return lp.l[lf.l[i].p[j]].p.x;
}

float Objeto::getY(int i, int j)
{
    return lp.l[lf.l[i].p[j]].p.y;
}

float Objeto::getZ(int i, int j)
{
    return lp.l[lf.l[i].p[j]].p.z;
}

int Objeto::rayToFace(coordenada O, coordenada V, float t)
{
    bool ray = true;
    int i,j;
    //coordenada normal, pint, v0,v1;
    float dt,tn,td;
    coordenada pint, w0, w1, w2, wx,a0,a1,a2;
    coordenada vpn0 = coordenada();
    coordenada vpn1 = coordenada();
    coordenada vpn2 = coordenada();
    for(i=0;i<lf.l.size();i++)
    {
        ray = true;
        /*if(rayTriangleIntersect(O, V, lp.l[lf.l[i].p[0]].p, lp.l[lf.l[i].p[1]].p, lp.l[lf.l[i].p[2]].p, t))
        {
            printf("Hit!");
        }*/
        //Plano Normal
        if(i>0)
        {
            j=2;
        }

        vpn0 =  lp.l[lf.l[i].p[1]].p - lp.l[lf.l[i].p[0]].p;
        vpn1 =  lp.l[lf.l[i].p[2]].p - lp.l[lf.l[i].p[0]].p;


        vpn2.crossproduct(vpn0,vpn1);
        vpn2.normalizar();
        dt = vpn2.dotproduct(vpn2,vpn0);

        if(dt<0)
        {
            ray = false; //PARALELO
        }

        tn = vpn2.dotproduct(O,vpn2) + dt;
        td = vpn2.dotproduct(V,vpn2);

        if(td!=0)
        {
            t = tn/td;
        }else
        {
            ray = false;
        }
        if(t<0)
        {
            ray = false;
        }

        pint = O + V*t;

        w0 = pint - lp.l[lf.l[i].p[0]].p;
        w1 = pint - lp.l[lf.l[i].p[1]].p;
        w2 = pint - lp.l[lf.l[i].p[2]].p;

        a0 = lp.l[lf.l[i].p[1]].p - lp.l[lf.l[i].p[0]].p;
        a1 = lp.l[lf.l[i].p[2]].p - lp.l[lf.l[i].p[1]].p;
        a2 = lp.l[lf.l[i].p[0]].p - lp.l[lf.l[i].p[2]].p;

        wx.crossproduct(a0,w0);
        if(vpn2.dotproduct(vpn2,wx) < 0)
        {
            ray = false;
        }

        wx.crossproduct(a1,w1);
        if(vpn2.dotproduct(vpn2,wx) < 0)
        {
            ray = false;
        }

        wx.crossproduct(a2,w2);
        if(vpn2.dotproduct(vpn2,wx) < 0)
        {
            ray = false;
        }

        if(ray==true)
        {return 1;}
    }

    return 0;
}
