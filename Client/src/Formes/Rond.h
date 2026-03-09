/**
 * @file Rond.h
 * @brief Définition de la classe Rond (Cercle).
 */

#ifndef ROND_H
#define ROND_H

#include "Forme.h"
#include <iostream>
#include <cmath>
#include "../Calculs/Vecteur2D.h"
#include "../Calculs/Matrice22.h"

/**
 * @class Rond
 * @brief Classe représentant un cercle (rond) défini par un centre et un rayon.
 */
class Rond : public Forme {
private:
    double rayon;               /**< Rayon du cercle  */
    double rayonPixel;          /**< Rayon converti en pixels pour l'affichage. */
    Vecteur2D position;         /**< Position du centre du cercle*/
    Vecteur2D positionPixel;    /**< Position du centre convertie en pixels. */

public:
    /**
     * @brief Constructeur de la classe Rond.
     * @param x Abscisse du centre.
     * @param y Ordonnée du centre.
     * @param r Rayon du cercle (doit être positif).
     * @param color Couleur du cercle.
     * @throw std::invalid_argument Si le rayon fourni est négatif.
     */
    Rond(double x, double y, double r, const std::string& color) {
        if (r < 0) throw std::invalid_argument("Le rayon ne peut pas être négatif");
        this->position = Vecteur2D(x, y);
        this->rayon = r;
        this->color = color;
        this->id = auto_id++;
    }

    /** @inheritdoc */
    void dessiner(Visiteur* v) const override;

    /** @inheritdoc */
    void sauvegarder(VisiteurSauvegarde* v) const override;

    /** @inheritdoc */
    virtual std::string tranformerCoordonnees() const override;

    /** @inheritdoc */
    explicit operator std::string() const override;

    /**
     * @inheritdoc
     * @return L'aire calculée via la formule PI * r².
     */
    double calculerAire() const override;

    /** @name Calcul des limites (Bounding Box)
      * Ces méthodes parcourent toutes les formes pour déterminer l'enveloppe globale du groupe.
      * @{ */
    /** @inheritdoc */
    double getMaxY() const override { return position.getY() + rayon; }
    /** @inheritdoc */
    double getMaxX() const override { return position.getX() + rayon; }
    /** @inheritdoc */
    double getMinY() const override { return position.getY() - rayon; }
    /** @inheritdoc */
    double getMinX() const override { return position.getX() - rayon; }
    /** @} */

    /** @inheritdoc */
    void preparerPixel(Plan &plan) override;

    /** @name Transformations Géométriques
     * @{ */

    /**
     * @inheritdoc
     * @details Déplace simplement le centre du cercle par le vecteur v.
     */
    void translation(const Vecteur2D& v) override {
        this->position = this->position + v;
    }

    /**
     * @inheritdoc
     * @details Modifie à la fois la position du centre et la taille du rayon.
     * Le rayon est multiplié par la valeur absolue du rapport.
     */
    void homothetie(double rapport, const Vecteur2D& centre) override {
        this->position = centre + (this->position - centre) * rapport;
        this->rayon = this->rayon * std::abs(rapport);
    }

    /**
     * @inheritdoc
     * @details Fait tourner le centre du cercle autour du point pivot.
     * Note : la rotation n'affecte pas l'apparence visuelle d'un cercle parfait
     * lui-même, mais change sa position relative.
     */
    void rotation(double angle, const Vecteur2D& pointPivot) override {
        Matrice22 mat = Matrice22::creeRotation(angle);
        this->position = pointPivot + mat * (this->position - pointPivot);
    }
    /** @} */
};

#endif //ROND_H