//
// Created by sanes on 05/03/2026.
//

#include "FormesManager.h"
#include "../Visiteur/VisiteurDessinJava.h"
#include <fstream>
#include "../COR/ExpertCharger.h"
#include "../COR/ExpertChargerArete.h"
#include "../COR/ExpertChargerFaces.h"
#include <thread>
#include <chrono>

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

void FormesManager::ajouterVectorForme(std::vector<Forme *> formes) {
    for(Forme *forme : formes) {
        VectorFormes.push_back(forme);
    }
    updateFormes();
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

bool FormesManager::chargerFormes(const std::string& nomFichier) {
    //on utilise un ifstream pour Uniquement Lire le fichier
    std::ifstream fichier(nomFichier);

    if (!fichier.is_open()) {
        return false;
    }

    std::string ligne;
    std::vector<Forme*> formes;
    setupCOR();

    int cpt = 0;

    while (std::getline(fichier, ligne)) {
        Forme* forme = expertCharger->charger(ligne);
        if (forme != nullptr) {
            formes.push_back(forme);
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
            std::cout<<cpt++;
        }
    }
    ajouterVectorForme(formes);
    return true;
}

void FormesManager::setupCOR() {

    if (expertCharger == nullptr) {
        ExpertCharger* maillon3 = nullptr; // Expert final (ex: ExpertParDefaut)
        ExpertCharger* maillon2 = new ExpertChargerFaces(maillon3);
        ExpertCharger* maillon1 = new ExpertChargerArete(maillon2);

        expertCharger = maillon1;
    }
}




