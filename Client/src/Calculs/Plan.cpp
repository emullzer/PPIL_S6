//
// Created by sanes on 05/03/2026.
//

#include "Plan.h"

#include <algorithm>

void Plan::calculerMatrice(){
    double lambda1 = hPixel / hMonde;
    double lambda2 = lPixel / lMonde;

    double marge = 1.2;

    lambda = std::min(lambda1, lambda2)/marge;


    matrice = Matrice22(lambda,0,0,lambda*-1);

    std::cout << matrice << std::endl;
  }


Vecteur2D Plan::getOmega() {
    Vecteur2D omega = Vecteur2D(getLPixel()/2,getHPixel()/2 - 15) - // -15 effectué pour enlever la taille de la barre de titre de la page
        (getMatrice() *Vecteur2D((rectangleHG.getX()+rectangleBD.getX())/2,(rectangleHG.getY()+rectangleBD.getY())/2));
    return omega;
}



