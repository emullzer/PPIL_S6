//
// Created by sanes on 08/03/2026.
//

#include "ExpertChargerRond.h"
#include <vector>
#include "../Formes/Rond.h"


Forme* ExpertChargerRond::charger2(const std::string& ligne) const {
    //Regex qui capture 4 coordonnées, puis un mot, ici la couleur de l'arete
    std::istringstream i(ligne);
    int nbCar;
    std::string color;

    //on verifie que le texte commence bien par 1 entier
    if (!(i >> nbCar)) return nullptr;

    //on stocke les points du segment dans un Vector et le char carInutile nous sert lors du traitement de chacune des coordonnées, il y a des caracteres tel que '(',')' ou ',' qu'on utilise pas mais qui les séparent
    Vecteur2D point;
    char carInutile;

    double x,y;
        //format : ( x, y)
    if (i >> carInutile >> x >> carInutile >> y >> carInutile) {
        point = Vecteur2D(x,y);
    }
    std::string rayon;
    i >> rayon;
    if (rayon.at(0)== '(') return nullptr;

    if (i >> color) return new Rond(point.getX(),point.getY(),std::stod(rayon),color);
    else return new Rond(point.getX(),point.getY(),std::stod(rayon),"black");

}