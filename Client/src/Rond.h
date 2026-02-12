//
// Created by mulle1149u on 07/02/2026.
//

#ifndef ROND_H
#define ROND_H
#include "Forme.h"
#include <iostream>


class Rond: public Forme {
    double xCentre, yCentre, rayon;

    public:
    Rond(double x, double y, double r) {
        this->xCentre = x;
        this->yCentre = y;
        this->rayon = r;
    }

    void dessiner() const override;
    explicit operator std::string() const override;

};



#endif //ROND_H
