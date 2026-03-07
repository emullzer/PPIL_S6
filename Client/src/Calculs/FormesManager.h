//
// Created by sanes on 05/03/2026.
//

#ifndef FORMESMANAGER_H
#define FORMESMANAGER_H
#include "Plan.h"
#include <iostream>
#include <optional>
#include <vector>
#include "../Formes/Forme.h"
#include "Vecteur2D.h"
#include "../Connexion/ConnexionServeur.h"

class FormesManager {
    Plan plan;
    std::vector<Forme*> VectorFormes;
    std::optional<Vecteur2D> rectangleHG, rectangleBD;


    void dessinerFormes();

    /**
     * Fonction qui mets à jour les deux Vecteur2D rectangleHG et rectangleBD, qui permet de trouver le rectangle encadrant les formes, pour permettre d'afficher les formes en plus grand sur le serveur.
     */
    void updateBordsFormes(Forme* forme);

    /**
     * Fonction qui cherche parmis toutes les formes les valeurs minimales et maximales pour RectangleHG/RectangleBD
     */
    void updateBordsFormes();
    void updatePlan();


    public:
        FormesManager():plan(Vecteur2D(-5,-5),10,10),VectorFormes() {}

        void ajouterForme(Forme *forme);

        void nettoyer()
        {
            ConnexionServeur::getInstance().envoyerRequete("Nettoyer[]\n");
        }

        void updateFormes();

};



#endif //FORMESMANAGER_H
