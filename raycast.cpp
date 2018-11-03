#include "raycast.h"

RayCast::RayCast()
{

}

Cor RayCast::rayToObjects(coordenada O, coordenada V, std::vector<Objeto> objetos)
{
    bool TestRay1 = false;
    bool TestRay2 = false;
    int a,b,c,ww, i,j;
    float dt,tn,td,t,aux;
    float newt;
    int face,objeto;
    newt = FLT_MAX;


    coordenada vpn0,vpn1,vpn2, vpnx;
    coordenada w0, w1, w2, wx,a0,a1,a2,pint,pintnew;
    for(j=0; j<objetos.size();j++)
    {
        for(i=0;i<objetos[j].lf.size();i++)
        {

            vpn2 = coordenada();
            a = objetos[j].lf[i].p[0];
            b = objetos[j].lf[i].p[1];
            c = objetos[j].lf[i].p[2];
            vpn0 =  objetos[j].lp[b].p - objetos[j].lp[a].p;
            vpn1 =  objetos[j].lp[c].p - objetos[j].lp[a].p;
            vpn2 = vpn2.crossproduct(vpn1,vpn0);
            vpn2.normalizar();
            dt = vpn2.dotproduct(vpn2,vpn1);

            if(fabs(dt) < 0.000001)
            {
                //TestRay1 = false; //PARALELO
            }

            tn = vpn2.dotproduct(objetos[j].lp[a].p,vpn2) ;
            td = vpn2.dotproduct(V,vpn2);
            if(td!=0)
            {
                t = tn/td;
            }else
            {
                //TestRay1 = false;
            }
            if(t<0)
            {
                //TestRay1 = false;
            }else
            {
                vpnx = vpn2;
                ww=0;
                int facea,faceb,facec;
                facea = objetos[j].lf[i].p[0];
                faceb = objetos[j].lf[i].p[1];
                facec = objetos[j].lf[i].p[2];

                pint = V*t;
                w0 = pint - objetos[j].lp[facea].p;
                w1 = pint - objetos[j].lp[faceb].p;
                w2 = pint - objetos[j].lp[facec].p;

                a0 = objetos[j].lp[faceb].p - objetos[j].lp[facea].p;
                a1 = objetos[j].lp[facec].p - objetos[j].lp[faceb].p;
                a2 = objetos[j].lp[facea].p - objetos[j].lp[facec].p;
                wx = coordenada();
                wx = wx.crossproduct(a0,w0);
                wx.normalizar();
                aux = vpn2.dotproduct(vpn2,wx);
                if(aux <= 0)ww--;
                else ww++;

                wx = wx.crossproduct(a1,w1);
                wx.normalizar();
                aux = vpn2.dotproduct(vpn2,wx);
                if(aux <= 0)ww--;
                else ww++;

                wx = wx.crossproduct(a2,w2);
                wx.normalizar();
                aux = vpn2.dotproduct(vpn2,wx);
                if(aux <= 0)ww--;
                else ww++;

                if((fabs(ww)==3))
                {
                    TestRay2 = true;
                    if(t<newt)
                    {
                        face = i;
                        objeto = j;
                        pintnew=pint;
                        vpnx = vpn2;
                    }
                }
            }
        }

    }

    if(TestRay2==true)
    {
        //return Cor(1.0,1.0,1.0);
        return calcularCor(V, pintnew, vpnx, Luz(0.500, 0.500, 0.500, 0,0,-2), objetos[objeto].lf[face]);
    }else return Cor();
}

Cor RayCast::calcularCor(coordenada V, coordenada pint, coordenada normal, Luz luz, o_face f)
{
    normal.normalizar();
    luz.p.normalizar();



    float difusa, especular,m;
    m = 0.21;
    coordenada r,l,n;

    n = pint - normal;
    n.normalizar();

    l = pint - luz.p;
    l.normalizar();
    difusa = normal.dotproduct(n,l);
    if(difusa<0) difusa = 0;

    r = normal;
    r = (r*difusa)*2;
    r = r - l;
    r.normalizar();
    especular = r.dotproduct(r,V);

    if(especular<0) especular = 0;

    Cor corAparente = Cor();
   corAparente.r = f.corAMB.r * luz.cor.r + f.corDIF.r * luz.cor.r * difusa + f.corESP.r * pow(especular,m);
   corAparente.g = f.corAMB.g * luz.cor.g + f.corDIF.g * luz.cor.g * difusa + f.corESP.g * pow(especular,m);
   corAparente.b = f.corAMB.b * luz.cor.b + f.corDIF.b * luz.cor.b * difusa + f.corESP.b * pow(especular,m);
   return corAparente;
}


Cor RayCast::rayToMaths(coordenada origem, coordenada direcao, std::vector<Objeto> objetos)
{

}
