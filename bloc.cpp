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

    if(balle.center.y-this->haut_gauche.y()<=this->rectangle.height()+balle.radius&&balle.center.y-this->haut_gauche.y()>=balle.radius){
        if(balle.center.x-this->haut_gauche.x()<=this->rectangle.width()+balle.radius&&balle.center.x-this->haut_gauche.x()>=balle.radius){
            retour=true;
        }
    }
    if(this->rectangle.contains(balle.center.x,balle.center.y))
        retour=true;
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
