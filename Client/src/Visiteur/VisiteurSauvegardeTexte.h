//
// Created by sanes on 08/03/2026.
//

#ifndef VISITEURSAUVEGARDETEXTE_H
#define VISITEURSAUVEGARDETEXTE_H
#include <fstream>

#include "VisiteurSauvegarde.h"


class VisiteurSauvegardeTexte : public VisiteurSauvegarde {
    std::ofstream* texte;
public:
  using VisiteurSauvegarde::VisiteurSauvegarde;

        void sauvegarder(const Forme* forme);
        void visite(const Groupe* groupe) override;
        void visite(const Polygone* polygone)override;
        void visite(const Formes::Rectangle* rectangle)override;
        void visite(const Rond* rond)override;
        void visite(const Segment* segment)override;
        void visite(const Triangle * triangle)override;


};



#endif //VISITEURSAUVEGARDETEXTE_H
