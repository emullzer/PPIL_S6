//
// Created by mulle1149u on 07/02/2026.
//

#ifndef CROIX_H
#define CROIX_H
#include "Forme.h"
#include "Vecteur2D.h"
#include <iostream>


class Croix: public Forme {
    protected:

    Vecteur2D position;
    double longueur;


public:
    Croix(const double x,const double y,const double longueur,const std::string& color) {
        position = Vecteur2D(x,y);
        this->longueur = longueur;
        this->color = color;
    }

    explicit operator std::string() const override;
    void dessiner() const override;

};



#endif //CROIX_H
