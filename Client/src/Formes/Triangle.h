//
// Created by sanes on 19/02/2026.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Forme.h"
#include "Vecteur2D.h"

class Triangle: public Forme{
    Vecteur2D sommet1, sommet2, sommet3;

    public:
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3,const std::string& color)
    {
        sommet1 = Vecteur2D(x1, y1);
        sommet2 = Vecteur2D(x2, y2);
        sommet3 = Vecteur2D(x3, y3);
        this->color = color;
    }

    void dessiner() const override;
    explicit operator std::string() const override;

};



#endif //TRIANGLE_H
