#include "bloc.hpp"
#include <cmath>
#include"circle.hpp"
bloc::bloc()
{
}
bloc::bloc(vec2 origine,float Longeur,float Hauteur):bas_gauche(origine),L(Longeur),H(Hauteur){}
/**
/** * @brief bloc::estToucher
/** * @param balle
/** * @return
 *permet de determiné si le bloc a été toucher par la balle
/** */
bool bloc::estToucher(const circle &balle)
{
    for(int i=0;i<L;i++){
        for(int j=0;j<H;j++){
            vec2 temp(this->bas_gauche.x+i,this->bas_gauche.y+j);
            if(point_inside_circle(temp,balle))
            {
                return true;
            }
        }
    }
    return false;
}
bool bloc::operator ==(bloc const& A)
{
    if(this->bas_gauche.x==A.bas_gauche.x&&this->bas_gauche.y==A.bas_gauche.y){
        if(this->H==A.H&&this->L==A.L)
            return true;
    }

    return false;

}
