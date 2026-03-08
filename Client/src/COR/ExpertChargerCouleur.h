//
// Created by sanes on 08/03/2026.
//

#ifndef EXPERTCHARGERCOULEUR_H
#define EXPERTCHARGERCOULEUR_H
#include "ExpertCharger.h"
#include <regex>
#include "../Formes/Groupe.h"

class ExpertChargerCouleur : public ExpertCharger {
public:
    using ExpertCharger::ExpertCharger;
protected:
    Forme* charger2(const std::string& ligne) const override {
        std::smatch couleurTrouvee;
        //regex cherche que la ligne soit juste une couleur avec des espaces avant ou apres
        static const std::regex regexCouleur(R"(^\s*([a-zA-Z]+)\s*$)");

        if (std::regex_match(ligne, couleurTrouvee, regexCouleur)) {
            std::string couleurDetectee = couleurTrouvee[1].str();

            // On crée un groupe vide qui porte cette couleur
            // Ton constructeur de Groupe doit accepter une couleur en paramètre
            return new Groupe(couleurDetectee);
        }
        return nullptr;
    }
};

#endif //EXPERTCHARGERCOULEUR_H
