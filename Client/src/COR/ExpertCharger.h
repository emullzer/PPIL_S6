#ifndef EXPERTCHARGER_H
#define EXPERTCHARGER_H

#include "Expert.h"

/**
 * @class ExpertCharger
 * @brief Classe de base pour les experts concrets de chargement de formes.
 */
class ExpertCharger : public Expert {
public:
    /** * @brief Utilise le constructeur de la classe Expert.
     * @param next Pointeur vers l'expert suivant dans la chaîne.
     */
    using Expert::Expert;

    /**
     * @brief Point d'entrée pour le chargement d'une ligne. Utilise ensuite la fonction
     * charger2 pour réaliser la Chain of Responsability.
     * @param ligne La chaîne de caractères à analyser.
     * @return Forme* Pointeur vers la forme créée, ou résultat de l'expert suivant.
     */
    Forme* charger(const std::string& ligne) const override;

protected:

    /**
     * @brief Méthode d'analyse spécifique à implémenter dans les classes filles.
     * @param ligne La ligne de texte à analyser.
     * @return Forme* Pointeur vers la forme créée si le format correspond, sinon nullptr.
     */
    virtual Forme* charger2(const std::string& ligne) const = 0;
};

#endif //EXPERTCHARGER_H
