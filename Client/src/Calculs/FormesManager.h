//
// Created by sanes on 05/03/2026.
//

#ifndef FORMESMANAGER_H
#define FORMESMANAGER_H
#include "Plan.h"
#include <iostream>
#include <vector>
#include "../Formes/Forme.h"
#include "Vecteur2D.h"

class FormesManager {
    Plan plan;
    std::vector<Forme*> VectorFormes;
    public:
        FormesManager():plan(Vecteur2D(0,0),10,10),VectorFormes() {}

        void ajouterForme(Forme *forme);
    //TODO: Creer une Classe qui stocke les formes, a achaque ajout supprime les formes et les renvoie avec la bonne taille
    //TODO à implementer : Calucler le rectangle qui entoure les formes
    //TODO: mettre dans les formes les fonction getxmax, getymax,getxmin,getymin pour ensuite les utiliser pour la bounding box.

};



#endif //FORMESMANAGER_H
