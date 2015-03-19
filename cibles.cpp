#include "cibles.hpp"
#include <QWidget>
cibles::cibles()
{
}
/** Constructeur permettant de genérer une matrice de N element qui remplis toute la partie haute de l'élément*/
cibles::cibles(int N, int nombreLignes):nombreCibles(N)
{
    int H=20;
    int L=38;
    for(int j=0;j<nombreLignes;j++){
        for(int i=0;i<(int)nombreCibles/nombreLignes;i++){
            bloc temp(0+i*L,j*H,L,H);
            this->briques.push_back(temp);
        }
        std::cout<<"on change de ligne"<<std::endl;
    }
    std::cout<<this->briques.size()<<std::endl;
}
void cibles::gestionCollision(const circle &balle)
{
    for(bloc pave : this->briques){
        if(pave.estToucher(balle))
        {
            briques.remove(pave);
            nombreCibles--;
        }
    }
}
