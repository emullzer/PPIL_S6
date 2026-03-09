#ifndef EXPERT_H
#define EXPERT_H

#include <string>
#include "../Formes/Forme.h"

/**
 * @class Expert
 * @brief Classe de base abstraite pour la Chaîne de Responsabilité (COR).
 */
class Expert {
protected:
    Expert* suivant; /**< Pointeur vers le prochain expert dans la chaîne de responsabilité. */

public:
    /**
     * @brief Constructeur de l'Expert.
     * @param next Pointeur vers l'expert suivant (peut être nullptr pour le dernier maillon).
     */
    Expert(Expert* next) : suivant(next) {}

    /**
     * @brief Destructeur virtuel par défaut.
     */
    virtual ~Expert() = default;

    /**
     * @brief Tente de charger une forme à partir d'une ligne de texte.
     * @param ligne La chaîne de caractères représentant une forme sauvegardée.
     * @return Forme* Un pointeur vers la forme créée, ou nullptr si aucun expert n'a pu traiter la ligne.
     */
    virtual Forme* charger(const std::string& ligne) const = 0;
};

#endif