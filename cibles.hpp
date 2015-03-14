#ifndef CIBLES_HPP
#define CIBLES_HPP
#include"bloc.hpp"
#include<list>
#include<QSizeF>
/**
 * @brief The cibles struct
 */
struct cibles
{
    /**
     * @brief cibles
     */
    cibles();
    /**
     * @brief cibles
     * @param N
     * @param nombreLignes
     * @param zone_de_jeu
     */
    cibles(int N, int nombreLignes, QSizeF const& taille);
    /**
     * @brief nombreCibles
     */
    int nombreCibles;
    std::list<bloc> briques;
    /**
     * @brief gestionCollision
     * @param balle
     */
    void gestionCollision(circle const& balle);
};

#endif // CIBLES_HPP
