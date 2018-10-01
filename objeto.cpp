#include "objeto.h"

Objeto::Objeto()
{
    this->r = this->g = this->b = 1.000;
}

vector<o_ponto> Objeto::translation(float x, float y, float z)
{
    int i=0;
    for(i=0;i<(int)lp.size();i++)
    {

        lp[i].p.x=(lp[i].p.getX()+x);
        lp[i].p.y=(lp[i].p.getY()+y);
        lp[i].p.z=(lp[i].p.getZ()+z);
    }
    return lp;
}

vector<o_ponto> Objeto::scale(float x, float y, float z)
{
    int i=0;
    for(i=0;i<(int)lp.size();i++)
    {
        lp[i].p.setX(lp[i].p.getX()*x);
        lp[i].p.setY(lp[i].p.getY()*y);
        lp[i].p.setZ(lp[i].p.getZ()*z);
    }
    return lp;
}

vector<o_ponto> Objeto::rotation(float A,int x,int y,int z)
{
    float cosseno, seno;
    int i=0;
    cosseno = cos(A*PI/180);
    seno = sin(A*PI/180);

    for(i=0;i<(int)lp.size();i++)
    {
        if((x==1) && (y==0) && (z == 0))//X rotation
        {
            lp[i].p.setY(lp[i].p.getY()*cosseno - lp[i].p.getZ()*seno);
            lp[i].p.setZ(lp[i].p.getY()*seno    + lp[i].p.getZ()*cosseno);
        }

        if((x==0) && (y==1) && (z == 0))//Y rotation
        {
            lp[i].p.setX(lp[i].p.getX()*cosseno + lp[i].p.getZ()*seno);
            lp[i].p.setZ(-lp[i].p.getX()*seno   + lp[i].p.getZ()*cosseno);
        }

        if((x==0) && (y==0) && (z == 1))//Z rotation
        {

            lp[i].p.setX(lp[i].p.getX()*cosseno - lp[i].p.getY()*seno);
            lp[i].p.setY(lp[i].p.getX()*seno    + lp[i].p.getY()*cosseno);
        }
    }

    return lp;
}

float Objeto::getX(int i, int j)
{
    return lp[lf[i].p[j]].p.x;
}

float Objeto::getY(int i, int j)
{
    return lp[lf[i].p[j]].p.y;
}

float Objeto::getZ(int i, int j)
{
    return lp[lf[i].p[j]].p.z;
}

int Objeto::rayToObject(coordenada O, coordenada V)
{
    bool ray;
    int i,a,b,c;
    float dt,tn,td,t,aux;
    coordenada vpn0,vpn1,vpn2;
    for(i=0;i<(int)lf.size();i++)
    {
        ray = true;
        a = lf[i].p[0];
        b = lf[i].p[1];
        c = lf[i].p[2];
        vpn0 =  lp[b].p - lp[a].p;
        vpn1 =  lp[c].p - lp[a].p;
        vpn2.crossproduct(vpn0,vpn1);
        vpn2.normalizar();
        dt = vpn2.dotproduct(vpn2,V);

        if(fabs(dt) < 0.000001)
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

        if(ray==true)
        {

            coordenada w0, w1, w2, wx, pint,a0,a1,a2;
            pint = O + V*t;
            w0 = pint - lp[a].p;
            w1 = pint - lp[b].p;
            w2 = pint - lp[c].p;

            a0 = lp[b].p - lp[a].p;
            a1 = lp[c].p - lp[b].p;
            a2 = lp[a].p - lp[c].p;

            wx.crossproduct(a0,w0);
            aux = vpn2.dotproduct(vpn2,wx);
            if(aux < 0)
            {
                ray = false;
            }

            wx.crossproduct(a1,w1);
            aux = vpn2.dotproduct(vpn2,wx);
            if(aux < 0)
            {
                ray = false;
            }

            wx.crossproduct(a2,w2);
            aux = vpn2.dotproduct(vpn2,wx);
            if(aux < 0)
            {
                ray = false;
            }
         }
        if(ray==true)
        {
            return 1;
        }
    }
    return 0;
}

void Objeto::setMaterial(float r, float g, float b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}
