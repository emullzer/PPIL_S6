/**
 * @file Groupe.h
 * @brief Définition de la classe Groupe, permettant de manipuler des ensembles de formes.
 */

#ifndef GROUPE_H
#define GROUPE_H

#include <iostream>
#include <vector>
#include <algorithm> // Pour std::max et std::min
#include "Forme.h"

/**
 * @class Groupe
 * @brief Classe représentant un groupe, c'est-à-dire un ensemble de Formes.
 * * Cette classe implémente le pattern **Composite** : un Groupe est lui-même une Forme.
 * Chaque Forme ne peut appartenir qu'à un seul et unique Groupe.
 */
class Groupe : public Forme {
private:
    /** @brief Vecteur contenant l'ensemble des pointeurs vers les formes du Groupe. */
    std::vector<Forme*> formesGroupe;

public:
    /**
     * @brief Constructeur avec la couleur du Groupe.
     * @param couleur Chaîne de caractères définissant la couleur commune du groupe.
     */
    explicit Groupe(const std::string &couleur) {
        this->color = couleur;
        id = auto_id++;
    }

    /** @brief Destructeur. Libère les ressources spécifiques au groupe si nécessaire. */
    ~Groupe() override = default;

    /**
     * @brief Ajoute une nouvelle Forme au groupe.
     * @param forme Pointeur vers la forme à ajouter.
     * @throw std::invalid_argument Si la forme possède déjà un parent (un seul groupe autorisé).
     * @note La couleur de la forme ajoutée est automatiquement alignée sur celle du groupe.
     */
    void ajouterForme(Forme* &forme) {
        if (forme->getParent() != nullptr) {
            throw std::invalid_argument("La forme appartient deja a un groupe");
        }
        forme->setCouleur(color);
        forme->setParent(this); // Mise à jour du lien parent
        this->formesGroupe.push_back(forme);
    }

    /** @inheritdoc */
    explicit operator std::string() const override;

    /**
     * @inheritdoc
     * @details Appelle récursivement la méthode dessiner sur toutes les formes contenues.
     */
    void dessiner(Visiteur* v) const override;

    /**
     * @inheritdoc
     * @return La somme des aires de toutes les formes du groupe.
     */
    double calculerAire() const override;

    /** @name Calcul des limites (Bounding Box)
     * Ces méthodes parcourent toutes les formes pour déterminer l'enveloppe globale du groupe.
     * @{ */

    /** @inheritdoc */
    double getMaxY() const override {
        if (formesGroupe.empty()) return 0;
        double maxVal = formesGroupe[0]->getMaxY();
        for(auto forme : formesGroupe) maxVal = std::max(maxVal, forme->getMaxY());
        return maxVal;
    }

    /** @inheritdoc */
    double getMaxX() const override {
        if (formesGroupe.empty()) return 0;
        double maxVal = formesGroupe[0]->getMaxX();
        for(auto forme : formesGroupe) maxVal = std::max(maxVal, forme->getMaxX());
        return maxVal;
    }

    /** @inheritdoc */
    double getMinY() const override {
        if (formesGroupe.empty()) return 0;
        double minVal = formesGroupe[0]->getMinY();
        for(auto forme : formesGroupe) minVal = std::min(minVal, forme->getMinY());
        return minVal;
    }

    /** @inheritdoc */
    double getMinX() const override {
        if (formesGroupe.empty()) return 0;
        double minVal = formesGroupe[0]->getMinX();
        for(auto forme : formesGroupe) minVal = std::min(minVal, forme->getMinX());
        return minVal;
    }
    /** @} */

    /** @brief Retourne le nombre de formes actuellement dans le groupe. */
    int getNbFormes() const { return formesGroupe.size(); }

    /** @brief Retourne la liste des pointeurs de formes du groupe. */
    std::vector<Forme*> getFormes() const { return formesGroupe; }

    /** @inheritdoc */
    void preparerPixel(Plan &plan) override;

    /** @name Transformations Géométriques
     * Les transformations sont appliquées récursivement à chaque membre du groupe.
     * @{ */

    /** @inheritdoc */
    void translation(const Vecteur2D& v) override {
        for(auto forme : formesGroupe) forme->translation(v);
    }

    /** @inheritdoc */
    void homothetie(double rapport, const Vecteur2D& centre) override {
        for(auto forme : formesGroupe) forme->homothetie(rapport, centre);
    }

    /** @inheritdoc */
    void rotation(double angle, const Vecteur2D& pointPivot) override {
        for(auto forme : formesGroupe) forme->rotation(angle, pointPivot);
    }
    /** @} */

    /** @inheritdoc */
    void sauvegarder(VisiteurSauvegarde* v) const override;

    /** @inheritdoc */
    std::string tranformerCoordonnees() const override { return ""; }
};

#endif //GROUPE_H