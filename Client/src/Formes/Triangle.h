//
// Created by sanes on 19/02/2026.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>

#include "Forme.h"
#include "../Calculs/Vecteur2D.h"

class Triangle: public Forme{
    Vecteur2D sommet1, sommet2, sommet3;
    Vecteur2D sommet1Pixel, sommet2Pixel, sommet3Pixel;

    public:
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3,const std::string& color)
    {
        sommet1 = Vecteur2D(x1, y1);
        sommet2 = Vecteur2D(x2, y2);
        sommet3 = Vecteur2D(x3, y3);
        this->color = color;
        id = auto_id++;
    }

    void dessiner() const override;
    explicit operator std::string() const override;
    double calculerAire() const override;

    double getMaxY() const override {
        return std::max(std::max(sommet1.getY(), sommet2.getY()),sommet3.getY());
    }
    double getMaxX() const override{
        return std::max(std::max(sommet1.getX(), sommet2.getX()),sommet3.getX());
    }
    double getMinY() const override {
        return std::min(std::min(sommet1.getY(), sommet2.getY()),sommet3.getY());
    }
    double getMinX() const override {
        return std::min(std::min(sommet1.getX(), sommet2.getX()),sommet3.getX());
    }

    void preparerPixel(Plan &plan) override;

};



#endif //TRIANGLE_H
