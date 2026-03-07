//
// Created by sanes on 06/03/2026.
//

#include "ExpertCharger.h"

Forme *ExpertCharger::resoudre(const std::string &ligne) const {

    Forme* f = resoudre2(ligne);
    if (f != nullptr) return f;

    if (suivant != nullptr) return suivant->resoudre(ligne);

    return nullptr; // Personne n'a trouvé
}