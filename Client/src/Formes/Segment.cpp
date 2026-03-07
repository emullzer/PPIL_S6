//
// Created by sanes on 07/03/2026.
//

#include "Segment.h"
#include "../Connexion/ConnexionServeur.h"

Segment::operator std::string() const {
    std::ostringstream o;
    o << "Segment[" << APixel << "," << BPixel <<","<< color << "," << id <<"]";
    return o.str();
}

void Segment::dessiner() const {
    std::string message = this->operator std::string()+"\n";
    ConnexionServeur::getInstance().envoyerRequete(message);
    //std::cout << message ; // Utilisé pour debug
}

double Segment::calculerAire() const {
    return 0;
}

void Segment::preparerPixel(Plan &plan) {
    Vecteur2D omega = plan.getOmega();

    APixel = plan.getMatrice() * A + omega;
    BPixel = plan.getMatrice() * B + omega;
}
