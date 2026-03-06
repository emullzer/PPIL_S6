//
// Created by sanes on 05/03/2026.
//

#include "Rectangle.h"

void Rectangle::dessiner() const {

}

Rectangle::operator std::string() const {
    std::ostringstream o;

    return o.str();
}

double Rectangle::calculerAire() const {
    return (getMaxX()-getMinX())*(getMaxY()-getMinY());
}

void Rectangle::preparerPixel(Plan &plan) {
    Vecteur2D omega = plan.getOmega();

    pointHautGauchePixel = plan.getMatrice() * pointHautGauche + omega;
    pointBasDroitPixel = plan.getMatrice() * pointBasDroit + omega;
}
