#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "../Calculs/Vecteur2D.h"
#include "Forme.h"
#include <algorithm>

namespace Formes {
    class Rectangle : public Forme {
        // On stocke les 4 coins du rectangle
        Vecteur2D p1, p2, p3, p4;
        Vecteur2D p1Pixel, p2Pixel, p3Pixel, p4Pixel;

    public:
        Rectangle(double x1, double y1, double x2, double y2, const std::string& color) {

            p1 = Vecteur2D(x1, y1); // Haut-Gauche
            p2 = Vecteur2D(x2, y1); // Haut-Droit
            p3 = Vecteur2D(x2, y2); // Bas-Droit
            p4 = Vecteur2D(x1, y2); // Bas-Gauche
            
            this->color = color;
            id = auto_id++;
        }

        void dessiner(Visiteur* v) const override;
        explicit operator std::string() const override;
        double calculerAire() const override;


        void translation(const Vecteur2D& v) override {
            p1 = p1 + v; p2 = p2 + v; p3 = p3 + v; p4 = p4 + v;
        }

        void homothetie(double rapport, const Vecteur2D& centre) override {
            p1 = centre + (p1 - centre) * rapport;
            p2 = centre + (p2 - centre) * rapport;
            p3 = centre + (p3 - centre) * rapport;
            p4 = centre + (p4 - centre) * rapport;
        }

        void rotation(double angle, const Vecteur2D& centre) override {
            const Matrice22 mat = Matrice22::creeRotation(angle);
            //on soustrait
            p1 = (mat * (p1 - centre)) + centre;
            p2 = (mat * (p2 - centre)) + centre;
            p3 = (mat * (p3 - centre)) + centre;
            p4 = (mat * (p4 - centre)) + centre;
        }

        double getMaxY() const override { return std::max({p1.getY(), p2.getY(), p3.getY(), p4.getY()}); }
        double getMaxX() const override { return std::max({p1.getX(), p2.getX(), p3.getX(), p4.getX()}); }
        double getMinY() const override { return std::min({p1.getY(), p2.getY(), p3.getY(), p4.getY()}); }
        double getMinX() const override { return std::min({p1.getX(), p2.getX(), p3.getX(), p4.getX()}); }

        void preparerPixel(Plan &plan) override ;
    };
}

#endif //RECTANGLE_H