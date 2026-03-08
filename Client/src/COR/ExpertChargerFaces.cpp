//
// Created by sanes on 08/03/2026.
//

#include "ExpertChargerFaces.h"
#include "../Formes/Polygone.h"


Forme* ExpertChargerFaces::charger2(const std::string& ligne) const {
    //pour traiter la ligne on utilise un istringstream, qui est un flux d'entrée contrairement a ostringstream
    std::istringstream i(ligne);
    int nbCar,nbPoints;
    std::string color;

    //on verifie que le texte commence bien par 2 entiers
    if (!(i >> nbCar >> nbPoints)) return nullptr;

    //on stocke les points du polygone dans un Vector et le char carInutile nous sert lors du traitement de chacune des coordonnées, il y a des caracteres tel que '(',')' ou ',' qu'on utilise pas mais qui les séparent
    std::vector<Vecteur2D> points;
    char carInutile;

    // on boucle tant que le nombre de points dans le vector n'est pas égal a celui déclaré en debut de ligne et que l'istringstream possede encore des données
    while (points.size() < (size_t)nbPoints && i.good() ) {
        double x,y;
        //format : ( x, y)
        if (i >> carInutile >> x >> carInutile >> y >> carInutile) {
            points.push_back(Vecteur2D(x, y));
        }
    }

    //si il y a eu le bon nombre de poijnts annoncés, alors c'est le bon format
    if (points.size() == (size_t)nbPoints) {
        //on regarde si une couleur a été définie, sinon on applique la couleur noire
        if (i >> color) return new Polygone(color, points);
        else return new Polygone("black", points);
    }

    //si le nombre de points est pas bon, alors ce n'etait pas le bon formatage, on retourne donc nullptr
    return nullptr;


}