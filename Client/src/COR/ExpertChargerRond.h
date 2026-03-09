//
// Created by sanes on 08/03/2026.
//

#ifndef EXPERTCHARGERROND_H
#define EXPERTCHARGERROND_H
#include "ExpertCharger.h"

/**
 * @class ExpertChargerRond
 * @brief Expert spécialisé dans le chargement des Ronds.
 */
class ExpertChargerRond : public ExpertCharger {
public:
    /** * @brief Récupère les constructeurs de la classe parente ExpertCharger.
    */
    using ExpertCharger::ExpertCharger;
protected:
    /**
        * @brief Analyse une ligne pour tenter d'en extraire un Rond
        * @details Format doit etre de type : "nbCar (x,y) rayon (color)".
        * Si l'argument color est manquant, alors l'objet est construit avec la couleur noire.
        * * @param ligne La ligne de texte issue du fichier de sauvegarde.
        * @return Forme* Un pointeur vers un nouvel objet Rond si succès, sinon nullptr.
        */
    Forme* charger2(const std::string& ligne) const override;
};




#endif //EXPERTCHARGERROND_H
