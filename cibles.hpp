#ifndef CIBLES_HPP
#define CIBLES_HPP
#include"bloc.hpp"
#include<list>
#include<QWidget>
struct cibles
{
    cibles();
    /**
     * @brief cibles
     * @param N
     * @param nombreLignes
     *Constructeur des cibles crée N cibles repartient sur nombreLignes
     */
    cibles(int N,int nombreLignes,QWidget zone_de_jeu);
    int nombreCibles;
    std::list<bloc> briques;
    void gestionCollision(circle const& balle);
};

#endif // CIBLES_HPP
