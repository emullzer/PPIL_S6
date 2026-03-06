//
// Created by sanes on 05/03/2026.
//

#include "FormesManager.h"


void FormesManager::ajouterForme(Forme *forme) {
    VectorFormes.push_back(forme);
    if(!rectangleHG.has_value()) {
        rectangleHG = Vecteur2D(forme->getMinX(),forme->getMaxY());
        rectangleBD = Vecteur2D(forme->getMaxX(),forme->getMinY());
    }else {
        updateBordsFormes(forme);
    }
        plan.updateMatrice(rectangleBD.value(),rectangleHG.value());

        plan.setHMonde((rectangleBD->getX()-rectangleHG->getX()));
        plan.setLMonde((rectangleHG->getY()-rectangleBD->getY()));
        plan.calculerMatrice();
        //nettoyer();
        dessinerFormes();

}

void FormesManager::updateBordsFormes(Forme* forme) {
    double minX = std::min(forme->getMinX(),rectangleHG->getX());
    double minY = std::min(forme->getMinY(),rectangleBD->getY());
    double maxX = std::min(forme->getMaxX(),rectangleBD->getX());
    double maxY = std::min(forme->getMaxY(),rectangleHG->getY());


    rectangleHG = Vecteur2D(minX,maxY);
    rectangleBD = Vecteur2D(maxX,minY);
}

void FormesManager::dessinerFormes() {
    for(auto forme : VectorFormes) {
        forme->preparerPixel(plan);
        forme->dessiner();
    }
}


