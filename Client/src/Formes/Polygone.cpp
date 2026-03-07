//
// Created by mulle1149u on 05/03/2026.
//

#include "Polygone.h"
#include "../Connexion/ConnexionServeur.h"

Polygone::operator std::string() const {
    std::ostringstream o;
    o << "Polygone[" << pointsPixel.size() << "," << color << "," << id << ",";
    for( auto const& point : pointsPixel ) {
        o << point<<",";
    }
    o << "]";

    return o.str();
}

void Polygone::dessiner() const {
    std::string message = this->operator std::string()+"\n";
    ConnexionServeur::getInstance().envoyerRequete(message);
    //std::cout << message ; // Utilisé pour debug
}

double Polygone::calculerAire() const {
    return 0;
}

void Polygone::preparerPixel(Plan &plan) {
    Vecteur2D omega = plan.getOmega();
    for( auto const& point : points ) {
        pointsPixel.push_back(plan.getMatrice()* point +omega);
    }
}
