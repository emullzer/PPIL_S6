//
// Created by sanes on 05/03/2026.
//

#include "Plan.h"

#include <algorithm>

void Plan::calculerMatrice(){
    double lambda1 = hPixel / hMonde;
    double lambda2 = lPixel / lMonde;

    double lambda = std::min(lambda1, lambda2);


    matrice = Matrice22(lambda,0,0,lambda*-1);
  }
