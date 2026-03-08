//
// Created by sanes on 06/03/2026.
//

#include "ExpertCharger.h"

Forme *ExpertCharger::charger(const std::string &ligne) const {

    Forme* f = charger2(ligne);
    if (f != nullptr) return f;

    if (suivant != nullptr) return suivant->charger(ligne);

    return nullptr; // Personne n'a trouvé
}