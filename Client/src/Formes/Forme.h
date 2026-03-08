//
// Created by mulle1149u on 07/02/2026.
//

#ifndef FORME_H
#define FORME_H
#include <iostream>
#include <string>
#include "../Calculs/Plan.h"
#include "../Visiteur/VisiteurSauvegarde.h"

class Visiteur;
class VisiteurSauvegarde;


class Forme {
protected:
    std::string color;
    int id;
    static int auto_id; // sert a définir automatiquement l'id d'une forme
public:
    virtual ~Forme() = default;

    virtual void dessiner(Visiteur* v) const = 0;
    virtual explicit operator std::string() const =0;
    virtual double calculerAire() const = 0;

    //Fonction utilisée par Groupe qui permet de changer la couleur d'une forme
    void setCouleur(std::string couleur) {
        color = couleur;
    }
    std::string getCouleur(){return this->color;}

    virtual double getMinX()const = 0;
    virtual double getMinY()const = 0;
    virtual double getMaxX()const = 0;
    virtual double getMaxY()const = 0; //TODO implementer dans toutes les formes, en fonction de leur taille

    virtual void preparerPixel(Plan &plan) = 0;

    virtual void rotation(double angle, const Vecteur2D& centre) = 0;
    virtual void translation(const Vecteur2D& v) = 0;
    virtual void homothetie(double rapport, const Vecteur2D& centre) = 0;

    virtual void sauvegarder(VisiteurSauvegarde* v) const = 0;
};



#endif //FORME_H
