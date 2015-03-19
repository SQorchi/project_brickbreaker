#ifndef RAQUETTE_HPP
#define RAQUETTE_HPP
#include"bloc.hpp"
class raquette : public bloc
{
public:
    raquette(float origine_x,float origine_y,float Longeur,float Hauteur,float r_x,float r_y);
    float angle_x;
    float angle_y;
};

#endif // RAQUETTE_HPP
