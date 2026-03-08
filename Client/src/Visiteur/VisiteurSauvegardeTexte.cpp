//
// Created by sanes on 08/03/2026.
//

#include "VisiteurSauvegardeTexte.h"
#include <fstream>
#include <filesystem>
#include <iostream>

#include "../Formes/Groupe.h"
#include "../Formes/Polygone.h"
#include "../Formes/Triangle.h"
#include "../Formes/Rond.h"
#include "../Formes/Rectangle.h"
#include "../Formes/Segment.h"

void VisiteurSauvegardeTexte::sauvegarder(const Forme *forme) {
    // Cree / vérifie que le dossier saves existe bien
    std::filesystem::create_directories("saves");
    std::ofstream fichier("saves/"+this->nomFichier);

    if (fichier.is_open()) {
        this->texte = &fichier;

        forme->sauvegarder(this);

        this->texte = nullptr;
        fichier.close();
    }
}


void VisiteurSauvegardeTexte::visite(const Groupe* groupe) {

    *texte << groupe->getNbFormes()<< std::endl;
    for (auto* forme : groupe->getFormes()) {
        forme->sauvegarder(this);
    }

}

void VisiteurSauvegardeTexte::visite(const Polygone* polygone) {
    std::string cd = polygone->tranformerCoordonnees();
    *texte << cd.size() << " " << cd ;
}

void VisiteurSauvegardeTexte::visite(const Formes::Rectangle* rectangle) {
    std::string cd = rectangle->tranformerCoordonnees();
    *texte << cd.size() << " " << cd ;
}

void VisiteurSauvegardeTexte::visite(const Rond* rond){
    std::string cd = rond->tranformerCoordonnees();
    *texte << cd.size() << " " << cd ;
}

void VisiteurSauvegardeTexte::visite(const Segment* segment) {
    std::string cd = segment->tranformerCoordonnees();
    *texte << cd.size() << " " << cd ;
}

void VisiteurSauvegardeTexte::visite(const Triangle * triangle) {
    std::string cd = triangle->tranformerCoordonnees();
    *texte << cd.size() << " " << cd ;
}