/**
 * @file Segment.h
 * @brief Définition de la classe Segment.
 */

#ifndef SEGMENT_H
#define SEGMENT_H

#include "../Calculs/Vecteur2D.h"
#include "../Calculs/Matrice22.h"
#include "Forme.h"

/**
 * @class Segment
 * @brief Classe représentant un segment défini par deux points.
 */
class Segment : public Forme {
protected:
    Vecteur2D A; /**< Premier point d'extrémité du segment. */
    Vecteur2D B; /**< Second point d'extrémité du segment. */

    Vecteur2D APixel; /**< Coordonnées du point A converties pour l'affichage */
    Vecteur2D BPixel; /**< Coordonnées du point B converties pour l'affichage */

public:
    /**
     * @brief Constructeur de la classe Segment.
     * @param x Abscisse du point A.
     * @param y Ordonnée du point A.
     * @param x2 Abscisse du point B.
     * @param y2 Ordonnée du point B.
     * @param color Couleur du segment.
     */
    Segment(const double& x, const double& y, const double& x2, const double& y2, const std::string& color) {
        A = Vecteur2D(x, y);
        B = Vecteur2D(x2, y2);
        this->color = color;
        this->id = auto_id++;
    }

    /** @inheritdoc */
    explicit operator std::string() const override;

    /** @inheritdoc */
    void sauvegarder(VisiteurSauvegarde* v) const override;

    /** @inheritdoc */
    virtual std::string tranformerCoordonnees() const override;

    /** @inheritdoc */
    void dessiner(Visiteur* v) const override;

    /**
     * @inheritdoc
     * @return Toujours 0 car un segment n'a pas de surface.
     */
    double calculerAire() const override { return 0.0; }

    /** @name Calcul des limites (Bounding Box)
      * Ces méthodes parcourent toutes les formes pour déterminer l'enveloppe globale du groupe.
      * @{ */
    /** @inheritdoc */
    double getMaxY() const override { return std::max(A.y, B.y); }
    /** @inheritdoc */
    double getMaxX() const override { return std::max(A.x, B.x); }
    /** @inheritdoc */
    double getMinY() const override { return std::min(A.y, B.y); }
    /** @inheritdoc */
    double getMinX() const override { return std::min(A.x, B.x); }
    /** @} */

    /** @inheritdoc */
    void preparerPixel(Plan &plan) override;

    /** @name Transformations Géométriques
     * @{ */

    /** @inheritdoc */
    void translation(const Vecteur2D& v) override {
        A = A + v;
        B = B + v;
    }

    /** @inheritdoc */
    void homothetie(double rapport, const Vecteur2D& centre) override {
        A = centre + (A - centre) * rapport;
        B = centre + (B - centre) * rapport;
    }

    /** @inheritdoc */
    void rotation(double angle, const Vecteur2D& centre) override {
        Matrice22 matRotation = Matrice22::creeRotation(angle);
        A = centre + matRotation * (A - centre);
        B = centre + matRotation * (B - centre);
    }
    /** @} */

};

#endif //SEGMENT_H