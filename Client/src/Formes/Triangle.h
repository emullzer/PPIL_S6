/**
 * @file Triangle.h
 * @brief Définition de la classe Triangle.
 */

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <algorithm>
#include "Forme.h"
#include "../Calculs/Vecteur2D.h"
#include "../Calculs/Matrice22.h"

/**
 * @class Triangle
 * @brief Classe représentant un triangle défini par ses trois sommets.
 */
class Triangle : public Forme {
private:
    Vecteur2D sommet1, sommet2, sommet3; /**< Les trois sommets du triangle */
    Vecteur2D sommet1Pixel, sommet2Pixel, sommet3Pixel; /**< Les sommets convertis pour le rendu */

public:
    /**
     * @brief Constructeur de la classe Triangle.
     * @param x1 Abscisse du premier sommet.
     * @param y1 Ordonnée du premier sommet.
     * @param x2 Abscisse du deuxième sommet.
     * @param y2 Ordonnée du deuxième sommet.
     * @param x3 Abscisse du troisième sommet.
     * @param y3 Ordonnée du troisième sommet.
     * @param color Couleur du triangle.
     */
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3, const std::string& color)
    {
        sommet1 = Vecteur2D(x1, y1);
        sommet2 = Vecteur2D(x2, y2);
        sommet3 = Vecteur2D(x3, y3);
        this->color = color;
        id = auto_id++;
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
     */
    double calculerAire() const override;

    /** @name Calcul des limites (Bounding Box)
      * Ces méthodes parcourent toutes les formes pour déterminer l'enveloppe globale du groupe.
      * @{ */
    /** @inheritdoc */
    double getMaxY() const override {
        return std::max({sommet1.getY(), sommet2.getY(), sommet3.getY()});
    }
    /** @inheritdoc */
    double getMaxX() const override {
        return std::max({sommet1.getX(), sommet2.getX(), sommet3.getX()});
    }
    /** @inheritdoc */
    double getMinY() const override {
        return std::min({sommet1.getY(), sommet2.getY(), sommet3.getY()});
    }
    /** @inheritdoc */
    double getMinX() const override {
        return std::min({sommet1.getX(), sommet2.getX(), sommet3.getX()});
    }
    /** @} */

    /** @inheritdoc */
    void preparerPixel(Plan &plan) override;

    /** @name Transformations Géométriques
     * @{ */

    /** @inheritdoc */
    void translation(const Vecteur2D& v) override {
        sommet1 = sommet1 + v;
        sommet2 = sommet2 + v;
        sommet3 = sommet3 + v;
    }

    /** @inheritdoc */
    void homothetie(double rapport, const Vecteur2D& centre) override {
        sommet1 = centre + (sommet1 - centre) * rapport;
        sommet2 = centre + (sommet2 - centre) * rapport;
        sommet3 = centre + (sommet3 - centre) * rapport;
    }

    /** @inheritdoc */
    void rotation(double angle, const Vecteur2D& centre) override {
        Matrice22 mat = Matrice22::creeRotation(angle);
        sommet1 = centre + mat * (sommet1 - centre);
        sommet2 = centre + mat * (sommet2 - centre);
        sommet3 = centre + mat * (sommet3 - centre);
    }
    /** @} */

};

#endif //TRIANGLE_H