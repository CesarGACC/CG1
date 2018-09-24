#include "cubo.h"

/*cubo::cubo()
{

}*/

cubo::cubo()
{
    lp.l.push_back(o_ponto(0,0,0,0));
    lp.l.push_back(o_ponto(1,1,0,0));
    lp.l.push_back(o_ponto(2,1,1,0));
    lp.l.push_back(o_ponto(3,0,1,0));
    lp.l.push_back(o_ponto(4,0,1,1));
    lp.l.push_back(o_ponto(5,1,0,1));
    lp.l.push_back(o_ponto(6,1,1,1));
    lp.l.push_back(o_ponto(7,0,1,1));

    lf.l.push_back(o_face(0,lp.l.at(0),lp.l.at(1),lp.l.at(2)));
    lf.l.push_back(o_face(0,lp.l.at(0),lp.l.at(1),lp.l.at(3)));
    lf.l.push_back(o_face(0,lp.l.at(3),lp.l.at(2),lp.l.at(6)));
    lf.l.push_back(o_face(0,lp.l.at(3),lp.l.at(6),lp.l.at(7)));
    lf.l.push_back(o_face(0,lp.l.at(4),lp.l.at(7),lp.l.at(5)));
    lf.l.push_back(o_face(0,lp.l.at(6),lp.l.at(5),lp.l.at(7)));
    lf.l.push_back(o_face(0,lp.l.at(1),lp.l.at(4),lp.l.at(5)));
    lf.l.push_back(o_face(0,lp.l.at(0),lp.l.at(4),lp.l.at(1)));
    lf.l.push_back(o_face(0,lp.l.at(3),lp.l.at(7),lp.l.at(4)));
    lf.l.push_back(o_face(0,lp.l.at(3),lp.l.at(4),lp.l.at(0)));
    lf.l.push_back(o_face(0,lp.l.at(5),lp.l.at(6),lp.l.at(2)));
    lf.l.push_back(o_face(0,lp.l.at(5),lp.l.at(2),lp.l.at(1)));
}
