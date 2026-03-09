//
// Created by mulle1149u on 05/03/2026.
//

#include "Polygone.h"
#include "../Connexion/ConnexionServeur.h"
#include "../Visiteur/Visiteur.h"
#include "../Visiteur/VisiteurSauvegarde.h"

Polygone::operator std::string() const {
    std::ostringstream o;
    o << "Polygone[" << color << "," << id << ",";
    for( auto const& point : pointsPixel ) {
        o << point<<",";
    }
    o << "]";

    return o.str();
}

void Polygone::dessiner(Visiteur* v) const {
    v->visite(this);
}
void Polygone::sauvegarder(VisiteurSauvegarde* v) const {
    return v->visite(this);
}

double Polygone::calculerAire() const {
    double aire = 0.0;
    int n = static_cast<int>(points.size());

    for (int i = 0; i < n; ++i) {
        // On récupère le point actuel et le suivant (avec modulo pour boucler)
        const Vecteur2D& p1 = points[i];
        const Vecteur2D& p2 = points[(i + 1) % n];

        // Calcul du déterminant 2D (produit en croix)
        aire += (p1.x * p2.y) - (p2.x * p1.y);
    }

    return std::abs(aire) / 2.0;
}

void Polygone::preparerPixel(Plan &plan) {
    Vecteur2D omega = plan.getOmega();
    for( auto const& point : points ) {
        pointsPixel.push_back(plan.getMatrice()* point +omega);
    }
}

 std::string Polygone::tranformerCoordonnees()const {
    std::ostringstream o;
    o << points.size() ;
    for( auto const& point : points ) {
        o <<" ( "<< point << ")";
    }
    o << " " << color << std::endl;
    return o.str();
}
