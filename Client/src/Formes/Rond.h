//
// Created by mulle1149u on 07/02/2026.
//

#ifndef ROND_H
#define ROND_H
#include "Forme.h"
#include <iostream>

#include "Vecteur2D.h"


class Rond: public Forme {
    double rayon;
    Vecteur2D position;

    public:
    Rond(double x, double y, double r,const std::string& color) {
        position = Vecteur2D(x,y);
        this->rayon = r;
        this->color = color;
    }

    void dessiner() const override;
    explicit operator std::string() const override;

};



#endif //ROND_H
