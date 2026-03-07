//
// Created by mulle1149u on 07/02/2026.
//

#include "Rond.h"
#include <sstream>
#include "../Connexion/ConnexionServeur.h"
#include "../Visiteur/VisiteurDessin.h"


Rond::operator std::string() const {
    std::ostringstream o;
    o << "Rond[" << positionPixel << "," << rayonPixel << "," << color << "," << id << "]";
    return o.str();
}

void Rond::dessiner(VisiteurDessin* v) const { //Je pense ici il faudra mettre le accept(patternvisitor) et donc changer les parametres
    v->visite(this);
}

double Rond::calculerAire() const {
    return rayon *  std::numbers::pi * std::numbers::pi;
}

void Rond::preparerPixel( Plan &plan) {
    Vecteur2D omega = plan.getOmega();

    positionPixel = plan.getMatrice()* position +omega;
    std::cout << positionPixel << std::endl;
    rayonPixel = rayon * plan.getLambda();

}

