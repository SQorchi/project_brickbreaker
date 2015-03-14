#ifndef BLOC_HPP
#define BLOC_HPP
#include"vec2.hpp"
#include"circle.hpp"
/**
 * @brief The bloc struct
 */
struct bloc
{
    bloc();
    /**
     * @brief bloc
     * @param origine
     * @param Longeur
     * @param Hauteur
     * Constructeur d'un bloc
     */
    bloc(vec2 origine,float Longeur,float Hauteur);
    /** Origine du bloc (en bas à gauche)*/
    vec2 bas_gauche;
    /** L=largeur H=hauteur*/
    float L,H;
    /**
/**     * @brief estToucher
/**     * @param balle
/**     * @return
/**     */
    bool estToucher(circle const& balle);
    /**
     * @brief operator ==
     * @param A
     * @return
     */
    bool operator ==(bloc const& A);
};


#endif // BLOC_HPP
