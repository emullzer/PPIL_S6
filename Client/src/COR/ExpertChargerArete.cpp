//
// Created by sanes on 08/03/2026.
//

#include "ExpertChargerArete.h"

Forme* ExpertChargerArete::charger2(const std::string& ligne) const {
    //Regex qui capture 4 coordonnées, puis un mot, ici la couleur de l'arete
    std::istringstream i(ligne);
    int nbCar;
    std::string color;

    //on verifie que le texte commence bien par 1 entier
    if (!(i >> nbCar)) return nullptr;

    //on stocke les points du segment dans un Vector et le char carInutile nous sert lors du traitement de chacune des coordonnées, il y a des caracteres tel que '(',')' ou ',' qu'on utilise pas mais qui les séparent
    std::vector<Vecteur2D> points;
    char carInutile;

    // on boucle tant que le nombre de points dans le vector n'est pas égal a celui déclaré en debut de ligne et que l'istringstream possede encore des données
    for (int j = 0; j<2;j++){
        double x,y;
        //format : ( x, y)
        if (i >> carInutile >> x >> carInutile >> y >> carInutile) {
            points.push_back(Vecteur2D(x, y));
        }
    }

    //si il y a eu le bon nombre de poijnts annoncés, alors c'est le bon format
    if (points.size() == (size_t)2) {
        //on regarde si une couleur a été définie, sinon on applique la couleur noire
        if (i >> color) return new Segment(points[0].getX(),points[0].getY(),points[1].getX(),points[1].getY(),color);
        else return new Segment(points[0].getX(),points[0].getY(),points[1].getX(),points[1].getY(),"black");
    }

    //si le nombre de points est pas bon, alors ce n'etait pas le bon formatage, on retourne donc nullptr
    return nullptr;
}