//
// Created by sanes on 25/02/2026.
//

#include "Groupe.h"
#include <sstream>
#include "../Connexion/ConnexionServeur.h"
#include "../Visiteur/Visiteur.h"

Groupe::operator std::string() const {
    std::ostringstream o;
    o << "Groupe "  << id << ";";
    for(auto const& forme : formesGroupe) {
      o << std::string(*forme) << ";";
    }
    std::string s = o.str();
    s.pop_back();

    return s;
}

void Groupe::dessiner(Visiteur* v) const {
    v->visite(this);
}
void Groupe::sauvegarder(VisiteurSauvegarde* v) const {
    return v->visite(this);
}

double Groupe::calculerAire() const {
    return 0;
}

void Groupe::preparerPixel(Plan& plan) {
    for (auto const& forme : formesGroupe) {
        forme->preparerPixel(plan);
    }
    }