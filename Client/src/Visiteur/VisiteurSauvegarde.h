//
// Created by sanes on 06/03/2026.
//

#ifndef VISITEURSAUVEGARDE_H
#define VISITEURSAUVEGARDE_H
#include "Visiteur.h"

class Forme;

class VisiteurSauvegarde : public Visiteur {
protected:
    std::string nomFichier;

public:
    explicit VisiteurSauvegarde(const std::string& chemin) : nomFichier(chemin) {}
    VisiteurSauvegarde(){nomFichier = "Sauvegarde.txt";}
    virtual void sauvegarder(const Forme* f) = 0;

};



#endif //VISITEURSAUVEGARDE_H
