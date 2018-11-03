#include "pot.h"
#define imax 10
Pot::Pot()
{
    int angulo = 10;
    float seno, cosseno;
    float pote[imax][2] = {
                        //{0.0, 0.0},
                        {0.85,0.0},
                        {0.85,0.1},
                        {0.80,0.2},
                        {0.80,0.3},
                        {0.75,0.4},
                        {0.60,0.5},
                        {0.40,0.6},
                        {0.20,0.7},
                        {0.30,0.8},
                        {0.40,0.9}};

    //lp[i].p.setX(lp[i].p.getX()*cosseno + lp[i].p.getZ()*seno);
    //lp[i].p.setZ(-lp[i].p.getX()*seno   + lp[i].p.getZ()*cosseno);
    int j=0;
    for(int ang=0;ang<360;ang=ang+angulo)
    {
        cosseno = cos(ang*PI/180);
        seno = sin(ang*PI/180);

        //lp.push_back(o_ponto(0,pote[0][0], pote[0][1],0));

        for(int i=0;i<imax;i++)
        {
            lp.push_back(o_ponto(j,pote[i][0]*cosseno+0, pote[i][1], -pote[i][0]*seno+0));
            //lp.push_back(o_ponto(i,pote[i][0], pote[i][1],0));
            j++;
        }
    }
    int k,a,b,c,d;
    int kmax = 360/angulo;
    j=0;

    for(int kaux=0;kaux<kmax;kaux++)
    {
        for(int i=0;i<imax-1;i++)
        {
            k =  kaux;
            a =  k*imax+i;
            c =  k*imax+i+1;

            if((k+1)>=kmax) b=i;
            else b = (k+1)*imax +i;
            if((k+1)>=kmax) d=i+1;
            else d = (k+1)*imax +i+1;

            lf.push_back(o_face(j,a,b,c));
            j++;
            lf.push_back(o_face(j,b,d,c));
            j++;
        }
    }


}
