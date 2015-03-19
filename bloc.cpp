#include "bloc.hpp"
#include <cmath>
#include"circle.hpp"
#include <cstdlib>
bloc::bloc()
{
}
bloc::bloc(float origine_x, float origine_y, float Longeur, float Hauteur):H(Hauteur),L(Longeur),haut_gauche(origine_x,origine_y),taille(L,H),rectangle(haut_gauche,taille),couleur(std::rand()%255,std::rand()%255,std::rand()%255){
}
/**
@brief bloc::estToucher
@param balle
@return
*permet de determiné si le bloc a été toucher par la balle
**/
bool bloc::estToucher(const circle &balle)
{
    bool retour=false;
    float i=0;
    float increment=0.01;
    do{
        vec2 temp(this->haut_gauche.x(),this->haut_gauche.y()+i);
            if(point_inside_circle(temp,balle))
            {
                retour=true;
            }
            i+=increment;
    }while(i<this->rectangle.height());
    i=0;
    do{
        vec2 temp(this->haut_gauche.x()+i,this->haut_gauche.y());
            if(point_inside_circle(temp,balle))
            {
                retour=true;
            }
            i+=increment;
    }while(i<this->rectangle.width());

    i=0;
    do{
        vec2 temp(this->haut_gauche.x()+this->rectangle.width(),this->haut_gauche.y()+i);
            if(point_inside_circle(temp,balle))
            {
                retour=true;
            }
            i+=increment;
    }while(i<this->rectangle.height());

    i=0;
    do{
        vec2 temp(this->haut_gauche.x()+i,this->haut_gauche.y()+this->rectangle.height());
            if(point_inside_circle(temp,balle))
            {
                retour=true;
            }
            i+=increment;
    }while(i<this->rectangle.width());

    return retour;
}
bool bloc::operator ==(bloc const& A)
{
    if(this->rectangle==A.rectangle){
            return true;
    }

    return false;

}
void bloc::change_origine_x(float x){
    haut_gauche.setX(qreal(x));
}
