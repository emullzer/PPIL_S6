//
// Created by sanes on 05/03/2026.
//

#ifndef PLAN_H
#define PLAN_H
#include "Vecteur2D.h"
#include "Matrice22.h"

class Plan {
    static Plan* instance;

    Vecteur2D origine; // egal a minX, min Y
    double hMonde, lMonde; // longeur = maxX - minX et pareil pour hauteur
    int hPixel=600, lPixel=800;
    double lambda =1;

    Matrice22 matrice= Matrice22(0,0,0,0);

    public:

      Plan(const Vecteur2D& origine, const double &hMonde, const double& lMonde): origine(origine), hMonde(hMonde),
                lMonde(lMonde) {
                calculerMatrice();
            }

      void calculerMatrice();

        void setHMonde(const double &hMonde) {
            this->hMonde = hMonde;
        }
        void setLMonde(const double &lMonde) {
            this->lMonde = lMonde;
        }
        Matrice22 getMatrice() {
            return matrice;
        }
    double getLambda() const {
            return lambda;
        }

    [[nodiscard]] double getHMonde() const {
        return hMonde;
    }

    [[nodiscard]] double getLMonde() const {
        return lMonde;
    }

    [[nodiscard]] int getHPixel() const {
        return hPixel;
    }

    [[nodiscard]] int getLPixel() const {
        return lPixel;
    }
};



#endif //PLAN_H
