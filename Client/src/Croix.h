//
// Created by mulle1149u on 07/02/2026.
//

#ifndef CROIX_H
#define CROIX_H
#include "Forme.h"


class Croix: public Forme {
    protected:

    double gauche,haut,droite,bas;


public:
    Croix(const double g,const double h,const double d,const double b) {
        this->gauche = g;
        this->haut = h;
        this->droite = d;
        this->bas = b ;
    }

    explicit operator std::string() const override;
    void dessiner() const override;

    double get_gauche() const {
        return gauche;
    }

    double get_haut() const {
        return haut;
    }

    double get_droite() const {
        return droite;
    }

    double get_bas() const {
        return bas;
    }
};



#endif //CROIX_H
