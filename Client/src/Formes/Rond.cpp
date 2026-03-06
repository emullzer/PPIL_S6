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
    Matrice22 matrice = plan.getMatrice();
    //calcul de a et b; omega = c' - L * C
    Vecteur2D omega = Vecteur2D(plan.getLPixel()/2,plan.getHPixel()/2) -
        (plan.getMatrice()*Vecteur2D(plan.getLMonde()/2,plan.getHMonde()/2));

    positionPixel = plan.getMatrice()* position +omega;
    rayonPixel = rayon * plan.getLambda();

}

