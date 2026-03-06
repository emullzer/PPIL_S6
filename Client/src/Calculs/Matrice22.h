#ifndef MATRICE22_H
#define MATRICE22_H
#include "Vecteur2D.h"
/**
 * Permet de représenter une matrice de taille 2x2
*/
class Matrice22
{
    public :
    Vecteur2D ligneHaut,ligneBas;

    /**
     * Constructeur de Matrice22
     * @param ligneHaut
     * @param ligneBas
     */
    Matrice22(const Vecteur2D &ligneHaut,const Vecteur2D &ligneBas):ligneHaut(ligneHaut),ligneBas(ligneBas){/*rien à faire*/}

    /**
     * Autre constructeur de Matrice22
     * @param a11
     * @param a12
     * @param a21
     * @param a22
     */
    explicit Matrice22(const double &a11,const double &a12,
                       const double &a21,const double &a22):
              Matrice22(Vecteur2D(a11,a12),Vecteur2D(a21,a22)){}

    /**
     * Permet de faire une rotation selon Alfa
     * @param alfa
     * @return
     */
    static const Matrice22 creeRotation(const double &alfa)
    {
        double calfa=cos(alfa);
        double salfa=sin(alfa);

        return Matrice22(calfa,-salfa,salfa,calfa);
    }

    /**
     * Permet d'afficher la Matrice22
     */
    operator std::string() const
    {
        std::ostringstream o;

        o<<ligneHaut<<std::endl;
        o<<ligneBas;

        return o.str();
    }

    /**
     * Permet de multiplier this par un vecteur2D
     * @param v
     * @return
     */
    const Vecteur2D operator*(const Vecteur2D &v)const
    {
        return Vecteur2D(ligneHaut*v,ligneBas*v);
    }



};

/**
 * Permet de redéfinir l'opérateur <<
 * @param o
 * @param mat
 * @return
 */
inline std::ostream &operator<<(std::ostream&o, const Matrice22&mat){
    return o<<(std::string)mat;
}

#endif