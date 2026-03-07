//
// Created by sanes on 25/02/2026.
//

#include "Groupe.h"
#include <sstream>
#include "../Connexion/ConnexionServeur.h"
#include "../Visiteur/VisiteurDessin.h"

Groupe::operator std::string() const {
    std::ostringstream o;
    o << "Groupe[" << formesGroupePixel.size() << "," << color << "," << id << ",";
    for(auto const& forme : formesGroupePixel) {
      o << std::string(*forme) << ",";
    }
    std::string s = o.str();
    s.pop_back();

    s += "]";
    return s;
}

void Groupe::dessiner(VisiteurDessin* v) const {
    v->visite(this);
}

double Groupe::calculerAire() const {
    return 0;
}

void Groupe::preparerPixel(Plan& plan) {
    }