//
// Created by sanes on 06/03/2026.
//

#ifndef VISITEURDESSIN_H
#define VISITEURDESSIN_H

namespace Formes {
  class Rectangle;
}

class Groupe;
class Segment;
class Rond;
class Triangle;
class Polygone;



class Visiteur {
public:
  virtual void visite(const Groupe* groupe) = 0;
  virtual void visite(const Polygone* polygone) = 0;
  virtual void visite(const Formes::Rectangle* rectangle) = 0;
  virtual void visite(const Rond* rond) = 0;
  virtual void visite(const Segment* segment) = 0;
  virtual void visite(const Triangle * triangle) = 0;
};



#endif //VISITEURDESSIN_H
