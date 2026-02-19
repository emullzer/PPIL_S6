//
// Created by mulle1149u on 07/02/2026.
//

#include "Rond.h"
#include <iostream>
#include <cmath>

#include "../Connexion/ConnexionServeur.h"


Rond::operator std::string() const {
    std::string result = "Rond[" + std::to_string((xCentre)) +"," + std::to_string(static_cast<int>(std::round(yCentre))) + "," + std::to_string(static_cast<int>(std::round(rayon))) + "]";
    return result;
}

void Rond::dessiner() const {
    std::string message = this->operator std::string()+"\n";
    ConnexionServeur::getInstance().envoyerRequete(message);
}
