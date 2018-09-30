#include "cubo.h"

cubo::cubo()
{
    lp.l.push_back(o_ponto(0,0,0,0));
    lp.l.push_back(o_ponto(1,1,0,0));
    lp.l.push_back(o_ponto(2,1,1,0));
    lp.l.push_back(o_ponto(3,0,1,0));
    lp.l.push_back(o_ponto(4,0,0,1));
    lp.l.push_back(o_ponto(5,1,0,1));
    lp.l.push_back(o_ponto(6,1,1,1));
    lp.l.push_back(o_ponto(7,0,1,1));

    lf.l.push_back(o_face(0,0,1,3));
    lf.l.push_back(o_face(1,1,2,3));

    lf.l.push_back(o_face(2,3,2,7));
    lf.l.push_back(o_face(3,2,6,7));

    lf.l.push_back(o_face(4,7,6,4));
    lf.l.push_back(o_face(5,6,5,4));

    lf.l.push_back(o_face(6,4,5,0));
    lf.l.push_back(o_face(7,5,1,0));

    lf.l.push_back(o_face(8,1,5,2));
    lf.l.push_back(o_face(9,5,6,2));

    lf.l.push_back(o_face(10,0,4,3));
    lf.l.push_back(o_face(11,4,7,3));
}
