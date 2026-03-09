#ifndef EXPERTCHARGERARETE_H
#define EXPERTCHARGERARETE_H

#include "ExpertCharger.h"
#include "../Formes/Segment.h"
#include <regex>

/**
 * @class ExpertChargerArete
 * @brief Expert spécialisé dans le chargement des segments (arêtes).
 */
class ExpertChargerArete : public ExpertCharger {
public:
       /** * @brief Récupère les constructeurs de la classe parente ExpertCharger.
        */
       using ExpertCharger::ExpertCharger;

protected:
       /**
        * @brief Analyse une ligne pour tenter d'en extraire un Segment.
        * @details Format doit etre de type : "43 ( 2.09827, -0.12983) (color)".
        * * Si l'argument color est manquant, alors l'objet est construit avec la couleur noire.
        * @param ligne La ligne de texte issue du fichier de sauvegarde.
        * @return Forme* Un pointeur vers un nouvel objet Segment si succès, sinon nullptr.
        */
       Forme* charger2(const std::string& ligne) const override;
};

#endif // EXPERTCHARGERARETE_H