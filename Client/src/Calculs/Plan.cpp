//
// Created by sanes on 05/03/2026.
//

#include "Plan.h"

#include <algorithm>

void Plan::calculerMatrice(){
    double lambda1 = hPixel / hMonde;
    double lambda2 = lPixel / lMonde;

    lambda = std::min(lambda1, lambda2);


    matrice = Matrice22(lambda,0,0,lambda*-1);
  }

Vecteur2D Plan::getOmega() const {
    Vecteur2D omega = Vecteur2D(getLPixel()/2,getHPixel()/2) -
        (matrice*Vecteur2D(getLMonde()/2,getHMonde()/2));
    return omega;
}


