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
        plan.setHMonde((rectangleBD->getX()-rectangleHG->getX()));
        plan.setLMonde((rectangleHG->getY()-rectangleBD->getY()));
        plan.calculerMatrice();
        dessinerFormes();
    }
}

void FormesManager::updateBordsFormes(Forme* forme) {
    double minX = std::min(forme->getMinX(),rectangleHG->getX())*0.95;
    double minY = std::min(forme->getMinY(),rectangleBD->getY())*0.95;
    double maxX = std::min(forme->getMaxX(),rectangleBD->getX())*1.05;
    double maxY = std::min(forme->getMaxY(),rectangleHG->getY())*1.05;


    rectangleHG = Vecteur2D(minX,maxY);
    rectangleBD = Vecteur2D(maxX,minY);
}

void FormesManager::dessinerFormes() {
    for(auto forme : VectorFormes) {
        forme->preparerPixel(plan);
        forme->dessiner();
    }
}


