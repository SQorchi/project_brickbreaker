#include "bloc.hpp"
#include <cmath>
#include"circle.hpp"
bloc::bloc()
{
}
bloc::bloc(float origine_x, float origine_y, float Longeur, float Hauteur):H(Hauteur),L(Longeur),haut_gauche(origine_x,origine_y),taille(L,H),rectangle(haut_gauche,taille){
}
/**
@brief bloc::estToucher
@param balle
@return
*permet de determiné si le bloc a été toucher par la balle
**/
bool bloc::estToucher(const circle &balle)
{
    float i=0;
    float j=0;
    float increment=0.01;
    do{
        vec2 temp(this->haut_gauche.x()+i,this->haut_gauche.y()-j);
            if(point_inside_circle(temp,balle))
            {
                return true;
            }
            i+=increment;
            j+=increment;
    }while(i!=L&&j!=H);

    return false;
}
bool bloc::operator ==(bloc const& A)
{
    if(this->rectangle==A.rectangle){
            return true;
    }

    return false;

}
