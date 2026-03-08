//
// Created by sanes on 08/03/2026.
//

#ifndef VISITEURSAUVEGARDETEXTE_H
#define VISITEURSAUVEGARDETEXTE_H
#include "VisiteurSauvegarde.h"


class VisiteurSauvegardeTexte : public VisiteurSauvegarde {

  using VisiteurSauvegarde::VisiteurSauvegarde;

    virtual void visite(const Groupe* groupe);
    virtual void visite(const Polygone* polygone);
    virtual void visite(const Formes::Rectangle* rectangle);
    virtual void visite(const Rond* rond);
    virtual void visite(const Segment* segment);
    virtual void visite(const Triangle * triangle);


};



#endif //VISITEURSAUVEGARDETEXTE_H
