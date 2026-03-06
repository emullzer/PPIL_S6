//
// Created by mulle1149u on 07/02/2026.
//

#ifndef FORME_H
#define FORME_H
#include <iostream>
#include <string>
#include "../Calculs/Plan.h"


class Forme {
protected:
    std::string color;
    int id;
    static int auto_id; // sert a définir automatiquement l'id d'une forme
public:
    virtual ~Forme() = default;

    virtual void dessiner() const = 0;
    virtual explicit operator std::string() const =0;
    virtual double calculerAire() const = 0;

    virtual double getMinX()const = 0;
    virtual double getMinY()const = 0;
    virtual double getMaxX()const = 0;
    virtual double getMaxY()const = 0; //TODO implementer dans toutes les formes, en fonction de leur taille

    virtual void preparerPixel(const Plan& plan) const = 0;
};
int Forme::auto_id = 1;


#endif //FORME_H
