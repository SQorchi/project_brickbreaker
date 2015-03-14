#include "cibles.hpp"
#include <QWidget>
cibles::cibles()
{
}
/** Constructeur permettant de genérer une matrice de N element qui remplis toute la partie haute de l'élément*/
cibles::cibles(int N, int nombreLignes, const QSizeF &taille):nombreCibles(N)
{
    int nombreElementsLigne=int(N/nombreLignes);
    float H=0.5/nombreLignes;
    float L=1/nombreElementsLigne;
    float basBlocCible=taille.height()/2;
    for(int j=0;j<nombreLignes;j++){
        for(int i=0;i<nombreElementsLigne;i++)
        {
            //vec2 origine(0+i*L,basBlocCible+j*H);
            float origine_x(0+i*L);
            float origine_y(basBlocCible+j*H);
            bloc temp(origine_x,origine_y,L,H);
            this->briques.push_back(temp);
        }
    }
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
