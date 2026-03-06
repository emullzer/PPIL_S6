//
// Created by mulle1149u on 07/02/2026.
//

#ifndef ROND_H
#define ROND_H
#include "Forme.h"
#include <iostream>

#include "../Calculs/Vecteur2D.h"


class Rond: public Forme {
    double rayon;
    double rayonPixel;
    Vecteur2D position;
    Vecteur2D positionPixel;

    public:
    Rond(double x, double y, double r,const std::string& color) {
        position = Vecteur2D(x,y);
        this->rayon = r;
        this->color = color;
        id = auto_id++;
    }

    void dessiner() const override;
    explicit operator std::string() const override;
    double calculerAire() const override;

    double getMaxY() const override {
        return position.getY()+rayon;
    }
    double getMaxX() const override{
        return position.getX()+rayon;
    }
    double getMinY() const override {
        return position.getY()-rayon;
    }
    double getMinX() const override {
        return position.getX()-rayon;
    }

    void preparerPixel(Plan &plan) override;

};



#endif //ROND_H
