//
// Created by sanes on 07/03/2026.
//

#ifndef SEGMENT_H
#define SEGMENT_H
#include "../Calculs/Vecteur2D.h"
#include "Forme.h"


class Segment: public Forme {
    protected:
        Vecteur2D A,B;
        Vecteur2D APixel,BPixel;


    public:
        Segment(const double& x,const double& y,const double& x2,double const& y2,const std::string& color) {
            A = Vecteur2D(x,y);
            B = Vecteur2D(x2,y2);
            this->color = color;
            id = auto_id++;
        }

        explicit operator std::string() const override;
        void dessiner() const override;
        double calculerAire() const override ;

        double getMaxY() const override {
             return std::max(A.y,B.y);
         }
         double getMaxX() const override{
            return std::max(A.x,B.x);
         }
         double getMinY() const override {
            return std::min(A.y,B.y);
         }
         double getMinX() const override {
            return std::min(A.x,B.x);
         }

         void preparerPixel(Plan &plan) override;

        void translation(const Vecteur2D& v) override {
            A = A + v;
            B = B + v;
        }

        void homothetie(double rapport, const Vecteur2D& centre) override {
            A = centre + (A - centre) * rapport;
            B = centre + (B - centre) * rapport;
        }

        void rotation(double angle, const Vecteur2D& centre) override {
            Matrice22 matRotation = Matrice22::creeRotation(angle);
            A = centre + matRotation * (A - centre);
            B = centre + matRotation * (B - centre);
        }



    };

#endif //SEGMENT_H
