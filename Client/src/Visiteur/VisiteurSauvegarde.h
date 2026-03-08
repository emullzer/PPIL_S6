//
// Created by sanes on 06/03/2026.
//

#ifndef VISITEURSAUVEGARDE_H
#define VISITEURSAUVEGARDE_H
#include "Visiteur.h"

namespace Formes {
    class Rectangle;
}

class Groupe;
class Segment;
class Rond;
class Triangle;
class Polygone;

class VisiteurSauvegarde : public Visiteur {
    virtual void visite(const Groupe* groupe);
    virtual void visite(const Polygone* polygone);
    virtual void visite(const Formes::Rectangle* rectangle);
    virtual void visite(const Rond* rond);
    virtual void visite(const Segment* segment);
    virtual void visite(const Triangle * triangle);

};



#endif //VISITEURSAUVEGARDE_H
