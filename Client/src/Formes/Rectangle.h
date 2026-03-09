/**
 * @file Rectangle.h
 * @brief Définition de la classe Rectangle.
 */

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "../Calculs/Vecteur2D.h"
#include "Forme.h"
#include <algorithm>

/**
 * @namespace Formes
 * @brief Espace de nommage qui permet d'utiliser la classe Rectangle, sinon il y a des problemes avec certaines librairies.
 */
namespace Formes {

    /**
     * @class Rectangle
     * @brief Classe représentant un rectangle défini par ses quatre sommets.
     * * Le rectangle est stocké via ses 4 coins (Vecteur2D), ce qui permet de maintenir
     * son intégrité géométrique même après des rotations complexes.
     */
    class Rectangle : public Forme {
    private:
        Vecteur2D p1, p2, p3, p4; /**< Sommets du rectangle dans l'espace monde. */
        Vecteur2D p1Pixel, p2Pixel, p3Pixel, p4Pixel; /**< Coordonnées des sommets converties pour le rendu (pixels). */

    public:
        /**
         * @brief Constructeur du Rectangle.
         * * Initialise les sommets du rectangle.
         * * @param x1 Abscisse du premier point.
         * @param y1 Ordonnée du premier point.
         * @param x2 Abscisse du point opposé (diagonale).
         * @param y2 Ordonnée du point opposé (diagonale).
         * @param x3 Abscisse du troisième point (utilisé pour l'extension future).
         * @param y3 Ordonnée du troisième point.
         * @param x4 Abscisse du quatrième point.
         * @param y4 Ordonnée du quatrième point.
         * @param color Couleur du rectangle.
         */
        Rectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, const std::string& color) {
            p1 = Vecteur2D(x1, y1); // Haut-Gauche
            p2 = Vecteur2D(x2, y2); // Haut-Droit
            p3 = Vecteur2D(x3, y2); // Bas-Droit
            p4 = Vecteur2D(x4, y4); // Bas-Gauche

            this->color = color;
            id = auto_id++;
        }

        /** @inheritdoc */
        void dessiner(Visiteur* v) const override;

        /** @inheritdoc */
        explicit operator std::string() const override;

        /** @inheritdoc */
        double calculerAire() const override;

        /** @inheritdoc */
        void sauvegarder(VisiteurSauvegarde* v) const override;

        /** @name Transformations Géométriques
         * @{ */

        /** @inheritdoc */
        void translation(const Vecteur2D& v) override {
            p1 = p1 + v; p2 = p2 + v; p3 = p3 + v; p4 = p4 + v;
        }

        /** @inheritdoc */
        void homothetie(double rapport, const Vecteur2D& centre) override {
            p1 = centre + (p1 - centre) * rapport;
            p2 = centre + (p2 - centre) * rapport;
            p3 = centre + (p3 - centre) * rapport;
            p4 = centre + (p4 - centre) * rapport;
        }

        /**
         * @inheritdoc
         * @details Applique une rotation aux 4 sommets via une matrice de rotation.
         */
        void rotation(double angle, const Vecteur2D& centre) override {
            const Matrice22 mat = Matrice22::creeRotation(angle);
            p1 = (mat * (p1 - centre)) + centre;
            p2 = (mat * (p2 - centre)) + centre;
            p3 = (mat * (p3 - centre)) + centre;
            p4 = (mat * (p4 - centre)) + centre;
        }
        /** @} */

        /** @name Calcul des limites (Bounding Box)
      * Ces méthodes parcourent toutes les formes pour déterminer l'enveloppe globale du groupe.
      * @{ */
        /** @inheritdoc */
        double getMaxY() const override { return std::max({p1.getY(), p2.getY(), p3.getY(), p4.getY()}); }
        /** @inheritdoc */
        double getMaxX() const override { return std::max({p1.getX(), p2.getX(), p3.getX(), p4.getX()}); }
        /** @inheritdoc */
        double getMinY() const override { return std::min({p1.getY(), p2.getY(), p3.getY(), p4.getY()}); }
        /** @inheritdoc */
        double getMinX() const override { return std::min({p1.getX(), p2.getX(), p3.getX(), p4.getX()}); }
        /** @} */

        /** @inheritdoc */
        void preparerPixel(Plan &plan) override;

        /** @inheritdoc */
        virtual std::string tranformerCoordonnees() const override;
    };
}

#endif //RECTANGLE_H