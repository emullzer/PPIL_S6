//
// Created by sanes on 08/03/2026.
//

#ifndef EXPERTCHARGERFACES_H
#define EXPERTCHARGERFACES_H
#include "ExpertCharger.h"

/**
 * @class ExpertChargerFaces
 * @brief Expert spécialisé dans le chargement des Polygones (Faces).
 */
class ExpertChargerFaces : public ExpertCharger {
public:
    /** * @brief Récupère les constructeurs de la classe parente ExpertCharger.
        */
    using ExpertCharger::ExpertCharger;

    protected:
    /**
        * @brief Analyse une ligne pour tenter d'en extraire un Polygone.
        * @details Format doit etre de type : "nbCar nbPolygones ( 2.09827, -0.12983) ..... (x,y) (color)".
        * Si l'argument color est manquant, alors l'objet est construit avec la couleur noire.
        * @param ligne La ligne de texte issue du fichier de sauvegarde.
        * @return Forme* Un pointeur vers un nouvel objet Polygone si succès, sinon nullptr.
        */
        Forme* charger2(const std::string& ligne) const override;
};



#endif //EXPERTCHARGERFACES_H
