#include "cubo.h"

Cubo::Cubo()
{
    lp.push_back(o_ponto(0,0,0,0));
    lp.push_back(o_ponto(1,1,0,0));
    lp.push_back(o_ponto(2,1,1,0));
    lp.push_back(o_ponto(3,0,1,0));
    lp.push_back(o_ponto(4,0,0,-1));
    lp.push_back(o_ponto(5,1,0,-1));
    lp.push_back(o_ponto(6,1,1,-1));
    lp.push_back(o_ponto(7,0,1,-1));

    lf.push_back(o_face(0,0,1,3));
    lf.push_back(o_face(1,1,2,3));

    lf.push_back(o_face(2,3,2,7));
    lf.push_back(o_face(3,2,6,7));

    //lf.push_back(o_face(4,7,6,4));
    //lf.push_back(o_face(5,6,5,4));

    //lf.push_back(o_face(6,4,5,0));
    //lf.push_back(o_face(7,5,1,0));

    //lf.push_back(o_face(8,1,5,2));
    //lf.push_back(o_face(9,5,6,2));

    lf.push_back(o_face(10,4,3,7));
    lf.push_back(o_face(11,4,0,3));
}
