//
// Created by sanes on 05/03/2026.
//

#include "Rectangle.h"
#include "../Connexion/ConnexionServeur.h"

void Formes::Rectangle::dessiner() const {
    std::string message = this->operator std::string()+"\n";
    ConnexionServeur::getInstance().envoyerRequete(message);
}

Formes::Rectangle::operator std::string() const {
    std::ostringstream o;
    o << "Rectangle[" << pointHautGauchePixel << "," << pointBasDroitPixel <<"," << color << "]";
    return o.str();
}

double Formes::Rectangle::calculerAire() const {
    return (getMaxX()-getMinX())*(getMaxY()-getMinY());
}

void Formes::Rectangle::preparerPixel(Plan &plan) {
    Vecteur2D omega = plan.getOmega();

    pointHautGauchePixel = plan.getMatrice() * pointHautGauche + omega;
    pointBasDroitPixel = plan.getMatrice() * pointBasDroit + omega;
}
