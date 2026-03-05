//
// Created by mulle1149u on 05/03/2026.
//

#ifndef POLYGONE_H
#define POLYGONE_H
#include <iostream>
#include <vector>

#include "Forme.h"
#include "Vecteur2D.h"


class Polygone : public Forme {
    protected:
        std::vector<Vecteur2D> points;
    public:
        explicit Polygone(const std::string& color) {
            points.clear();
            this->color = color;
        }
        Polygone(const std::string& color, const std::vector<Vecteur2D>& points) {
            this->color = color;
            if(points.size() < 3) {
                throw std::invalid_argument("Pas assez de points pour faire un Polygone");
            }
            this->points = points;
        }
        void ajouterPoint(const Vecteur2D& point) {
            this->points.push_back(point);
        }

    explicit operator std::string() const override;
    void dessiner() const override;
    double calculerAire() const override;

};



#endif //POLYGONE_H
