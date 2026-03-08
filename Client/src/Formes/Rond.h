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

    void dessiner(Visiteur* v) const override;
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

    void translation(const Vecteur2D& v) override {
        // On déplace le point central du rond
        this->position = this->position + v;
    }

    void homothetie(double rapport, const Vecteur2D& centre) override {
        // 1. On déplace le centre par rapport au point pivot
        this->position = centre + (this->position - centre) * rapport;

        // 2. On multiplie le rayon par le rapport (en valeur absolue pour éviter un rayon négatif)
        this->rayon = this->rayon * std::abs(rapport);
    }

    void rotation(double angle, const Vecteur2D& pointPivot) override {
        // On crée la matrice de rotation
        Matrice22 mat = Matrice22::creeRotation(angle);

        // On calcule la nouvelle position du centre (Pivot -> Origine -> Rotation -> Pivot)
        this->position = pointPivot + mat * (this->position - pointPivot);
    }

};



#endif //ROND_H
