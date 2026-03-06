//
// Created by sanes on 05/03/2026.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "../Calculs/Vecteur2D.h"
#include "Forme.h"


class Rectangle: public Forme {

    Vecteur2D pointHautGauche;
    Vecteur2D pointHautGauchePixel;
    Vecteur2D pointBasDroit;
    Vecteur2D pointBasDroitPixel;

public:
    Rectangle(double x1, double y1,double x2, double y2, const std::string& color) {
        pointHautGauche = Vecteur2D(x1,y1);
        pointBasDroit = Vecteur2D(x2,y2);
        this->color = color;
        id = auto_id++;
    }

    void dessiner() const override;
    explicit operator std::string() const override;
    double calculerAire() const override;

    double getMaxY() const override {
        return pointHautGauche.getY();
    }
    double getMaxX() const override{
        return pointBasDroit.getX();
    }
    double getMinY() const override {
        return pointBasDroit.getY();
    }
    double getMinX() const override {
        return pointHautGauche.getX();
    }

    void preparerPixel(const Plan &plan) const override;
};



#endif //RECTANGLE_H
