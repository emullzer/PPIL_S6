//
// Created by sanes on 06/03/2026.
//

#ifndef EXPERTCHARGER_H
#define EXPERTCHARGER_H
#include "Expert.h"


class ExpertCharger : public Expert {
    public:
        using Expert::Expert; // Utilise le constructeur de la base

        // Logique commune : si je ne sais pas faire, je demande au suivant
        Forme* resoudre(const std::string& ligne) const override;

    protected:
        // Chaque sous-classe implémentera sa propre analyse de texte ici
        virtual Formes::Forme* resoudre2(const std::string& ligne) const = 0;
    };

};



#endif //EXPERTCHARGER_H
