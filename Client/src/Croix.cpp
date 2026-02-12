//
// Created by mulle1149u on 07/02/2026.
//

#include "Croix.h"
#include <string>
#include <cmath>

#include "Connexion/ConnexionServeur.h"

Croix::operator std::string() const {
    std::string result = "Croix[" + std::to_string(static_cast<int>(std::round(gauche))) +"," + std::to_string(static_cast<int>(std::round(haut))) + "," + std::to_string(static_cast<int>(std::round(droite))) + ","+ std::to_string(static_cast<int>(std::round(bas))) +"]";
    return result;
}

void Croix::dessiner() const {
    ConnexionServeur connexion;
    connexion.envoyerRequete(this->operator std::string());

}
