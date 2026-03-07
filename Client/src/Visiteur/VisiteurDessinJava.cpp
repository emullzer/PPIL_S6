//
// Created by sanes on 07/03/2026.
//

#include "VisiteurDessinJava.h"
#include "../Connexion/ConnexionServeur.h"
#include "../Formes/Groupe.h"
#include "../Formes/Polygone.h"
#include "../Formes/Rectangle.h"
#include "../Formes/Rond.h"
#include "../Formes/Segment.h"
#include "../Formes/Triangle.h"

void VisiteurDessinJava::visite(const Groupe* groupe) {
  std::string message = groupe->operator std::string()+"\n";
  ConnexionServeur::getInstance().envoyerRequete(message);
  }
void VisiteurDessinJava::visite(const Polygone* polygone) {
  std::string message = polygone->operator std::string()+"\n";
  ConnexionServeur::getInstance().envoyerRequete(message);
}
void VisiteurDessinJava::visite(const Formes::Rectangle* rectangle) {
  std::string message = rectangle->operator std::string()+"\n";
  ConnexionServeur::getInstance().envoyerRequete(message);
}
void VisiteurDessinJava::visite(const Rond* rond) {
  std::string message = rond->operator std::string()+"\n";
  ConnexionServeur::getInstance().envoyerRequete(message);
}
void VisiteurDessinJava::visite(const Segment* segment) {
  std::string message = segment->operator std::string()+"\n";
  ConnexionServeur::getInstance().envoyerRequete(message);
}
void VisiteurDessinJava::visite(const Triangle * triangle) {
  std::string message = triangle->operator std::string()+"\n";
  ConnexionServeur::getInstance().envoyerRequete(message);
}