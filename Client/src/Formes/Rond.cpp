//
// Created by mulle1149u on 07/02/2026.
//

#include "Rond.h"
#include <iostream>
#include <cmath>

#include "../Connexion/ConnexionServeur.h"


Rond::operator std::string() const {
    std::ostringstream o;
    o << "Rond[" << position << "," << rayon << "," << color << "]";
    return o.str();
}

void Rond::dessiner() const { //Je pense ici il faudra mettre le accept(patternvisitor) et donc changer les parametres
    std::string message = this->operator std::string()+"\n";
    ConnexionServeur::getInstance().envoyerRequete(message);
}
