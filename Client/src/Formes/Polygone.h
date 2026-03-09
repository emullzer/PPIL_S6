/**
 * @file Polygone.h
 * @brief Définition de la classe Polygone.
 */

#ifndef POLYGONE_H
#define POLYGONE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Forme.h"
#include "../Calculs/Vecteur2D.h"
#include "../Calculs/Matrice22.h"

/**
 * @class Polygone
 * @brief Classe représentant un polygone défini par une suite de sommets.
 * * Un polygone est constitué d'au moins 3 points pour former une surface fermée.
 */
class Polygone : public Forme {
protected:
    std::vector<Vecteur2D> points;      /**< Liste des sommets du polygone dans l'espace monde. */
    std::vector<Vecteur2D> pointsPixel; /**< liste des points convertis en coordonnées écran/pixel. */

public:
    /**
     * @brief Constructeur créant un polygone vide.
     * @param color Couleur de remplissage/bordure du polygone.
     */
    explicit Polygone(const std::string& color) {
        points.clear();
        this->color = color;
        id = auto_id++;
    }

    /**
     * @brief Constructeur initialisant le polygone avec une liste de points.
     * @param color Couleur du polygone.
     * @param points Vecteur contenant les sommets initiaux.
     * @throw std::invalid_argument Si le nombre de points est inférieur à 3.
     */
    Polygone(const std::string& color, const std::vector<Vecteur2D>& points) {
        this->color = color;
        if(points.size() < 3) {
            throw std::invalid_argument("Pas assez de points pour faire un Polygone (min 3)");
        }
        this->points = points;
        id = auto_id++;
    }

    /**
     * @brief Ajoute un sommet à la fin de la liste actuelle.
     * @param point Le nouveau Vecteur2D à ajouter.
     */
    void ajouterPoint(const Vecteur2D& point) {
        this->points.push_back(point);
    }

    /** @inheritdoc */
    explicit operator std::string() const override;

    /** @inheritdoc */
    void dessiner(Visiteur* v) const override;

    /**
     * @inheritdoc
     * @note Le calcul est basé sur la formule de l'aire d'un polygone non-auto-intersectant (Formule de Shoelace).
     */
    double calculerAire() const override;

    /** @name Calcul des limites (Bounding Box)
      * Ces méthodes parcourent toutes les formes pour déterminer l'enveloppe globale du groupe.
      * @{ */

    /** @inheritdoc */
    double getMaxY() const override {
        if (points.empty()) return 0;
        double maxVal = points[0].getY();
        for(auto point : points) maxVal = std::max(maxVal, point.getY());
        return maxVal;
    }

    /** @inheritdoc */
    double getMaxX() const override {
        if (points.empty()) return 0;
        double maxVal = points[0].getX();
        for(auto point : points) maxVal = std::max(maxVal, point.getX());
        return maxVal;
    }

    /** @inheritdoc */
    double getMinY() const override {
        if (points.empty()) return 0;
        double minVal = points[0].getY();
        for(auto point : points) minVal = std::min(minVal, point.getY());
        return minVal;
    }

    /** @inheritdoc */
    double getMinX() const override {
        if (points.empty()) return 0;
        double minVal = points[0].getX();
        for(auto point : points) minVal = std::min(minVal, point.getX());
        return minVal;
    }
    /** @} */

    /** @inheritdoc */
    void preparerPixel(Plan &plan) override;

    /** @name Transformations Géométriques
     * @{ */

    /** @inheritdoc */
    void translation(const Vecteur2D& v) override {
        for (auto& point : points) {
            point = point + v;
        }
    }

    /** @inheritdoc */
    void homothetie(double rapport, const Vecteur2D& centre) override {
        for (auto& point : points) {
            point = centre + (point - centre) * rapport;
        }
    }

    /** @inheritdoc */
    void rotation(double angle, const Vecteur2D& centre) override {
        Matrice22 matRotation = Matrice22::creeRotation(angle);
        for (auto& point : points) {
            point = centre + matRotation * (point - centre);
        }
    }
    /** @} */

    /** @inheritdoc */
    void sauvegarder(VisiteurSauvegarde* v) const override;

    /** @inheritdoc */
    virtual std::string tranformerCoordonnees() const override;

};

#endif //POLYGONE_H