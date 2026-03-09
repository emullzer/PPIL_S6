//
// Created by sanes on 08/03/2026.
//

#ifndef EXPERTCHARGERTRIANGLE_H
#define EXPERTCHARGERTRIANGLE_H
#include "ExpertCharger.h"

/**
 * @class ExpertChargerRond
 * @brief Expert spécialisé dans le chargement des Triangles.
 */
class ExpertChargerTriangle : public ExpertCharger {
public:
    /** * @brief Récupère les constructeurs de la classe parente ExpertCharger.
    */
    using ExpertCharger::ExpertCharger;
protected:
    /**
       * @brief Analyse une ligne pour tenter d'en extraire un Triangle.
       * @details Format doit etre de type : "nbCar (x,y)x3 (color)"
       * Si l'argument color est manquant, alors l'objet est construit avec la couleur noire.
       * * @param ligne La ligne de texte issue du fichier de sauvegarde.
       * @return Forme* Un pointeur vers un nouvel objet Rond si succès, sinon nullptr.
       */
    Forme* charger2(const std::string& ligne) const override;
};



#endif //EXPERTCHARGERTRIANGLE_H
