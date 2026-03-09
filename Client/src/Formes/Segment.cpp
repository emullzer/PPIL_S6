//
// Created by sanes on 07/03/2026.
//

#include "Segment.h"
#include "../Connexion/ConnexionServeur.h"
#include "../Visiteur/Visiteur.h"
#include "../Visiteur/VisiteurSauvegarde.h"

Segment::operator std::string() const {
    std::ostringstream o;
    o << "Segment[" << APixel << "," << BPixel <<","<< color << "," << id <<"]";
    return o.str();
}

void Segment::dessiner(Visiteur* v) const {
    v->visite(this);
}
void Segment::sauvegarder(VisiteurSauvegarde* v) const {
    return v->visite(this);
}

void Segment::preparerPixel(Plan &plan) {
    Vecteur2D omega = plan.getOmega();

    APixel = plan.getMatrice() * A + omega;
    BPixel = plan.getMatrice() * B + omega;
}
std::string Segment::tranformerCoordonnees()const {
    std::ostringstream o;
    o << "( " << A << ") (" << B << ") " << color << std::endl;
    return o.str();
}
