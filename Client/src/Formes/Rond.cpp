//
// Created by mulle1149u on 07/02/2026.
//

#include "Rond.h"
#include <sstream>
#include "../Connexion/ConnexionServeur.h"
#include <cmath>


Rond::operator std::string() const {
    std::ostringstream o;
    o << "Rond[" << positionPixel << "," << rayonPixel << "," << color << "]";
    return o.str();
}

void Rond::dessiner() const { //Je pense ici il faudra mettre le accept(patternvisitor) et donc changer les parametres
    std::string message = this->operator std::string()+"\n";
    ConnexionServeur::getInstance().envoyerRequete(message);
}

double Rond::calculerAire() const {
    return rayon *  std::numbers::pi * std::numbers::pi;
}

void Rond::preparerPixel( Plan &plan) {
    Vecteur2D omega = plan.getOmega();

    positionPixel = plan.getMatrice()* position +omega;
    rayonPixel = rayon * plan.getLambda();

}

