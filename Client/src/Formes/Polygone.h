//
// Created by mulle1149u on 05/03/2026.
//

#ifndef POLYGONE_H
#define POLYGONE_H
#include <iostream>
#include <vector>

#include "Forme.h"
#include "../Calculs/Vecteur2D.h"


class Polygone : public Forme {
    protected:
        std::vector<Vecteur2D> points;
        std::vector<Vecteur2D> pointsPixel;
    public:
        explicit Polygone(const std::string& color) {
            points.clear();
            this->color = color;
            id = auto_id++;
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

    double getMaxY() const override {
        double max = points[0].getY();
        for(auto point : points) {
            max = std::max(max, point.getY());
        }
        return max;
    }
    double getMaxX() const override{
        double max = points[0].getX();
        for(auto point : points) {
            max = std::max(max, point.getX());
        }
        return max;
    }
    double getMinY() const override {
        double min = points[0].getY();
        for(auto point : points) {
            min = std::min(min, point.getY());
        }
        return min;
    }
    double getMinX() const override {
        double min = points[0].getX();
        for(auto point : points) {
            min = std::min(min, point.getX());
        }
        return min;
    }

    void preparerPixel(Plan &plan) override;

    void translation(const Vecteur2D& v) override {
        for (auto& point : points) {
            point = point + v;
        }
    }

    void homothetie(double rapport, const Vecteur2D& centre) override {
        for (auto& point : points) {
            point = centre + (point - centre) * rapport;
        }
    }

    void rotation(double angle, const Vecteur2D& centre) override {
        Matrice22 matRotation = Matrice22::creeRotation(angle);
        for (auto& point : points) {
            point = centre + matRotation * (point - centre);
        }
    }

};



#endif //POLYGONE_H
