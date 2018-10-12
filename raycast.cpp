#include "raycast.h"

RayCast::RayCast()
{

}

Cor RayCast::rayToObjects(coordenada O, coordenada V, std::vector<Objeto> objetos)
{
    bool TestRay1 = false;
    bool TestRay2 = false;
    int a,b,c,ww;
    float dt,tn,td,t,aux;
    float newt;
    int face,objeto;
    newt = FLT_MAX;


    coordenada vpn0,vpn1,vpn2, vpnx;
    coordenada w0, w1, w2, wx,a0,a1,a2,pint;
    for(int j=0; j<objetos.size();j++)
    {
        for(int i=0;i<objetos[j].lf.size();i++)
        {

            vpn2 = coordenada();
            a = objetos[j].lf[i].p[0];
            b = objetos[j].lf[i].p[1];
            c = objetos[j].lf[i].p[2];
            vpn0 =  objetos[j].lp[b].p - objetos[j].lp[a].p;
            vpn1 =  objetos[j].lp[c].p - objetos[j].lp[a].p;
            vpn2 = vpn2.crossproduct(vpn0,vpn1);
            vpn2.normalizar();
            dt = vpn2.dotproduct(vpn2,objetos[j].lp[a].p);

            if(fabs(dt) < 0.000001)
            {
                //TestRay1 = false; //PARALELO
            }

            tn = vpn2.dotproduct(O,vpn2) + dt;
            td = vpn2.dotproduct(V,vpn2);
            if(td!=0)
            {
                t = tn/td;
            }else
            {
                //TestRay1 = false;
            }
            if(t<=0)
            {
                //TestRay1 = false;
            }else
            {
                if(t<=newt)
                {
                    newt = t;
                    face = i;
                    vpnx = vpn2;
                    objeto = j;
                    TestRay1 = true;
                }
            }
        }
    }
    if(TestRay1==true)
    {
        TestRay2=true;
        ww=0;
        int facea,faceb,facec;
        facea = objetos[objeto].lf[face].p[0];
        faceb = objetos[objeto].lf[face].p[1];
        facec = objetos[objeto].lf[face].p[2];
        pint = V*newt - O;
        w0 = pint - objetos[objeto].lp[facea].p;
        w1 = pint - objetos[objeto].lp[faceb].p;
        w2 = pint - objetos[objeto].lp[facec].p;

        a0 = objetos[objeto].lp[faceb].p - objetos[objeto].lp[facea].p;
        a1 = objetos[objeto].lp[facec].p - objetos[objeto].lp[faceb].p;
        a2 = objetos[objeto].lp[facea].p - objetos[objeto].lp[facec].p;
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

        if((fabs(ww)==3)) TestRay2 = true;
    }
    if(TestRay2==true)
    {
        return calcularCor(V, pint, vpnx, Luz(1.000, 1.000, 1.000, 0,10,2), objetos[objeto].lf[face]);
    }else return Cor();
}

Cor RayCast::calcularCor(coordenada V, coordenada pint, coordenada normal, Luz luz, o_face f)
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

    Cor corAparente = Cor();
   corAparente.r = f.corAMB.r * luz.cor.r + f.corDIF.r * luz.cor.r * difusa ;//+ luz.cor.r * corESP.r * especular;
   corAparente.g = f.corAMB.g * luz.cor.g + f.corDIF.g * luz.cor.g * difusa ;//+ luz.cor.g * corESP.g * especular;
   corAparente.b = f.corAMB.b * luz.cor.b + f.corDIF.b * luz.cor.b * difusa ;//+ luz.cor.b * corESP.b * especular;
   return corAparente;
}


Cor RayCast::rayToMaths(coordenada origem, coordenada direcao, std::vector<Objeto> objetos)
{

}
