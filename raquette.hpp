#ifndef RAQUETTE_HPP
#define RAQUETTE_HPP
#include"bloc.hpp"
class raquette : public bloc
{
public:
    raquette(float origine_x,float origine_y,float Longeur,float Hauteur,float r_x,float r_y);
    float angle_x;
    float angle_y;
    void change_haut_gauche(vec2 const& nvl_posi);
};

#endif // RAQUETTE_HPP
