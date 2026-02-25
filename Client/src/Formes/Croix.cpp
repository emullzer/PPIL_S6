//
// Created by mulle1149u on 07/02/2026.
//

#include "Croix.h"
#include <string>
#include <cmath>

#include "../Connexion/ConnexionServeur.h"

Croix::operator std::string() const {
    std::ostringstream o;
    o << "Croix[" << position << "," << longueur <<","<< color <<"]";
    return o.str();
}

void Croix::dessiner() const {
    std::string message = this->operator std::string()+"\n";
    ConnexionServeur::getInstance().envoyerRequete(message);
    //std::cout << message ; // Utilisé pour debug
}
