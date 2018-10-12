#include "objeto.h"

Objeto::Objeto()
{
    corAMB = Cor(0.1,0.1,0.1);
    corDIF = Cor(0.8,0.8,0.8);
    corESP = Cor(0.2,0.2,0.2);
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
    int i,a,b,c,ww;
    float dt,tn,td,t,aux;
    float newt;
    int facea,faceb,facec;
    newt = FLT_MAX;


<<<<<<< HEAD
=======
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
            ray = false;//salvar menor t
        }
>>>>>>> 6c4b512d3aa36ac9b06133152446ae0e902392f8

    coordenada vpn0,vpn1,vpn2, vpnx;
    coordenada w0, w1, w2, wx,a0,a1,a2,pint;
    //for(int j=0;j<this->size() ;j++)
    //{
        for(int i=0;i<(int)lf.size();i++)
        {
            ray = true;
            vpn2 = coordenada();
            a = lf[i].p[0];
            b = lf[i].p[1];
            c = lf[i].p[2];
            vpn0 =  lp[b].p - lp[a].p;
            vpn1 =  lp[c].p - lp[a].p;
            vpn2 = vpn2.crossproduct(vpn0,vpn1);
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
            if(t<=0)
            {
                ray = false;
            }else
            {
                if(t<newt)
                {
                    newt = t;
                    facea = a;
                    faceb = b;
                    facec = c;
                    vpnx = vpn2;
                }else
                {
                    ray = false;
                }
            }

            if(ray==true)
            {
                ww=0;

                pint = V*newt + O;
                w0 = pint - lp[facea].p;
                w1 = pint - lp[faceb].p;
                w2 = pint - lp[facec].p;

                a0 = lp[faceb].p - lp[facea].p;
                a1 = lp[facec].p - lp[faceb].p;
                a2 = lp[facea].p - lp[facec].p;
                wx = coordenada();
                wx = wx.crossproduct(a0,w0);
                wx.normalizar();
                aux = vpnx.dotproduct(vpnx,wx);
                if(aux < 0)ww--;
                else ww++;

                wx = wx.crossproduct(a1,w1);
                aux = vpnx.dotproduct(vpnx,wx);
                if(aux < 0)ww--;
                else ww++;

                wx = wx.crossproduct(a2,w2);
                aux = vpnx.dotproduct(vpnx,wx);
                if(aux < 0)ww--;
                else ww++;

                if((ww==3) || (ww==-3))ray = true;
                else ray=false;
                i=i;
            }
            if(ray==true)
            {
                calcularCor(V, pint, vpnx, Luz(1.000, 1.000, 1.000, 0,10,2));
                return 1;
            }
        }
    //}
    return 0;
}

Cor Objeto::calcularCor(coordenada V, coordenada pint, coordenada normal, Luz luz)
{
    normal.normalizar();
    luz.p.normalizar();
    pint.normalizar();

    float difusa, especular;
    coordenada r,l;
    l = luz.p - pint;
    l.normalizar();
    difusa = normal.dotproduct(normal,l);

    r = normal;
    r = (r*difusa)*2;
    r = r - l;
    r.normalizar();
    especular = r.dotproduct(r,V);


   corAparente.r = corAMB.r * luz.cor.r + corDIF.r * luz.cor.r * difusa ;//+ luz.cor.r * corESP.r * especular;
   corAparente.g = corAMB.g * luz.cor.g + corDIF.g * luz.cor.g * difusa ;//+ luz.cor.g * corESP.g * especular;
   corAparente.b = corAMB.b * luz.cor.b + corDIF.b * luz.cor.b * difusa ;//+ luz.cor.b * corESP.b * especular;

}
