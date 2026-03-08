//
// Created by sanes on 06/03/2026.
//

#ifndef VISITEURSAUVEGARDE_H
#define VISITEURSAUVEGARDE_H
#include "Visiteur.h"

class Forme;

class VisiteurSauvegarde : public Visiteur {
protected:
    std::string cheminFichier;

public:
    explicit VisiteurSauvegarde(const std::string& chemin) : cheminFichier(chemin) {}
    VisiteurSauvegarde(){cheminFichier = "../FormesSauv/formesSauvegarde.txt";}

};



#endif //VISITEURSAUVEGARDE_H
