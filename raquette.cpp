#include "raquette.hpp"
#include<QRect>
#include<QPoint>
raquette::raquette(float origine_x, float origine_y, float Longeur, float Hauteur, float r_x, float r_y):bloc(origine_x,origine_y,Longeur,Hauteur),angle_x(r_x),angle_y(r_y)
{
}
void raquette::change_haut_gauche(const vec2 &nvl_posi){
    haut_gauche.setX(nvl_posi.x);
    haut_gauche.setY(nvl_posi.y);
//    this->rectangle(this->haut_gauche,this->taille);
    this->rectangle.setTopLeft(this->haut_gauche);
    this->rectangle.setSize(this->taille);
}
