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
    return 0; //TODO
}