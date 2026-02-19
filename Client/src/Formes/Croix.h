//
// Created by mulle1149u on 07/02/2026.
//

#ifndef CROIX_H
#define CROIX_H
#include "Forme.h"
#include "Vecteur2D.h"


class Croix: public Forme {
    protected:

    Vecteur2D positionHautGauche, positionBasDroite;


public:
    Croix(const double g,const double h,const double d,const double b) {
        positionHautGauche = Vecteur2D(g,h);
        positionBasDroite = Vecteur2D(d,b);
    }

    explicit operator std::string() const override;
    void dessiner() const override;

};



#endif //CROIX_H
