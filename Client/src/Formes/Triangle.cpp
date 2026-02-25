//
// Created by sanes on 19/02/2026.
//

#include "Triangle.h"
#include "../Connexion/ConnexionServeur.h"


Triangle::operator std::string() const {
    std::ostringstream o;
    o << "Triangle[" << sommet1 << "," << sommet2 << "," << sommet3 << "," << color << "]";
    return o.str();
}


void Triangle::dessiner() const{
    std::string message = this->operator std::string()+"\n";
    ConnexionServeur::getInstance().envoyerRequete(message);
}