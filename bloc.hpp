#ifndef BLOC_HPP
#define BLOC_HPP
#include"vec2.hpp"
#include"circle.hpp"
#include<QSizeF>
#include<QPointF>
#include<QRectF>
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
    bloc(float origine_x,float origine_y,float Longeur,float Hauteur);
    /** Origine du bloc (en haut à gauche)*/
    QPointF haut_gauche;
    /** L=largeur H=hauteur*/
    float L,H;
    QSizeF taille;
    QRectF rectangle;

    /**
@brief estToucher
@param balle
@return
**/
    bool estToucher(circle const& balle);
    /**
     * @brief operator ==
     * @param A
     * @return
     */
    bool operator ==(bloc const& A);
};


#endif // BLOC_HPP
