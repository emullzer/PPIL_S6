//
// Created by sanes on 25/02/2026.
//

#include "Groupe.h"
#include <sstream>
#include "../Connexion/ConnexionServeur.h"

Groupe::operator std::string() const {
    std::ostringstream o;
    o << "Groupe[";
    for(auto const& forme : formesGroupe) {
      o << std::string(*forme) << ";";
    }
    std::string s = o.str();
    s.pop_back();

    s += "]";
    return s;
}

void Groupe::dessiner() const {
    std::string message = this->operator std::string()+"\n";
    ConnexionServeur::getInstance().envoyerRequete(message);
    //std::cout << message ; // Utilisé pour debug
}