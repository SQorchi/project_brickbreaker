
#include "circle.hpp"

#include <cmath>

circle::circle()
    :center(),radius(0.0f)
{}

circle::circle(vec2 const& center_param,float const radius_center)
    :center(center_param),radius(radius_center)
{}

bool point_inside_circle(vec2 const& p,circle const& c)
{
    vec2 const& u=p-c.center;

    float const n=norm(u);
    float const r=c.radius;

    if(n<=r)
        return true;
    else
        return false;
}
vec2 circle::getCoord()
{
    vec2 retour(0,0);
    retour.x=this->center.x;
    retour.y=this->center.y;
    return retour;
}
