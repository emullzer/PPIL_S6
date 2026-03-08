//
// Created by sanes on 05/03/2026.
//

#include "Rectangle.h"
#include "../Connexion/ConnexionServeur.h"
#include "../Visiteur/Visiteur.h"

void Formes::Rectangle::dessiner(Visiteur* v) const {
    v->visite(this);
}
void Formes::Rectangle::sauvegarder(VisiteurSauvegarde* v) const {
    return v->visite(this);
}

Formes::Rectangle::operator std::string() const {
    std::ostringstream o;
    o << "Rectangle[" << p1Pixel << "," << p2Pixel << "," << p3Pixel << "," << p4Pixel <<"," << color << "," << id << "]";
    return o.str();
}

double Formes::Rectangle::calculerAire() const {
    return (getMaxX()-getMinX())*(getMaxY()-getMinY());
}

void Formes::Rectangle::preparerPixel(Plan &plan) {
    Vecteur2D omega = plan.getOmega();

    p1Pixel = plan.getMatrice() * p1 + omega;
    p2Pixel = plan.getMatrice() * p2 + omega;
    p3Pixel = plan.getMatrice() * p3 + omega;
    p4Pixel = plan.getMatrice() * p4 + omega;
}

std::string Formes::Rectangle::tranformerCoordonnees()const {
    std::ostringstream o;
    o << "( " << p1 << ") (" << p2 << ") (" << p3 << ") (" << p4 << ") " << color << std::endl;
    return o.str();
}
