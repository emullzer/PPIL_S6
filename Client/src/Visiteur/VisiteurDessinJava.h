//
// Created by sanes on 07/03/2026.
//

#ifndef VISITEURDESSINJAVA_H
#define VISITEURDESSINJAVA_H
#include "VisiteurDessin.h"


class VisiteurDessinJava: public VisiteurDessin {
  //on laisse en virtual dans le cas ou l'on pourrait déssiner le dessin Java avec plusieurs librairies differentes
    virtual void visite(const Groupe* groupe);
    virtual void visite(const Polygone* polygone);
    virtual void visite(const Formes::Rectangle* rectangle);
    virtual void visite(const Rond* rond);
    virtual void visite(const Segment* segment);
    virtual void visite(const Triangle * triangle);
};



#endif //VISITEURDESSINJAVA_H
