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
        Vecteur2D tranformerPixels(Vecteur2D point);

};



#endif //PLAN_H
