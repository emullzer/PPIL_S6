//
// Created by sanes on 05/03/2026.
//

#include "FormesManager.h"
#include "../Visiteur/VisiteurDessinJava.h"


void FormesManager::ajouterForme(Forme *forme) {
    VectorFormes.push_back(forme);
    if(!rectangleHG.has_value()) {
        rectangleHG = Vecteur2D(forme->getMinX(),forme->getMaxY());
        rectangleBD = Vecteur2D(forme->getMaxX(),forme->getMinY());
    }else {
        updateBordsFormes(forme);
    }
        updatePlan();

        nettoyer();
        dessinerFormes();

}

void FormesManager::updateBordsFormes(Forme* forme) {
    double minX = std::min(forme->getMinX(),rectangleHG->getX());
    double minY = std::min(forme->getMinY(),rectangleBD->getY());
    double maxX = std::max(forme->getMaxX(),rectangleBD->getX());
    double maxY = std::max(forme->getMaxY(),rectangleHG->getY());


    rectangleHG = Vecteur2D(minX,maxY);
    rectangleBD = Vecteur2D(maxX,minY);
}

void FormesManager::updateBordsFormes(){
    if (VectorFormes.empty()) return;
    //On initialise les coins du rectangle avec les valeurs du premier element
    double minX = VectorFormes[0]->getMinX();
    double minY = VectorFormes[0]->getMinY();
    double maxX = VectorFormes[0]->getMaxX();
    double maxY = VectorFormes[0]->getMaxY();
    rectangleHG = Vecteur2D(minX,maxY);
    rectangleBD = Vecteur2D(maxX,minY);

    //Puis on appelle la fonction qui compare la forme avec RectangleHG/BD
    for (auto forme : VectorFormes) {
        updateBordsFormes(forme);
    }
}

void FormesManager::dessinerFormes() {

    auto* visiteur = new VisiteurDessinJava();
    for(auto forme : VectorFormes) {
        forme->preparerPixel(plan);
        forme->dessiner(visiteur);
    }
}

void FormesManager::updateFormes() {
    updateBordsFormes();
    updatePlan();

    nettoyer();
    dessinerFormes();
}

void FormesManager::updatePlan() {
    plan.updateMatrice(rectangleBD.value(),rectangleHG.value());

    plan.setLMonde((rectangleBD->getX()-rectangleHG->getX()));
    plan.setHMonde((rectangleHG->getY()-rectangleBD->getY()));
    plan.calculerMatrice();
}




