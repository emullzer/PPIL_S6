//
// Created by sanes on 19/02/2026.
//

#include "Triangle.h"
#include "../Connexion/ConnexionServeur.h"
#include <sstream>


Triangle::operator std::string() const {
    std::ostringstream o;
    o << "Triangle[" << sommet1Pixel << "," << sommet2Pixel << "," << sommet3Pixel << "," << color << "]";
    return o.str();
}


void Triangle::dessiner() const{
    std::string message = this->operator std::string()+"\n";
    ConnexionServeur::getInstance().envoyerRequete(message);
}

double Triangle::calculerAire() const {
    double aire = 0.5 * std::abs(Vecteur2D::determinant(sommet1,sommet2,sommet3));
    return aire;
}

void Triangle::preparerPixel(Plan &plan) {
    Vecteur2D omega = plan.getOmega();

    sommet1Pixel = plan.getMatrice() * sommet1 + omega;
    sommet2Pixel = plan.getMatrice() * sommet2 + omega;
    sommet3Pixel = plan.getMatrice() * sommet3 + omega;
}
